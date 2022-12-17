#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
char c[maxn][maxn], tmp[maxn][maxn];
int r1[30], c1[30], r2[30], c2[30];
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T --)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < 26; i ++)
		{
			r1[i] = c1[i] = 1e9;
			r2[i] = c2[i] = 0;
		}
		int mx = -1;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				cin >> c[i][j];
				if(c[i][j] != '.')
				{
					int now = c[i][j] - 'a';
					r1[now] = min(r1[now], i);
					c1[now] = min(c1[now], j);
					r2[now] = max(r2[now], i);
					c2[now] = max(c2[now], j);
					mx = max(mx, now);
				}
			}
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				tmp[i][j] = '.';
		bool boom = 0;
		for(int i = 0; i <= mx; i ++)
		{
			if(r2[i] + c2[i] < 1)
			{
				r1[i] = r2[i] = r1[mx];
				c1[i] = c2[i] = c1[mx];
			}
			if(r1[i] != r2[i] && c1[i] != c2[i])
			{
				boom = 1;
				break;
			}
			if(r1[i] == r2[i])
			{
				for(int j = c1[i]; j <= c2[i]; j ++)
					tmp[r1[i]][j] = (char)(i + 'a');
			}
			else
			{
				for(int j = r1[i]; j <= r2[i]; j ++)
					tmp[j][c1[i]] = (char)(i + 'a');
			}
		}
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				if(tmp[i][j] != c[i][j])
					boom = 1;
		if(boom)
			cout << "NO" << '\n';
		else
		{
			cout << "YES" << '\n';
			cout << mx + 1 << '\n';
			for(int i = 0; i <= mx; i ++)
				cout << r1[i] << " " << c1[i] << " " << r2[i] << " " << c2[i] << '\n';
		}
	}
	
	return 0;
}