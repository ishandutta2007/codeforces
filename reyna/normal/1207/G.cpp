
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int sz = 1, nxt[N][26], inside[N], qv[N], qpos[N], q[N], f[N], fen[N], st[N], ed[N], tot;
vector<int> queries[N], inc[N], adj[N], trie_adj[N];
void aho_corasick() {
	int h = 0, t = 0;
	for (int j = 0; j < 26; ++j)
		if (nxt[0][j])
			q[t++] = nxt[0][j];
	while (h != t) {
		int v = q[h++];
		for (int c = 0; c < 26; ++c)
			if (nxt[v][c]) {
				f[nxt[v][c]] = nxt[f[v]][c];
				q[t++] = nxt[v][c];
			} else {
				nxt[v][c] = nxt[f[v]][c];	
			}
	}
}
void update(int m, int x) { ++m;
	while (m < N) {
		fen[m] += x;
		m += m & -m;
	}
}
int query(int m) { ++m;
	int res = 0;
	while (m > 0) {
		res += fen[m];
		m -= m & -m;
	}
	return res;
}
int query(int l, int r) {
	return query(r - 1) - query(l - 1);	
}
void dfs_init(int v) {
	st[v] = tot++;
	for (int u : adj[v]) {
		dfs_init(u);
	}
	ed[v] = tot;
}
int res[N];
void dfs_res(int v) {
	update(st[v], +1);
	for (int j : inc[v])
		for (int q : queries[j]) {
			int u = qv[q];
			res[q] = query(st[u], ed[u]);
		}
	for (int u : trie_adj[v]) {
		dfs_res(u);	
	}
	update(st[v], -1);
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int t;
		cin >> t;
		if (t == 1) {
			char c;
			cin >> c;
			if (!nxt[0][c - 'a']) {
				nxt[0][c - 'a'] = sz++;
			}
			inc[nxt[0][c - 'a']].pb(j);
			inside[j] = nxt[0][c - 'a'];
		} else {
			int pos;
			char c;
			cin >> pos >> c;
			c -= 'a';
			--pos;
			int v = inside[pos];
			if (!nxt[v][c]) {
				nxt[v][c] = sz++;
			}
			inc[nxt[v][c]].pb(j);
			inside[j] = nxt[v][c];
		}
	}
	int m;
	cin >> m;
	for (int j = 0; j < m; ++j) {
		int &pos = qpos[j];
		string t;
		cin >> pos >> t;
		--pos;
		int v = 0;
		for (char c : t) {
			if (!nxt[v][c - 'a']) {
				nxt[v][c - 'a'] = sz++;
			}
			v = nxt[v][c - 'a'];
		}
		qv[j] = v;
		queries[pos].pb(j);
	}
	for (int v = 0; v < sz; ++v)
		for (int c = 0; c < 26; ++c)
			if (nxt[v][c])
				trie_adj[v].pb(nxt[v][c]);
	aho_corasick();
	for (int v = 1; v < sz; ++v) {
		adj[f[v]].push_back(v);
	}
	dfs_init(0);
	dfs_res(0);
	for (int j = 0; j < m; ++j)
		cout << res[j] << '\n';
}