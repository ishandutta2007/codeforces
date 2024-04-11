#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, dep[N], size[N], seg[N], cnt, a[N];
struct tree {
	private:
		int num[N];
		int lowbit(int x) {
			return (x & (-x));
		}
	public: 
		void update(int u, int val) {
			while(u <= n) {
				num[u] += val;
				u += lowbit(u);
			}
		}
		void add(int l, int r, int val) {
			update(l, val); update(r + 1, -val);
		}
		int query(int u) {
			int res = 0;
			while(u) {
				res += num[u];
				u -= lowbit(u);
			}
			return res;
		}
} t1, t2;

struct Edge {
	int v, nxt;
} edge[N * 2];
int head[N], k = 1;
void addedge(int u, int v) {
	edge[++k].v = v;
	edge[k].nxt = head[u];
	head[u] = k;
}

void dfs(int u, int fa) {
	seg[u] = ++cnt;
	size[u] = 1; dep[u] = dep[fa] + 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		dfs(v, u);
		size[u] += size[v];
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v); addedge(v, u);
	}
	dfs(1, 0);
	for(int i = 1; i <= m; i++) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int u, val;
			cin >> u >> val;
			if(dep[u] & 1) t1.add(seg[u], seg[u] + size[u] - 1, val);
			else t1.add(seg[u], seg[u] + size[u] - 1, -val);
		}
		else {
			int u;
			cin >> u;
			if(dep[u] & 1) cout << a[u] + t1.query(seg[u]) << endl;
			else cout << a[u] - t1.query(seg[u]) << endl;
		}
	}
}