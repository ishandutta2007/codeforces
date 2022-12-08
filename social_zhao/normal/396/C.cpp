#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const long long wty = 1000000007;
const int N = 3e5 + 5;
int n;
int seg[N], size[N], dep[N], cnt = 0;
class tree {
	private:
		long long num[N];
		int lowbit(int x) {
			return (x & (-x));
		}
	public: 
		void update(int u, int val) {
			while(u <= n) {
				num[u] = (num[u] + val) % wty;
				u += lowbit(u);
			}
		}
		void add(int l, int r, long long val) {
			update(l, val); update(r + 1, -val);
		}
		long long query(int u) {
			long long res = 0;
			while(u) {
				res = (res + num[u]) % wty;
				u -= lowbit(u);
			}
			return (res +wty) % wty;
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

signed main() {
	ios::sync_with_stdio(0);
	n = get();
	for(int i = 2; i <= n; i++) {
		int fa = get();
		addedge(fa, i), addedge(i, fa); 
	}
	dfs(1, 0);
	int q = get();
	for(int i = 1; i <= q; i++) {
		int opt = get();
		if(opt == 1) {
			long long u = get(), x = get(), y = get();
			t1.add(seg[u], seg[u] + size[u] - 1, (x + dep[u] * y % wty));
			t2.add(seg[u], seg[u] + size[u] - 1, -y);
		}
		else {
			int u = get();
			cout << (t1.query(seg[u]) + t2.query(seg[u]) * dep[u] % wty + wty) % wty << endl;
		}
	}
	return 0;
}