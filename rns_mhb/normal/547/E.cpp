#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define mc 26

int n, q, xx, yy, zz, id[N], dt[N * 26], et[N * 26], tm, root[N], tot, ll, rr;
char s[N], T;
vector <int> V[N * 26];

struct tree{
	int l, r, num;
} t[N * 30];

int modify(int x, int L, int R, int d) {
	int res = ++ tot;
	t[res] = t[x];
	t[res].num ++;
	if (L >= R) return res;
	int mid = L + R >> 1;
	if (mid < d) t[res].r = modify(t[res].r, mid + 1, R, d);
	else t[res].l = modify(t[res].l, L, mid, d);
	return res;
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return t[x].num;
	if (l > R || r < L) return 0;
	int mid = L + R >> 1;
	return query(t[x].l, L, mid, l, r) + query(t[x].r, mid + 1, R, l, r);
}

struct trie{

	struct Node{
		int nxt[mc], link;
	}node[N];
	int sz = 0, tm = 0, fa[N];
	
	int newnode() {
		node[sz].link = 0;
		memset(node[sz].nxt, 0, sizeof node[sz].nxt);
		return sz ++;
	}
	
	void init() {
		sz = 0;
		newnode();
	}
	
	void add(char *ad, int idx) {
		int k = 0;
		for (int i = 0; ad[i]; i ++) {
			int c = ad[i] - 'a';
			if (node[k].nxt[c]) k = node[k].nxt[c];
			else {
				node[k].nxt[c] = newnode();
				fa[node[k].nxt[c]] = k;
				k = node[k].nxt[c];
			}
		}
		id[idx] = k;
		return;
	}
	
	void get_link() {
		queue <int> Q;
		while (!Q.empty()) Q.pop();
		int k = 0;
		for (int i = 0; i < mc; i ++) if (node[k].nxt[i]) Q.push(node[k].nxt[i]);
		while (!Q.empty()) {
			k = Q.front(); Q.pop();
			for (int i = 0; i < mc; i ++) {
				int u = node[k].nxt[i];
				if (!u) continue;
				else {
					Q.push(u);
					int v = node[k].link;
					while (v && !node[v].nxt[i]) v = node[v].link;
					node[u].link = node[v].nxt[i];
				}
			}
		}
	}
	
	void build() {
		for (int i = 1; i < sz; i ++) V[node[i].link].push_back(i);
		tm = 0;
		return;
	}
	
	void dfs(int v) {
		dt[v] = ++ tm;
		for (int i = 0; i < V[v].size(); i ++) dfs(V[v][i]);
		et[v] = tm;
	}
}ACT;

int main() {
	scanf("%d %d", &n, &q);
	ACT.init();
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s);
		ACT.add(s, i);
	}
	ACT.get_link();
	ACT.build();
	ACT.dfs(0);
	for (int i = 1; i <= n; i ++) {
		int k = root[i - 1];
		int u = id[i];
		while (u) {
			k = modify(k, 1, ACT.sz, dt[u]);
			u = ACT.fa[u];
		}
		root[i] = k;
	}
	while (q --) {
		scanf("%d %d %d", &xx, &yy, &zz);
		printf("%d\n", query(root[yy], 1, ACT.sz, dt[id[zz]], et[id[zz]]) - query(root[xx - 1], 1, ACT.sz, dt[id[zz]], et[id[zz]]));
	}
	return 0;
}