#include <iostream>

using namespace std;

int a[200];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = m; i <= 100; i ++)
	{
		int res = 0;
		for (int j = 1; j <= n; j ++)
			res += a[j] / i;
		ans = max(ans, res * i);
	}
	cout << ans << endl;
	return 0;
}