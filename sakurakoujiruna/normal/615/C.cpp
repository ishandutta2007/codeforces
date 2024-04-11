#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2211;

int lcp[N][N];
int dp[N];
int from[N][2];

void solve(string &s, string &t, int type)
{
	memset(lcp, 0, sizeof(lcp));
	for(int i = s.size() - 1; i >= 0; i --)
		for(int j = t.size() - 1; j >= 0; j --)
			if(s[i] == t[j])
			{
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
				if(lcp[i][j] > dp[j])
				{
					dp[j] = lcp[i][j];
					from[j][0] = i + 1;
					from[j][1] = i + dp[j];
					if(type == 1)
					{
						int sl = s.size();
						from[j][0] = sl - from[j][0] + 1;
						from[j][1] = sl - from[j][1] + 1;		
					}
				}
			}
	/*
	for(int i = 0; i < t.size(); i ++)
		cout << i << ' ' << from[i][0] << ' ' << from[i][1] << '\n';
		*/
}

int main()
{
	ios :: sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	solve(s, t, 0);
	reverse(s.begin(), s.end());
	solve(s, t, 1);
	int now = 0;
	vector <pair <int, int> > ans;
	while(now != t.size())
	{
		if(dp[now] == 0)
		{
			cout << -1 << '\n';
			return 0;
		}
		ans.push_back(make_pair(from[now][0], from[now][1]));
		now += dp[now];
	}
	cout << ans.size() << '\n';
	for(auto &p : ans)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}