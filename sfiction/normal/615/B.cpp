#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

vector<int> E[MAXN];
int deg[MAXN], len[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		++deg[u];
		E[v].push_back(u);
		++deg[v];
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++i){
		++len[i];
		for (int j = 0; j < E[i].size(); ++j)
			len[E[i][j]] = max(len[E[i][j]], len[i]);
		ans = max(ans, len[i] * (ll)deg[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}