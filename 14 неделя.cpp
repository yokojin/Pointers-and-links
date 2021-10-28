// 14 неделя.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void distriBution(int* SIZEa) {
	cout << "\tInput size Array: ";
	cin >> (*SIZEa);
	cout << endl;
}
int* test(int *&pA, int SIZEa) {
	*&pA = new int[SIZEa];
	return pA;
}
void inicializatioN(int* pA, int SIZEa) {
	cout << "Input 1st Array: " << endl;
	for (int M = 0; M < SIZEa; M++) {
		cin >> pA[M];
	}
}
void ShowArray(int *&x, int SIZE) {
	for (int i = 0; i < SIZE; i++) {	
		cout << *&x[i] << " ";		
	}
}
void finalArray1(int* newArray, int SIZE3) {
	for (int i = 0; i < SIZE3; i++) {
		for (int j =i+1; j < SIZE3; j++) { //счётчик 2го цикла увеличенный на счётчик 1 в том же массиве

			if (newArray[i]==newArray[j]) {			//если 1 счётчик равне  (1му+1) 
				for (int count2 = j; count2 < SIZE3-1; count2++) {  //то новый (счётчик равен 1му+1) и цикл до размера массива -1
					newArray[count2] = newArray[count2 + 1];
				}
				SIZE3 -= 1;
			}			
			if (newArray[i] == newArray[j]) {
				j--;
			}		
		}	
	}	
	for (int i = 0; i < SIZE3; i++) {
		cout << newArray[i] << " ";
	}	
}
void SizeArray(int *A, int *B, int SIZEa, int SIZEb) {   // в каждом массиве найти не повторяющиеся элементы и объеденить в один без повторений	
	int* newARRAy = new int[SIZEa+SIZEb];	
	int i = 0;
	for (int i=0; i < SIZEa + SIZEb; i++) {
		if (i < SIZEa) {
			newARRAy[i] = A[i];
		}
		else {
			newARRAy[i] = B[i-SIZEa];
		}		
	}
	int SIZEnew = SIZEa + SIZEb;
	for (int i = 0; i < SIZEnew; i++) {
		for (int j = i + 1; j < SIZEnew; j++) { //счётчик 2го цикла увеличенный на счётчик 1 в том же массиве

			if (newARRAy[i] == newARRAy[j]) {			//если 1 счётчик равен  (1му+1) 
				for (int count2 = j; count2 < SIZEnew - 1; count2++) {  //то новый (счётчик равен 1му+1) и цикл до размера массива -1
					newARRAy[count2] = newARRAy[count2 + 1];
				}
				SIZEnew -= 1;
			}
			if (newARRAy[i] == newARRAy[j]) {
				j--;
			}
		}
	}	
	for (int i = 0; i < SIZEnew; i++) {
		cout << newARRAy[i] << " ";
	}
	delete[]newARRAy;
} // два массива в одном без повторения цифр
int addElement(int*&pA, int &SIZEa) {
	cout << "Input element: ";
	int element = 0;
	cin >> element;
	int*newArray = new int[SIZEa + 1];
	for (int i = 0; i < SIZEa; i++) {
		newArray[i] = pA[i];
	}
	newArray[SIZEa] = element;
	SIZEa++;
	delete[]pA;
	pA = newArray;

	return *pA;

}
int addElementForIndex(int*&pA, int&SIZEa) {
	cout << "Input index Array: ";
	int indexElement = 0;
	cin >> indexElement;
	cout << "Input Element: ";
	int element=0;
	cin >> element;
	int* newArray = new int[SIZEa + 1];
	int j = 0;
	for (int i = 0; i < SIZEa; i++) {			
		if (i != indexElement) {
			newArray[j] = pA[i];
			j++;
		}
		else {				
			newArray[j] = element;
			newArray[++j] = pA[i];
			j++;
		}		
	}
	SIZEa++;
	delete[]pA;
	pA = newArray;	
	return *pA;
}
int deleteElement(int*& pA, int& SIZEa) {
	cout << "Input index Array for digit delete: ";
	int indexElement = 0;
	cin >> indexElement;	
	int* newArray = new int[SIZEa];
	int j = 0;
	for (int i = 0; i < SIZEa; i++) {
		if (i != indexElement) {			
			newArray[j] = pA[i];
			j++;
		}
		else {
			newArray[j] = pA[i-1];					
		}
	}
	SIZEa--;
	delete[]pA;
	pA = newArray;
	return*pA;
}
//Задание 2 :Написать функцию, которая получает указатель на динамический массив и его размер. 
//Функция должна удалить из массива все простые числа и вернуть
//указатель на новый динамический массив.
int* simpleDigit(int*&pA, int& SIZEa) {
	int* newArray = new int[SIZEa];
	int size2 = 0;
	int j = 0;
	for (int i = 0; i < SIZEa; i++) {
		int digit = pA[i];	
		if (digit%2!=0 && digit%digit == 0)
		{
				newArray[size2++] = digit;				
		}		
	}	
	SIZEa = size2;	
	delete[]pA;
	pA = newArray;
	
	return pA;
}

