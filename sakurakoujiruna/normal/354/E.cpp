#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 21;

vector <int> add[43];
void dfs(int cur, int sum, vector <int> &v)
{
	if(cur == 6)
	{
		add[sum] = v;
		return;
	}
	v.push_back(0);
	dfs(cur + 1, sum, v);
	v.pop_back();

	v.push_back(4);
	dfs(cur + 1, sum + 4, v);
	v.pop_back();

	v.push_back(7);
	dfs(cur + 1, sum + 7, v);
	v.pop_back();
}

bool dp[N][10];
int from[N][10];
int trans[N][10];

int a[N];

void print(vector <int> v)
{
	bool p = false;
	for(auto &x : v)
	{
		if(x != 0)
			p = true;
		if(p)
			cout << x;
	}
	if(!p)
		cout << 0;
}

int main()
{
	vector <int> v;
	dfs(0, 0, v);
	ios :: sync_with_stdio(false);
	int kase;
	
	cin >> kase;
	while(kase --)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		memset(a, 0, sizeof(a));
		for(int i = 0; i < s.size(); i ++)
			a[i] = s[i] - '0';

		memset(dp, 0, sizeof(dp));
		dp[0][0] = true;
		for(int i = 0; i < N - 1; i ++)
			for(int j = 0; j < 10; j ++)
				for(int k = 0; k <= 42; k ++)
					if(dp[i][j] && (j + k) % 10 == a[i] && add[k].size())
					{
						int t = (j + k) / 10;
						dp[i + 1][t] = true;
						trans[i + 1][t] = k;
						from[i + 1][t] = j;
					}
		if(dp[N - 1][0])
		{
			vector <int> ans[6];
			int t = 0;
			for(int i = N - 1; i > 0; i --)
			{
				//cout << trans[i][t] << '\n';
				for(int j = 0; j < 6; j ++)
					ans[j].push_back(add[trans[i][t]][j]);
				t = from[i][t];
			}
			for(int i = 0; i < 6; i ++)
			{
				print(ans[i]);
				cout << ' ';
			}
			cout << '\n';
		}
		else
			cout << -1 << '\n';
	}
	
	return 0;
}