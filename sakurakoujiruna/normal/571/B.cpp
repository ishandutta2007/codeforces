#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300011;
const int M = 5011;

typedef long long intl;
int a[N];
intl dp[M][M];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	int m1 = n % k;
	int m2 = k - n % k;
	int l1 = n / k + 1;
	int l2 = n / k;
	a[0] = a[1];

	for(int i = 0; i < k; i ++)
		for(int j = 0; j <= m1 && j <= i; j ++)
		{
			int p = j * l1 + (i - j) * l2;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[p + 1] - a[p]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[p + 1] - a[p]);
		}

	cout << a[n] - a[1] - dp[k][m1] << '\n';
	return 0;
}