#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}
#define LL long long
void write(LL x) {
	if (x < 0) {
		putchar('-');
		write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

#define pb push_back

const LL inf = 1000000000000000ll;
const int Nd = 4e5;
const int N = 1e6 + 10;
vector <int> E[N], V[N];
int pos[N];
LL dis[N];
bool vis[N];
int s, n, q;

void insert(int u, int v, int w) {
	E[u].pb(v), V[u].pb(w);
}

void build(int k, int l, int r) {
	if (l == r) {
		pos[l] = k;
		return;
	}
	int mid = l + r >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
}

void add(int k, int l, int r, int x, int y, int u, int w, bool f) {
	if (x == l && r == y) {
		if (f) insert(pos[u], k, w);
		else insert(k + Nd, pos[u], w);
		return;		
	}
	int mid = l + r >> 1;
	if (y <= mid) add(k << 1, l, mid, x, y, u, w, f);
	else if (x > mid) add(k << 1 | 1, mid + 1, r, x, y, u, w, f);
	else add(k << 1, l, mid, x, mid, u, w, f), add(k << 1 | 1, mid + 1, r, mid + 1, y, u, w, f);
}

void link(int k, int l, int r) {
	for (int i = l; i <= r; i ++) insert(k, pos[i], 0), insert(pos[i], k + Nd, 0);
	if (l == r) return;
	int mid = l + r >> 1;
	link(k << 1, l, mid);
	link(k << 1 | 1, mid + 1, r);
}

void spfa() {
	for (int i = 0; i < N; i ++) dis[i] = inf;
	dis[pos[s]] = 0;
	vis[pos[s]] = 1;
	queue <int> q;
	q.push(pos[s]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int eg = E[u].size();
		for (int i = 0; i < eg; i ++) {
			int v = E[u][i];
			if (dis[u] + V[u][i] < dis[v]) {
				dis[v] = dis[u] + V[u][i];
				if (!vis[v]) q.push(v);
				vis[v] = 1;
			}
		}
		vis[u] = 0;
	}
} 

int main() {
	n = read(), q = read(), s = read();
	build(1, 1, n);
	for (int i = 1; i <= q; i ++) {
		int op = read();
		if (op == 1) {
			int u = read(), v = read(), w = read();
			insert(pos[u], pos[v], w);
		}
		else {
			int u = read(), lv = read(), rv = read(), w = read();
			add(1, 1, n, lv, rv, u, w, op == 2);
		}
	}
	link(1, 1, n);
	spfa();
	for (int i = 1; i <= n; i ++) {
		if (dis[pos[i]] == inf) write(-1);
		else write(dis[pos[i]]);
		putchar(32);
	}
	return 0;
}