//Задание 3. Написать функцию, которая получает указатель
//на статический массив и его размер.Функция распределяет положительные, отрицательные и нулевые элементы
//в отдельные динамические массивы.
void dynamicArray(int *arr,   int size) {	
	int count1{ 0 }, count2{ 0 }, count3{ 0 };
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";		
		if (arr[i] > 0) {
			count1++;
		}
		else if (arr[i] < 0) {
			count2++;
		}
		else if (arr[i] == 0) {
			count3++;
		}		
	}	 
	cout << endl;
	int Asize = count1;
	int* a = new int[Asize];
	int Bsize = count2;
	int* b = new int[Bsize];
	int Csize = count3;
	int* c = new int[Csize];
	int j{ 0 }, z{ 0 }, y{ 0 };
	for (int i = 0; i < size; i++) {	
		if (arr[i] > 0) {
			a[j++] = arr[i];
		}
		else if (arr[i] < 0) {
			b[z++] = arr[i];
		}
		else if (arr[i] == 0) {
			c[y++] = arr[i];
		}
	}

	for (int i=0; i < Asize; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < Bsize; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < Csize; i++) {
		cout << c[i] << " ";
	}	
	delete[] a;
	delete[] b;
	delete[] c;
};
void clearMemory(int* A, int* B, int* newArray, int* newArray2) {
	delete[]newArray2;
	delete[]newArray;
	delete[]A;
	delete[]B;
}
int main()
{
	int SIZEa=0;
	int SIZEb=0;
	int*A = 0;
	int*B = 0;
	distriBution(&SIZEa); // вписываем размер массива
	test(A, SIZEa); //выделяем под него память
	inicializatioN(A, SIZEa); // инициализируем массив
	cout << endl;
	distriBution(&SIZEb);
	test(B, SIZEb);
	inicializatioN(B, SIZEb);
	cout << endl;
	ShowArray(A, SIZEa);
	cout << endl;
	ShowArray(B, SIZEb);

	int newpSIZE = SIZEa+SIZEb;
	
	cout << endl;

	 int* newArray = new int[SIZEa<SIZEb? SIZEa:SIZEb];
	 int* newArray2 = new int[newpSIZE];
	 int SIZE3 = 0;
	 int SIZE4 = 0;
	//Создание третьего массива минимального возможного размера, в который входят элементы первого 
	//массива котрых нет во втором массиве без повторения
	 bool preset = false;
	 bool preset2 = false;
	 for (int i = 0; i < SIZEa; i++) {			 
		 preset = false;
		 for (int j = 0; j < SIZEb; j++) {	

			 if (A[i] == B[j]) {

				 preset = true;
				 break;
			 }					
		 }
		 if (preset == false) {
			 newArray[SIZE3] = A[i];
			 SIZE3++;
		 }		
	 }	 	 
	 cout << "================================================================" << endl;
	 cout << "\tFirst mission: "; finalArray1(newArray, SIZE3);
	 cout << endl;
	 cout << "================================================================" << endl; 
	 cout << "\tSecond mission: "; SizeArray(A, B, SIZEa, SIZEb);
	 cout << endl;
	 cout << "================================================================" << endl;
	 cout << "Added element to end" << endl;
	  addElement(A, SIZEa);
	 ShowArray(A, SIZEa);
	 cout << endl;
	 cout << "================================================================" << endl;
	 addElementForIndex(A, SIZEa);
	 ShowArray(A, SIZEa);
	 cout << endl;
	 cout << "================================================================" << endl;
	 deleteElement(A, SIZEa);
	 ShowArray(A, SIZEa);
	 cout << endl;	 
	 cout << "================================================================" << endl;
	 simpleDigit(A, SIZEa);
	 ShowArray(A, SIZEa);

	// GeneralElement(V, SIZEb);
	 /*
	 for (int i = 0; i < SIZEa; i++) {
		 for (int j = i + 1; j < SIZEa; j++) { //счётчик 2го цикла увеличенный на счётчик 1 в том же массиве

			 if (Z[i] == Z[j]) {			//если 1 счётчик равне  (1му+1) 
				 for (int count2 = j; count2 < SIZEa - 1; count2++) {  //то новый (счётчик равен 1му+1) и цикл до размера массива -1
					 Z[count2] = Z[count2 + 1];
				 }
				 SIZEa -= 1;
			 }

			 if (Z[i] == Z[j]) {
				 j--;
			 }
		 }
	 }

	 for (int i = 0; i < SIZEa; i++) {
		 cout << Z[i] << " ";

	 }
	 */
	 cout << endl;
	
	const int newSIZE = 10;
	 int ARRAY3[newSIZE];	
	 for (int i = 0; i < newSIZE; i++) {

		 ARRAY3[i] = rand() % 41 - 20;
	 }
	 cout << endl;
	 cout << "================================================================" << endl;
	 int* pX = ARRAY3;
	 dynamicArray(pX, newSIZE);	
	 clearMemory(A, B, newArray, newArray2);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
