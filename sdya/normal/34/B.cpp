#include <iostream>
#include <algorithm>

using namespace std;

int a[200];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i <= m; i ++)
		res += (a[i] <= 0 ? a[i] : 0);
	cout << - res << endl;
	return 0;
}