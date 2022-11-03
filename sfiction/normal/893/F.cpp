#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 1E5 + 10;

namespace SGT{
	struct Node{
		int l, r, val;
	}a[N * 18 * 2];

	int tot;

	void init(){
		// a[0].l = a[0].r = 0;
		a[0].val = INT_MAX;
		tot = 1;
	}

	int getNode(){
		// a[tot].l = a[tot].r = 0;
		return tot++;
	}

	void update(int &u, int l, int r, int L, int C){
		u = getNode();
		a[u].val = C;
		if (l + 1 == r)
			return;
		int m = l + r >> 1;
		if (L < m)
			update(a[u].l, l, m, L, C);
		else
			update(a[u].r, m, r, L, C);
	}

	void merge(int &u, int &v, int l, int r){
		if (!(u && v)){
			u = u | v;
			return;
		}
		int tu = u;
		u = getNode();
		a[u] = a[tu];
		mini(a[u].val, a[v].val);

		int m = l + r >> 1;
		merge(a[u].l, a[v].l, l, m);
		merge(a[u].r, a[v].r, m, r);
	}

	int query(int u, int l, int r, int L, int R){
		eput(u, l, r, L, R, a[u].val);
		if (L <= l && r <= R)
			return a[u].val;
		int m = l + r >> 1;
		return min(L < m ? query(a[u].l, l, m, L, R) : INT_MAX,
					m < R ? query(a[u].r, m, r, L, R) : INT_MAX);
	}
}

int n;
int a[N];
int dep[N], tree[N];
vector<int> E[N];

void DFS(int u, int pre){
	SGT::update(tree[u], 0, n, dep[u], a[u]);
	eput(u, pre, tree[u], SGT::a[tree[u]].val);
	eput(u, SGT::query(tree[u], 0, n, dep[u], dep[u] + 1));
	for (auto &v: E[u]){
		if (v == pre)
			continue;
		dep[v] = dep[u] + 1;
		DFS(v, u);
		SGT::merge(tree[u], tree[v], 0, n);
		eput(u, pre, tree[u], SGT::a[tree[u]].val);
	}
	eput(u, SGT::query(tree[u], 0, n, dep[u], dep[u] + 1));
}

int main(){
	int rt;
	scanf("%d%d", &n, &rt);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	SGT::init();
	dep[rt] = 0;
	DFS(rt, -1);
	
	int m, ans = 0;
	scanf("%d", &m);
	while (m--){
		int x, k;
		scanf("%d%d", &x, &k);
		x = (x + ans) % n + 1, k = min(n, dep[x] + (k + ans) % n + 1);
		printf("%d\n", ans = SGT::query(tree[x], 0, n, dep[x], k));
	}
	return 0;
}