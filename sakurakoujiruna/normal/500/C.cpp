#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
int w[N], b[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> w[i];
	for(int i = 1; i <= m; i ++)
		cin >> b[i];

	int ans = 0;
	for(int i = 1; i <= m; i ++)
	{
		memset(vis, 0, sizeof(vis));
		for(int j = i - 1; j >= 1; j --)
			if(b[j] == b[i])
				break;
			else if(!vis[b[j]])
			{
				vis[b[j]] = true;
				ans += w[b[j]];
			}
	}
	cout << ans << '\n';
	return 0;
}