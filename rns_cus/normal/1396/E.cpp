#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, sz[N], x[N], y[N], cnt[N];
long long k;
vector <int> adj[N];

int dfs(int u, int pa = 0) {
	int rlt = 1;
	for (auto e : adj[u]) {
		int v = x[e] ^ y[e] ^ u;
		if (v == pa) continue;
		int c = dfs(v, u);
		if (c & 1) cnt[e] ++, k --;
		sz[e] = c, rlt += c;
	}
	return rlt;
}

int id[N], up[N];

vector < pair <int, int> > ans;
vector <int> vec[N];

void dfs_solve(int u, int pa = 0, int up = 0) {
	vec[u].push_back(u);
	int tot = 0;
	typedef pair <int, int> pii;
	priority_queue <pii> pq;
	pq.emplace(1, u);
	for (auto e : adj[u]) {
		int v = x[e] ^ y[e] ^ u;
		if (v == pa) continue;
		dfs_solve(v, u, cnt[e]);
		assert(vec[v].size() == cnt[e]);
		tot += cnt[e];
		pq.emplace(cnt[e], v);
	}
	while (tot > up) {
		pii pu = pq.top(); pq.pop();
		pii pv = pq.top(); pq.pop();
		int u = pu.second, v = pv.second;
		tot -= 2;
		ans.emplace_back(vec[u].back(), vec[v].back()), vec[u].pop_back(), vec[v].pop_back();
		pq.emplace(pu.first - 1, u), pq.emplace(pv.first - 1, v);
	}
	for (auto e : adj[u]) {
		int v = x[e] ^ y[e] ^ u;
		if (v == pa) continue;
		if (vec[u].size() < vec[v].size()) swap(vec[u], vec[v]);
		for (auto x : vec[v]) vec[u].push_back(x);
	}
}

int main() {
    scanf("%d %lld", &n, &k);
    long long _k = k;
    for (int i = 1, u, v; i < n; i ++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(i);
		adj[v].push_back(i);
		x[i] = u, y[i] = v;
    }
    dfs(1);
    if (k < 0 || (k & 1)) return puts("NO"), 0;
    long long sum = 0; k /= 2;
    for (int i = 1; i < n; i ++) id[i] = i, up[i] = min(sz[i], n - sz[i]), sz[i] = min(sz[i], n - sz[i]) / 2, sum += sz[i];
    if (k > sum) return puts("NO"), 0;
	sort(id + 1, id + n, [&](int i, int j) {return sz[i] < sz[j];});

	for (int i = 1, c = 0; i < n; i ++) {
		if (1ll * (n - i) * (sz[id[i]] - c) >= k) {
			int q = k / (n - i), r = k % (n - i);

			for (int j = i; j < i + r; j ++) cnt[id[j]] += 2;
			for (int j = i; j < n; j ++) cnt[id[j]] += 2 * (c + q);
			for (int j = 1; j < i; j ++) cnt[id[j]] += 2 * sz[id[j]];
			break;
		}
		else k -= 1ll * (n - i) * (sz[id[i]] - c), c = sz[id[i]];
	}

	while (1) {
		bool fg = false;
		for (int u = 1; u <= n; u ++) {
			int mx = 0;
			long long s = 0;
			for (auto e : adj[u]) mx = max(mx, cnt[e]), s += cnt[e];
			if (mx > s - mx + 1) { fg = true;
				int e1;
				for (auto e : adj[u]) if (mx == cnt[e]) {e1 = e; cnt[e] -= 2; break;}
				for (auto e : adj[u]) {
					if (e != e1 && cnt[e] + 2 <= up[e]) {
						cnt[e] += 2; break;
					}
				}
			}
		}
		if (!fg) break;
	}

	dfs_solve(1);

	puts("YES");
	for (auto p : ans) printf("%d %d\n", p.first, p.second);

    return 0;
}