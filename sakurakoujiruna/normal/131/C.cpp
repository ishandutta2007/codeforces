#include <bits/stdc++.h>
using namespace std;

const int N = 61;
typedef long long ll;
ll com[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	com[0][0] = 1;
	for(int i = 1; i < N; i ++)
	{
		com[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
	}

	int n, m, t;
	cin >> n >> m >> t;
	ll ans = 0;
	for(int i = 4; i < t; i ++)
		ans += com[n][i] * com[m][t - i];
	cout << ans << '\n';
	return 0;
}