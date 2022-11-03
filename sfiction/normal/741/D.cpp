#include <cstdio>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 5E5 + 10, MAXC = 22, MAXM = 1 << MAXC;
const int INF = 1 << 30;

int n;
vector<PII> E[MAXN];
int size[MAXN], ms[MAXN];

int mask[MAXN], dep[MAXN];
vector<PII> lst[MAXN];
int cnt[MAXM];

int ans[MAXN];

void getSize(int u){
	ms[u] = 0;
	size[u] = 1;
	for (int v, i = 0; i < E[u].size(); ++i){
		getSize(v = E[u][i].st);
		size[u] += size[v];
		if (!ms[u] || size[ms[u]] < size[v])
			ms[u] = v;
	}
}

inline int calc(const PII &x){
	int ret = cnt[x.st];
	for (int i = 0; i < MAXC; ++i)
		ret = max(ret, cnt[x.st ^ 1 << i]);
	return ret + x.nd;
}

void DFS(int u, bool cFlag = false){
	for (int v, i = 0; i < E[u].size(); ++i){
		mask[v = E[u][i].st] = mask[u] ^ 1 << E[u][i].nd;
		dep[v] = dep[u] + 1;
		if (v != ms[u])
			DFS(v, true);
	}
	if (ms[u]){
		DFS(ms[u]);
		ans[u] = ans[ms[u]];
		lst[u].swap(lst[ms[u]]);
	}
	else{
		ans[u] = 0;
		lst[u].clear();
	}
	lst[u].emplace_back(mask[u], dep[u]);
	cnt[mask[u]] = max(cnt[mask[u]], dep[u]);
	ans[u] = max(ans[u], calc(lst[u].back()) - 2 * dep[u]);

	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == ms[u])
			continue;

		ans[u] = max(ans[u], ans[v]);
		for (auto &x: lst[v])
			ans[u] = max(ans[u], calc(x) - 2 * dep[u]);
		for (auto &x: lst[v]){
			lst[u].emplace_back(x);
			cnt[x.st] = max(cnt[x.st], x.nd);
		}
	}
	
	if (cFlag)
		for (auto &x: lst[u])
			cnt[x.st] = -INF;
}

int main(){
	fill_n(cnt, MAXM, -INF);

	scanf("%d", &n);
	char s[5];
	for (int u, i = 2; i <= n; ++i){
		scanf("%d%s", &u, s);
		E[u].push_back(PII(i, s[0] - 'a'));
	}
	getSize(1);
	mask[1] = 0, dep[1] = 0;
	DFS(1, true);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], "\n "[i < n]);
	return 0;
}