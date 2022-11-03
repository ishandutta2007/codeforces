#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 5E5 + 10, MAXD = 50;

int n;
double f[MAXN][MAXD];
int par[MAXN];

int main(){
	int m;
	scanf("%d", &m);
	for (int i = 0; i < MAXD; ++i)
		f[1][i] = 1;
	int n = 1;
	for (int com, u, i = 0; i < m; ++i){
		scanf("%d%d", &com, &u);
		if (com == 1){
			par[++n] = u;
			for (int i = 0; i < MAXD; ++i)
				f[n][i] = 1;
			vector<int> a;
			for (int u = n, i = 0; u > 1 && i < MAXD; ++i, u = par[u])
				a.push_back(u);

			for (int i = a.size() - 1; i > 0; --i)
				f[par[a[i]]][i] /= (1 + f[a[i]][i - 1]) / 2;
			f[par[n]][0] /= 2.0;
			for (int i = 1; i < a.size(); ++i)
				f[par[a[i]]][i] *= (1 + f[a[i]][i - 1]) / 2;
		}
		else if (com == 2){
			double ans = 0;
			for (int i = 0; i < MAXD; ++i)
				ans += 1 - f[u][i];
			printf("%.8f\n", ans);
		}
	}
	return 0;
}