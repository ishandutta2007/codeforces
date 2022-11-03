#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 5E5 + 10;

int n, m;
vector<int> E[MAXN];
vector<PII> lst[MAXN];
int dep[MAXN], mdep;
int tot, in[MAXN], out[MAXN];

char s[MAXN];

void DFS(int u){
	mdep = max(mdep, dep[u]);
	in[u] = ++tot;
	if (!lst[dep[u]].size())
		lst[dep[u]].push_back(PII(0, 0));
	lst[dep[u]].push_back(PII(tot, 1 << s[u - 1] - 'a'));
	for (int i = 0; i < E[u].size(); ++i){
		dep[E[u][i]] = dep[u] + 1;
		DFS(E[u][i]);
	}
	out[u] = ++tot;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, i = 2; i <= n; ++i){
		scanf("%d", &u);
		E[u].push_back(i);
	}
	scanf("%s", s);
	dep[1] = 1;
	DFS(1);

	for (int i = 1; i <= mdep; ++i)
		for (int j = 1; j < lst[i].size(); ++j)
			lst[i][j].nd ^= lst[i][j - 1].nd;

	for (int u, h, i = 0; i < m; ++i){
		scanf("%d%d", &u, &h);
		puts(mdep < h || h <= dep[u] || __builtin_popcount((--upper_bound(lst[h].begin(), lst[h].end(), PII(in[u], 0)))->nd ^ (--lower_bound(lst[h].begin(), lst[h].end(), PII(out[u], 0)))->nd) <= 1 ? "Yes" : "No");
	}
	
	return 0;
}