#include <iostream>
using namespace std;

typedef long long intl;
const int N = 201111;
const int Inf = 0x3f3f3f3f;

int a[N << 1];
int dp[N << 1];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int offset = Inf;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		offset = min(offset, a[i]);
	}
	for(int i = 1; i <= n; i ++)
		if(a[i] > offset)
			a[i] = a[i + n] = 1;
		else
			a[i] = 0;
	int final = 0;
	for(int i = 1; i <= 2 * n; i ++)
		if(a[i] == 1)
		{
			dp[i] = dp[i - 1] + 1;
			final = max(final, dp[i]);
		}
		else
			dp[i] = 0;
	cout << final + (intl)offset * n << '\n';
	return 0;
}