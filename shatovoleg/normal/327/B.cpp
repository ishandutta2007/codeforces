#include <iostream>

using namespace std;

int main()
{
	bool *arr = new bool[1299710];
	for (int i = 0; i < 1299710; ++i)
		arr[i] = true;
	int a, cnt = 0;
	cin >> a;
	for (int i = 2; cnt < a; ++i)
	if (arr[i])
	{
		for (int j = 2 * i; j < 1299710; j += i)
			arr[j] = false;
		++cnt;
		cout << i << " ";
	}
	delete[] arr;
}