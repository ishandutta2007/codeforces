#include <iostream>
#include <cstring>
using namespace std;

const int N = 411;
int f[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		f[u][v] = f[v][u] = 1;
	}
	if(f[1][n] == 1)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				if(i != j)
				{
					if(f[i][j] == 1)
						f[i][j] = 0x3f3f3f3f;
					else
						f[i][j] = 1;
				}

	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

	if(f[1][n] == 0x3f3f3f3f)
		cout << -1 << '\n';
	else
		cout << f[1][n] << '\n';
	return 0;
}