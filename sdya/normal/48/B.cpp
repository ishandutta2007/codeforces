#include <iostream>

using namespace std;

int n, m;
int a, b;
int c[100][100], s[100][100];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", &c[i][j]);
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + c[i][j];

	int res = 1000000;
	for (int i = 1; i <= n - a + 1; i ++)
		for (int j = 1; j <= m - b + 1; j ++)
			res = min(res, s[i + a - 1][j + b - 1] - s[i - 1][j + b - 1] - s[i + a - 1][j - 1] + s[i - 1][j - 1]);
	for (int i = 1; i <= n - b + 1; i ++)
		for (int j = 1; j <= m - a + 1; j ++)
			res = min(res, s[i + b - 1][j + a - 1] - s[i - 1][j + a - 1] - s[i + b - 1][j - 1] + s[i - 1][j - 1]);

	cout << res << endl;
	return 0;
}