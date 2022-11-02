#include <iostream>

using namespace std;

int n, c;
int a[3000];

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	int res = c;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			res = max(res, (c / a[i]) * a[j] + c % a[i]);
	cout << res << endl;
	return 0;
}