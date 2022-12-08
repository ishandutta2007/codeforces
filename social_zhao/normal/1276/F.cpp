#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, pos[N], sop[N];
char s[N];
struct SAM {
	struct State { int ch[26], len, fa; } st[N];
	int lst = 1, tot = 1;
	
	int insert(int c) {
		int p = lst, np = lst = ++tot;
		st[np].len = st[p].len + 1;
		while(p && !st[p].ch[c]) st[p].ch[c] = np, p = st[p].fa;
		if(!p) st[np].fa = 1;
		else {
			int q = st[p].ch[c];
			if(st[q].len == st[p].len + 1) st[np].fa = q;
			else {
				int nq = ++tot;
				st[nq] = st[q], st[nq].len = st[p].len + 1;
				st[q].fa = st[np].fa = nq;
				while(p && st[p].ch[c] == q) st[p].ch[c] = nq, p = st[p].fa;
			}
		}
		return np;
	}
} s1, s2;
vector<int> adj[N], jda[N];
set<pair<int, int>> lin[N];
int dfn[N], tim, f[N][20], dep[N], sum[N], ans1, ans2, tag[N];

void sfd(int u, int lst) {
	dfn[u] = ++tim, f[u][0] = lst, dep[u] = dep[lst] + 1;
	for(int i = 1; i <= 19; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(auto v : jda[u]) sfd(v, u);
}

int GetLCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int GetDis(int x, int y) { return s2.st[x].len + s2.st[y].len - 2 * s2.st[GetLCA(x, y)].len; }

void dfs(int u, int lst) {
	ans1 += s1.st[u].len - s1.st[lst].len;
	if(u == pos[n]) return;
	lin[u].emplace(1, 1), lin[u].emplace(tim + 1, 1), sum[u] = 2;
	if(tag[u])
		lin[u].emplace(dfn[tag[u]], tag[u]), sum[u] += 2 * s2.st[tag[u]].len;
	for(auto v : adj[u]) {
		dfs(v, u);
		if(lin[v].size() > lin[u].size()) {
			swap(lin[u], lin[v]), sum[u] = sum[v];
		}
		for(auto x : lin[v]) {
			if(lin[u].find(x) != lin[u].end()) continue;
			set<pair<int, int>>::iterator itl = lin[u].lower_bound(x), itr = itl;
			--itl;
			sum[u] -= GetDis(itl -> second, itr -> second);
			sum[u] += GetDis(itl -> second, x.second) + GetDis(x.second, itr -> second);
			lin[u].insert(x);
		}
	}
	ans2 += (s1.st[u].len - s1.st[lst].len) * (sum[u] / 2);
}

main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int i = 1; i <= n; i++) pos[i] = s1.insert(s[i] - 'a'); s1.st[0].len = -1; pos[0]     = 1;
	for(int i = n; i >= 1; i--) sop[i] = s2.insert(s[i] - 'a'); s2.st[0].len = -1; sop[n + 1] = 1;
	for(int i = 2; i <= s1.tot; i++) adj[s1.st[i].fa].emplace_back(i);
	for(int i = 2; i <= s2.tot; i++) jda[s2.st[i].fa].emplace_back(i);
	for(int i = 1; i <= n; i++) tag[pos[i - 1]] = sop[i + 1];
	sfd(1, 0);
	dfs(1, 0);
//	for(int i = 1; i <= s1.tot; i++) cout << tag[i] << " "; cout << endl;
//	for(int i = 1; i <= s1.tot; i++) cout << sum[i] / 2 << " "; cout << endl;
//	cout << ans1 << " " << ans2 << endl;
	cout << ans1 + ans2 << endl;
	return 0;
}