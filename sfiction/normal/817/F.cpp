#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

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

const int MAXN = 2E5 + 10;

struct SegmentTree{
	static const int MAXN = ::MAXN;

	struct node{
		int s, s0;
		int _rev, _set;

		void rev(){
			if (~_set)
				_set ^= 1, _rev = 0;
			else
				_rev ^= 1;
			s = s0 - s;
		}

		void set(int c){
			_set = c;
			s = c * s0;
		}
	}a[MAXN << 2];

	void pushDown(int u){
		if (~a[u]._set){
			a[u << 1].set(a[u]._set);
			a[u << 1 | 1].set(a[u]._set);
			a[u]._set = -1, a[u]._rev = 0;
			return;
		}
		if (a[u]._rev){
			a[u << 1].rev();
			a[u << 1 | 1].rev();
			a[u]._rev = 0;
		}
	}

	void pushUp(int u){
		a[u].s = a[u << 1].s + a[u << 1 | 1].s;
	}

	void build(int u, int l, int r){
		a[u] = (node){0, r - l, 0, -1};
		if (l + 1 == r)
			return;
		int m = l + r >> 1;
		build(u << 1, l, m);
		build(u << 1 | 1, m, r);
		pushUp(u);
	}

	void reverse(int u, int l, int r, int L, int R){
		if (L <= l && r <= R){
			a[u].rev();
			return;
		}
		pushDown(u);
		int m = l + r >> 1;
		if (L < m)
			reverse(u << 1, l, m, L, R);
		if (m < R)
			reverse(u << 1 | 1, m, r, L, R);
		pushUp(u);
	}

	void update(int u, int l, int r, int L, int R, int C){
		if (L <= l && r <= R){
			a[u].set(C);
			return;
		}
		pushDown(u);
		int m = l + r >> 1;
		if (L < m)
			update(u << 1, l, m, L, R, C);
		if (m < R)
			update(u << 1 | 1, m, r, L, R, C);
		pushUp(u);
	}

	int query(int u, int l, int r){
		if (l + 1 == r)
			return l;
		pushDown(u);
		int m = l + r >> 1;
		return a[u << 1].s < a[u << 1].s0 ? query(u << 1, l, m) : query(u << 1 | 1, m, r);
	}
}SGT;

int type[MAXN];
ll a[MAXN], b[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	vector<ll> c(1, 1);
	for (int i = 0; i < n; ++i){
		scanf("%d%lld%lld", type + i, a + i, b + i);
		c.push_back(a[i]);
		c.push_back(b[i] + 1);
	}
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	int m = c.size();
	SGT.build(1, 0, m);
	for (int i = 0; i < n; ++i){
		int l = lower_bound(all(c), a[i]) - c.begin();
		int r = lower_bound(all(c), b[i] + 1) - c.begin();

		if (type[i] == 3)
			SGT.reverse(1, 0, m, l, r);
		else
			SGT.update(1, 0, m, l, r,  2 - type[i]);
		printf("%lld\n", c[SGT.query(1, 0, m)]);
	}
	return 0;
}