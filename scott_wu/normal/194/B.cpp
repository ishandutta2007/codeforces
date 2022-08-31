#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		long long n;
		cin >> n;
		if (n % 4 == 3)
			cout << n + 1 << "\n";
		else if (n % 2 == 1)
			cout << 2 * n + 1 << "\n";
		else
			cout << 4 * n + 1 << "\n";
	}
	return 0;
}