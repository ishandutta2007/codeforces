#pragma GCC optimize("unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define FAST_ALLOCATOR_MEMORY 100*1024*1024
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int) FAST_ALLOCATOR_MEMORY];
 
inline void *operator new(size_t n) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= (int) FAST_ALLOCATOR_MEMORY);
    return (void *) res;
}
 
inline void operator delete(void *) noexcept {}
 
inline void operator delete(void *, size_t) {}
#endif

static const int buf_size = 4096;
 
static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;
 
inline bool isEof() {
    if (buf_pos == buf_len) {
        buf_pos = 0;
        buf_len = fread(buf, 1, buf_size, stdin);
        if (buf_pos == buf_len)
            return 1;
    }
    return 0;
}
 
inline int getChar() {
    return isEof() ? -1 : buf[buf_pos++];
}
 
inline int peekChar() {
    return isEof() ? -1 : buf[buf_pos];
}
 
inline int readChar() {
    int c = getChar();
    while (c != -1 && c <= 32)
        c = getChar();
    return c;
}
  
template<class T = int>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-') {
        s = -1;
        c = getChar();
    } else if (c == '+')
        c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}


const int MAXN = 150228;
vector<int> g[MAXN];
int n;
int a[MAXN];

void read() {
	n = readInt();
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		//cin >> u >> v;
		u = readInt();
		v = readInt();
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) 
		a[i] = readInt();
		//cin >> a[i];
}

ll ans;

bool used[MAXN];
int sz[MAXN];
int centr = 0;

void dfs_centr(int v, int p, int size) {
	sz[v] = 1;
	int mx = 0;
	for (auto i : g[v]) {
		if (used[i] || i == p) continue;
		dfs_centr(i, v, size);
		sz[v] += sz[i];
		chkmax(mx, sz[i]);
	}
	chkmax(mx, size - sz[v]);
	if (mx <= size / 2) {
		centr = v;
	}
}

const ll INF = -1e18;

struct line{
	ll k, b;
	line() {
		k = 0, b = INF;
	}
	line(ll _k, ll _b) {
		k = _k, b = _b;
	}
};

ll eval(line l, ll x) {
	return l.k * x + l.b;
}

struct node{
	node *l, *r;
	line x;
	node() {}
	node(line _x) {
		l = nullptr;
		r = nullptr;
		x = _x;
	}
};

struct li_chao{
	node * root;
	li_chao() {
		root = nullptr;
	}

	node * add(line x, node * tree, ll tl, ll tr) {
		if (tree == nullptr) {
			tree = new node(x);
			return tree;
		}
		ll tm = (tl + tr) / 2;
		bool mid = eval(tree->x, tm) < eval(x, tm);
		bool left = eval(tree->x, tl) < eval(x, tl);

		if (mid) swap(x, tree->x);
		if (tl == tr - 1) return tree;
		if (mid != left) {
			tree->l = add(x, tree->l, tl, tm);
		}
		else {
			tree->r = add(x, tree->r, tm, tr);
		}
		return tree;
	}

	void add(line x) {
		root = add(x, root, 0, 1e12);
	}

	ll get(ll x, node * tree, ll tl, ll tr) {
		if (tree == nullptr) return 0;
		if (tl >= x + 1 || tr <= x) return 0;
		if (tl == tr - 1) return eval(tree->x, x);
		ll tm = (tl + tr) / 2;
		return max(eval(tree->x, x), max(get(x, tree->l, tl, tm), get(x, tree->r, tm, tr)));
	}

	ll get(ll x) {
		return get(x, root, 0, 1e12);
	}
};

li_chao nor, rev;

void dfs_calc(int v, int p, ll sum, int len, ll sum_nor, ll sum_rev) {
	sum_nor += sum + a[v];
	sum_rev += (ll) (len + 1) * a[v];
	len++;
	sum += a[v];
	
	chkmax(ans, sum_nor);
	chkmax(ans, sum_rev);
	chkmax(ans, nor.get(sum) + sum_rev);
	chkmax(ans, rev.get(len) + sum_nor);

	for (auto i : g[v]) {
		if (used[i] || i == p) continue;
		dfs_calc(i, v, sum, len, sum_nor, sum_rev);
	}
}

void dfs_add(int v, int p, ll sum, int len, ll sum_nor, ll sum_rev) {
	sum_nor += sum + a[v];
	len++;
	sum_rev += (ll) len * a[v];
	sum += a[v];
	
	nor.add(line(len, sum_nor));
	rev.add(line(sum, sum_rev));
	for (auto i : g[v]) {
		if (used[i] || i == p) continue;
		dfs_add(i, v, sum, len, sum_nor, sum_rev);
	}
}

void solve(int v, int size) {
	dfs_centr(v, -1, size);
	v = centr;
	used[v] = true;
	chkmax(ans, a[v]);

	nor = li_chao();
	rev = li_chao();
	for (auto i : g[v]) {
		if (used[i]) continue;
		dfs_calc(i, v, a[v], 1, a[v], a[v]);
		dfs_add(i, v, 0, 0, 0, 0);
	}	
	for (auto i : g[v]) {
		if (used[i]) continue;
		int fsz = sz[i];
		if (fsz > sz[v]) fsz = size - sz[v];
		solve(i, fsz);
	}
}

void run() {
	solve(0, n);
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cerr.tie(0);
	read();
	run();
	write();
	return 0;
}