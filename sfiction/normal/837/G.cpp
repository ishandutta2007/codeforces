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

const int MAXN = 75000 + 10, MAXX = 2E5 + 10;

pll& operator +=(pll& a, const pll& b){
	a.st += b.st, a.nd += b.nd;
	return a;
}

pll operator +(const pll& a, const pll& b){
	pll ret(a);
	ret += b;
	return ret;
}

constexpr pll ZERO(0, 0);

struct SegmentTree{
	static const int N = ::MAXX, LOGN = 19;

	struct Node{
		int l, r;
		pll s;
	}a[N * 2 * LOGN];

	int limit, tot;	// set limit to control persistant

	int getNode(int u = 0){
		return u < limit ? (a[tot] = a[u], tot++) : u;
	}

	void update(int &u, pll c){
		u = getNode(u);
		a[u].s += c;
	}

	void update(int &u, int l, int r, int L, int R, pll c){
		u = getNode(u);
		if (L <= l && r <= R){
			update(u, c);
			eput(u, l, r, a[u].s);
			return;
		}
		int m = l + r >> 1;
		if (L < m)
			update(a[u].l, l, m, L, R, c);
		if (m < R)
			update(a[u].r, m, r, L, R, c);
	}

	pll query(int u, int l, int r, int L){
		if (l + 1 == r)
			return a[u].s;
		int m = l + r >> 1;
		return a[u].s + (L < m ? query(a[u].l, l, m, L) : query(a[u].r, m, r, L));
	}
}SGT;

int tree[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	int X = MAXX - 5;
	SGT.tot = 1;
	for (int i = 1; i <= n; ++i){
		int x1, x2, y1, y2, a, b;
		scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);
		++x1, ++x2;

		SGT.limit = SGT.tot;
		tree[i] = tree[i - 1];
		SGT.update(tree[i], 0, X, 0, x1, pll(y1, 0));
		SGT.update(tree[i], 0, X, x1, x2, pll(b, a));
		SGT.update(tree[i], 0, X, x2, X, pll(y2, 0));
	}

	ll ans = 0;
	const int M = 1E9;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		x = (ans + x) % M;
		pll a = SGT.query(tree[l - 1], 0, X, min(X - 1, x));
		pll b = SGT.query(tree[r], 0, X, min(X - 1, x));
		printf("%lld\n", ans = (b.nd - a.nd) * x + (b.st - a.st));
	}
	return 0;
}