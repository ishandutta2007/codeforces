#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n *= 2;
	for (int i = 1; i <= 200; i ++)
		if (i * (i - 1) == n)
		{
			cout << "YES" << endl;
			return 0;
		}

	cout << "NO" << endl;
	return 0;
}