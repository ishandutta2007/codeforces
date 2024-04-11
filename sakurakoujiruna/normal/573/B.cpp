#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100011;
const int Inf = 0x3f3f3f3f;

int h[N];
int dp[2][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> h[i];

	for(int t = 0; t < 2; t ++)
	{
		for(int i = 0; i < n; i ++)
		{
			if(i == 0)
				dp[t][i] = 1;
			else
				dp[t][i] = min(h[i], dp[t][i - 1] + 1);
		}
		reverse(h, h + n);
	}
	int ans = 0;
	for(int i = 0; i < n; i ++)
		ans = max(ans, min(dp[0][i], dp[1][n - i - 1]));
	cout << ans << '\n';
}