#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int MN = 200005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

struct union_find {
	int rt[MN], cnt[MN];
	
	void init(int n) {
		for (int u = 1; u <= n; u++) {
			rt[u] = u;
			cnt[u] = 1;
		}
	}
	
	int find_rt(int u) {
		if (rt[u] != u) rt[u] = find_rt(rt[u]);
		return rt[u];
	}
	
	bool merge(int u, int v) {
		u = find_rt(u);
		v = find_rt(v);
		if (u == v) return 0;
		if (cnt[u] < cnt[v]) swap(u, v);
		rt[v] = u;
		cnt[u] += cnt[v];
		return 1;
	}
} A, B;

int n, m, W;
vector<int> con[MN];
struct edge {
	int u, v, w;
	void in() {
		cin >> u >> v >> w;
		con[u].push_back(v);
		con[v].push_back(u);
		W ^= w;
	}
} E[MN];

bool operator<(edge e1, edge e2) {
	return e1.w < e2.w;
}

set<int> S;
queue<int> Q;
bool vis[MN];

void init() {
	sort(E, E + m);
	S.clear();
	for (int i = 1; i <= n; i++) {
		sort(con[i].begin(), con[i].end());
		S.insert(i);
	}
	A.init(n); B.init(n);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) E[i].in();
	int cnt = min(1000000LL, 1LL * n * (n - 1) / 2 - m);
	init();
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		while (!Q.empty()) Q.pop();
		vis[i] = 1;
		S.erase(i);
		Q.push(i);
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int v = 0; ; v++) {
				auto it = S.lower_bound(v);
				if (it == S.end()) break;
				v = *it;
				auto ct = lower_bound(con[u].begin(), con[u].end(), v);
				if (ct == con[u].end() || *ct != v) {
					Q.push(v);
					S.erase(v);
					vis[v] = 1;
					A.merge(v, i);
					cnt--;
				}
			}
		}
	}
	if (cnt) W = 0;
	LL rlt = 0;
	for (int i = 0; i < m; i++) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if (A.merge(u, v)) rlt += w, B.merge(u, v);
		else if (B.merge(u, v)) W = min(W, w);
	}
	cout << rlt + W << endl;

	return 0;

}