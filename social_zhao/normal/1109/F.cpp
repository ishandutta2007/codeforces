#include<bits/stdc++.h>
#define int long long
#define lc c[x][0]
#define rc c[x][1]
#define ls (u << 1)
#define rs (u << 1 | 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int T = 4005, N = 4e5 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, num[T][T];
struct Edge {
	int v, nxt;
} edge[N << 1];
int head[N], tot;
int f[N], c[N][2], r[N], bin[N], top;

void add(int u, int v) {
	edge[++tot].v = v, edge[tot].nxt = head[u], head[u] = tot;
}

bool chk(int x) { return c[f[x]][1] == x; }
bool nroot(int x) { return c[f[x]][chk(x)] == x; }
void pushr(int x) { r[x] ^= 1, swap(lc, rc); }
void pushdown(int x) { if(r[x]) { if(lc) pushr(lc); if(rc) pushr(rc); r[x] = 0; } }
void rotate(int x) {
	int y = f[x], z = f[y], k = chk(x), w = c[x][!k];
	if(nroot(y)) c[z][chk(y)] = x; c[x][!k] = y; c[y][k] = w;
	if(w) f[w] = y; f[y] = x; f[x] = z;
}
void splay(int x) {
	int y = x, z;
	bin[++top] = y;
	while(nroot(y)) bin[++top] = y = f[y];
	while(top) pushdown(bin[top--]);
	while(nroot(x)) {
		y = f[x], z = f[y];
		if(nroot(y)) rotate(chk(x) ^ chk(y)? x : y);
		rotate(x);
	}
}
void access(int x) { for(int y = 0; x; x = f[y = x]) splay(x), rc = y; }
void makeroot(int x) { access(x), splay(x), pushr(x); }
int findroot(int x) { access(x), splay(x); while(lc) pushdown(lc), x = lc; splay(x); return x; }
bool link(int x, int y) { makeroot(x); if(findroot(y) == x) return 0; f[x] = y; return 1; }
void cut(int x, int y) { makeroot(x); if(findroot(y) == x && f[y] == x && !c[y][0]) f[y] = rc = 0; }

int ms[N << 2], tag[N << 2], mx[N << 2];

void pusha(int u, int v) { tag[u] += v, mx[u] += v; }
void pushd(int u) { if(tag[u]) pusha(ls, tag[u]), pusha(rs, tag[u]), tag[u] = 0; }
void pushup(int u) { 
	if(mx[ls] > mx[rs]) mx[u] = mx[rs], ms[u] = ms[rs];
	if(mx[ls] < mx[rs]) mx[u] = mx[ls], ms[u] = ms[ls];
	if(mx[ls] == mx[rs]) mx[u] = mx[ls], ms[u] = ms[ls] + ms[rs];
}
void build(int u, int l, int r) {
	if(l == r) return void(ms[u] = 1);
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void update(int u, int l, int r, int a, int b, int v) {
	if(a == l && r == b) return pusha(u, v);
	pushd(u);
	int mid = l + r >> 1;
	if(b <= mid) update(ls, l, mid, a, b, v);
	else if(a > mid) update(rs, mid + 1, r, a, b, v);
	else update(ls, l, mid, a, mid, v), update(rs, mid + 1, r, mid + 1, b, v);
	pushup(u);
}
int query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return (mx[u] == 1) * ms[u];
	pushd(u);
	int mid = l + r >> 1;
	if(b <= mid) return query(ls, l, mid, a, b);
	else if(a > mid) return query(rs, mid + 1, r, a, b);
	else return query(ls, l, mid, a, mid) + query(rs, mid + 1, r, mid + 1, b);
}

signed main() {
//	freopen("data.in", "r", stdin);
	n = get(), m = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			num[i][j] = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 0; k < 4; k++)
				if(num[i + dx[k]][j + dy[k]] > num[i][j]) 
					add(num[i][j], num[i + dx[k]][j + dy[k]]), add(num[i + dx[k]][j + dy[k]], num[i][j]);
	int nowr = 0, ans = 0;
	build(1, 1, n * m);
	for(int i = 1; i <= n * m; i++) {
		for(int j = nowr + 1; j <= n * m; j++) {
			int cir = 0;
			for(int k = head[j]; k; k = edge[k].nxt) {
				int v = edge[k].v;
				if(i <= v && v < j) if(!link(j, v)) { cir = 1; break; }
			}
			for(int k = head[j]; k; k = edge[k].nxt) cut(j, edge[k].v);
			if(cir) break;
			nowr = j; 
			int cnt = 0;
			for(int k = head[j]; k; k = edge[k].nxt) {
				int v = edge[k].v;
				if(i <= v && v < j) link(j, v), cnt++;
			}
			update(1, 1, n * m, j, j, nowr - i + 1);
			update(1, 1, n * m, nowr, n * m, -cnt);
		}
		ans += query(1, 1, n * m, i, nowr);
		for(int j = head[i]; j; j = edge[j].nxt) {
			int v = edge[j].v;
			if(v >= i && v <= nowr) cut(i, v), update(1, 1, n * m, v, n * m, 1);
		}
		update(1, 1, n * m, i, nowr, -1);
	}
	printf("%lld\n", ans);
	return 0;
}