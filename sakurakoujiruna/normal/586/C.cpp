#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 4111;

int v[N];
int d[N];
long long p[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> v[i] >> d[i] >> p[i];

	vector <int> ans;
	memset(vis, 0, sizeof(vis));

	for(int i = 1; i <= n; i ++)
	{
		if(!vis[i])
		{
			ans.push_back(i);
			for(int j = i + 1; j <= n; j ++)
				if(!vis[j] && v[i] >= 0)
				{
					p[j] -= v[i];
					v[i] --;
				}
		}

		bool flag = false;
		while(!flag)
		{
			flag = true;
			for(int j = i + 1; j <= n; j ++)
				if(!vis[j] && p[j] < 0)
				{
					vis[j] = true;
					flag = false;
					for(int k = j + 1; k <= n; k ++)
						p[k] -= d[j];
					break;
				}
		}
	}

	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}