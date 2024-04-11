#include <iostream>
using namespace std;

const int N = 5011;
//typedef long long intl;
const int Mod = (int)1e9 + 7;

int lcp[N][N];
int dp[N][N];
int sum[N][N];

void update(int &a, int b)
{
	a += b;
	if(a >= Mod)
		a -= Mod;
}

bool check_less(int s0, int s1, int len, string &str)
{
	int t = lcp[s0][s1];
	if(t >= len)
		return false;
	return str[s0 + t] < str[s1 + t];
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string str;
	cin >> str;
	str = '\0' + str;
	for(int i = n; i >= 1; i --)
		for(int j = n; j >= 1; j --)
			if(str[i] == str[j])
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			else
				lcp[i][j] = 0;

	for(int i = 1; i <= n; i ++)
	{
		dp[i][i] = 1;
		for(int j = 1; j <= n; j ++)
			update(sum[i][j], sum[i][j - 1] + dp[i][j]);
		if(i != n && str[i + 1] != '0')
		{
			for(int len = 1; i + len <= n; len ++)
			{
				update(dp[i + len][len], sum[i][len - 1]);
				if(len <= i && check_less(i - len + 1, i + 1, len, str))
					update(dp[i + len][len], dp[i][len]);
			}
		}
	}
	cout << sum[n][n] << '\n';
	return 0;
}