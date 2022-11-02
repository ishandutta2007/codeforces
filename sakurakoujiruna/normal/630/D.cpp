#include <iostream>
using namespace std;

typedef unsigned long long uintl;

int main()
{
	uintl n;
	cin >> n;
	cout << n * (n + 1) / 2 * 6 + 1 << '\n';
	return 0;
}