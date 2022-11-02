#include <bits/stdc++.h>

using namespace std;

#define N 200010

typedef long long ll;

int n, k, tot, a[10], x[N];
int p[120][10], mul[120][120], lst[120];

int find() {
	int id;
	for (id = 0; id < tot; id ++) {
		bool fg = 1;
		for (int j = 1; j <= k; j ++) if (a[j] != p[id][j]) fg = 0;
		if (fg) break;
	}
	assert(id < tot);
	return id;
}

vector <int> base[N];
bool vis[N][120];
int cnt[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i ++) a[i] = i;
	do {
		memcpy(p[tot], a, sizeof a);
		tot ++;
	} while (next_permutation(a + 1, a + k + 1));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) scanf("%d", &a[j]);
		x[i] = find();
	}
	for (int i = 0; i < tot; i ++) {
		for (int j = 0; j < tot; j ++) {
			for (int t = 1; t <= k; t ++) a[t] = p[i][p[j][t]];
			mul[i][j] = find();
		}
	}
	ll ans = 0;
	vector <int> vec;
	for (int i = 1; i <= n; i ++) {
		int c = 0;
		do {
			c = mul[c][x[i]];
			vis[i][c] = 1;
			cnt[i] ++;
		} while (c);
		vec.push_back(i), base[i].push_back(x[i]);
		int sz = vec.size();
		for (int j = sz - 2; ~j; j --) {
			int u = vec[j];
			if (vis[u][x[i]]) break;
			base[u].push_back(x[i]);
			queue <int> Q; Q.push(x[i]); vis[u][x[i]] = 1, cnt[u] ++;
			while (!Q.empty()) {
				int v = Q.front(); Q.pop();
				for (auto d : base[u]) {
					int w = mul[v][d];
					if (!vis[u][w]) vis[u][w] = 1, cnt[u] ++, Q.push(w);
					w = mul[d][v];
					if (!vis[u][w]) vis[u][w] = 1, cnt[u] ++, Q.push(w);
				}
			}
		}
		int s = 0;
		for (int j = 0, t = 0; j < sz; j = t) {
			while (t < sz && cnt[vec[t]] == cnt[vec[j]]) t ++;
			swap(vec[s++], vec[t-1]);
		}
		vec.resize(s);
		for (int j = 0; j < s; j ++) {
			int l = j ? vec[j-1] : 0;
			ans += 1ll * (vec[j] - l) * cnt[vec[j]];
		}
	}

	printf("%I64d\n", ans);
}