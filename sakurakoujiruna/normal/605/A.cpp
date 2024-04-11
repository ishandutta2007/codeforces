#include <iostream>
using namespace std;

const int N = 101111;
int a[N];
int pos[N];
int dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	int ans = n;
	for(int i = 1; i <= n; i ++)
	{
		int last = pos[a[i] - 1];
		if(last < i)
			dp[i] = dp[last] + 1;
		else
			dp[i] = 1;
		ans = min(ans, n - dp[i]);
	}
	cout << ans << '\n';
	return 0;
}