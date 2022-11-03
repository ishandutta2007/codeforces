#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E5 + 10;

int n, m;
ll inv10;
vector<PII> E[MAXN];
bool vis[MAXN];
int size[MAXN];

ll ans;

ll modExp(ll e, ll n, ll m){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int getPhi(int x){
	int ret = 1;
	for (int i = 2; i * i <= x; ++i){
		if (x % i)
			continue;
		ret *= i - 1;
		for (x /= i; x % i == 0; x /= i)
			ret *= i;
	}
	return ret * max(1, x - 1);
}

int totSize, cent, centSize;

void getCentroid(int u, int pre){
	size[u] = 1;
	int vs = 0;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == pre || vis[v])
			continue;
		getCentroid(v, u);
		size[u] += size[v];
		vs = max(vs, size[v]);
	}
	vs = max(vs, totSize - size[u]);
	if (centSize > vs)
		cent = u, centSize = vs;
}

map<int, int> lst;
vector<int> alst;

void DFS(int u, int pre, ll a, ll b, ll a10, ll b10){
	size[u] = 1;
	if (lst.count((m - b) * b10 % m))
		ans += lst[(m - b) * b10 % m];
	alst.push_back(a);
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == pre || vis[v])
			continue;
		DFS(v, u, (a + E[u][i].nd * a10) % m, (b * 10 + E[u][i].nd) % m, a10 * 10 % m, b10 * inv10 % m);
		size[u] += size[v];
	}
}

void solve(int u, int tot){
	totSize = centSize = tot, cent = u;
	getCentroid(u, 0);
	vis[u = cent] = true;

	lst.clear();
	lst[0] = 1;
	for (int v, i = 0; i < E[u].size(); ++i){
		if (vis[v = E[u][i].st])
			continue;
		alst.clear();
		DFS(v, u, E[u][i].nd % m, E[u][i].nd % m, 10 % m, inv10);
		for (int j = 0; j < alst.size(); ++j){
			ans += alst[j] == 0;
			if (lst.count(alst[j]) == 0)
				lst[alst[j]] = 1;
			else
				++lst[alst[j]];
		}
	}
	lst.clear();
	for (int v, i = E[u].size() - 1; i >= 0; --i){
		if (vis[v = E[u][i].st])
			continue;
		alst.clear();
		DFS(v, u, E[u][i].nd % m, E[u][i].nd % m, 10 % m, inv10);
		for (int j = 0; j < alst.size(); ++j)
			if (lst.count(alst[j]) == 0)
				lst[alst[j]] = 1;
			else
				++lst[alst[j]];
	}

	for (int v, i = 0; i < E[u].size(); ++i)
		if (!vis[v = E[u][i].st])
			solve(v, size[v] < size[u] ? size[v] : tot - size[u]);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, w, i = 1; i < n; ++i){
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back(PII(v, w));
		E[v].push_back(PII(u, w));
	}
	inv10 = modExp(10, getPhi(m) - 1, m);
	solve(0, n);
	printf("%I64d\n", ans);
	return 0;
}