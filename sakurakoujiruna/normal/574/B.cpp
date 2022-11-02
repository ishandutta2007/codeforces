#include <iostream>
using namespace std;

const int N = 4011;
const int Inf = 0x3f3f3f3f;

int deg[N];
bool edge[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	while(m --)
	{
		int u, v;
		cin >> u >> v;
		deg[u] ++;
		deg[v] ++;
		edge[u][v] = true;
		edge[v][u] = true;
	}

	int ans = Inf;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(edge[i][j])
				for(int k = 1; k <= n; k ++)
					if(edge[i][k] && edge[j][k])
						ans = min(ans, deg[i] + deg[j] + deg[k] - 6);

	if(ans == Inf)
		ans = -1;
	cout << ans << '\n';
	return 0;
}