#include <iostream>
using namespace std;

const int N = 1011;
bool dp[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, mod;
	cin >> n >> mod;

	if(n <= mod)
	{
		for(int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			x %= mod;
			dp[i + 1][x] = true;
			for(int j = 0; j < mod; j ++)
				if(dp[i][j])
				{
					dp[i + 1][j] = true;
					dp[i + 1][(j + x) % mod] = true;
				}
		}
		if(dp[n][0])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else
		cout << "YES\n";
	return 0;
}