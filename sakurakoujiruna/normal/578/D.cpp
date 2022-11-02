#include <iostream>
using namespace std;

typedef long long intl;
const int N = 100011;
//const intl Mod = (intl)1e9 + 7;

intl dp[N][8];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	str = '\0' + str + '\0';

	for(char c = 'a'; c < 'a' + m; c ++)
	{
		int stat = 1;
		if(c == str[1])
			stat |= 2;
		if(c == str[1] || c == str[2])
			stat |= 4;
		dp[1][stat] ++;
	}

	for(int i = 2; i <= n; i ++)
		for(int j = 0; j < 8; j ++)
		{
			int old[3] = {i - 3 + (j & 1), i - 2 + ((j >> 1) & 1), i - 2 + ((j >> 2) & 1)};
			for(char c = 'a'; c < 'a' + m; c ++)
			{
				int now[3];
				if(c == str[i - 1])
					now[0] = old[0] + 1;
				else
					now[0] = old[1];
				if(c == str[i])
					now[1] = old[1] + 1;
				else
					now[1] = max(now[0], old[2]);
				if(c == str[i + 1])
					now[2] = old[2] + 1;
				else
					now[2] = now[1];

				now[0] -= i - 2;
				now[1] -= i - 1;
				now[2] -= i - 1;
				if((now[0] == 0 || now[0] == 1) &&
					(now[1] == 0 || now[1] == 1) &&
					(now[2] == 0 || now[2] == 1))
				{
					int stat = now[0] + (now[1] << 1) + (now[2] << 2);
					dp[i][stat] += dp[i - 1][j];
					//dp[i][stat] %= Mod;
				}
			}
		}
	intl ans = 0;
	for(int i = 0; i < 8; i ++)
		if(((i >> 1) & 1) == 0)
			ans += dp[n][i];
	//cout << ans % Mod << '\n';
	cout << ans << '\n';
	return 0;
}