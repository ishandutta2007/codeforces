#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	cout << max (n - (k - 2 * n), 0) << "\n";
	return 0;
}