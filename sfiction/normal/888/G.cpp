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

const int N = 2E5 + 10, D = 30;

int n;
int a[N];
int cnt[N][D];

struct Trie{
	static const int NN = ::N, S = 2;
	int tot = 0, child[N * ::D][S];
	
	int getNode(){
		fill_n(child[tot], S, -1);
		return tot++;
	}

	void init(){
		tot = 0;
		getNode();
	}

	void insert(int x, int d){
		int u = 0;
		for (; d >= 0; --d){
			int v = x >> d & 1;
			if (!~child[u][v])
				child[u][v] = getNode();
			u = child[u][v];
		}
	}

	int query(int x, int d){
		int u = 0, ret = 0;;
		for (; d >= 0; --d){
			int v = x >> d & 1;
			if (~child[u][v])
				u = child[u][v];
			else{
				ret |= 1 << d;
				u = child[u][!v];
			}
		}
		return ret;
	}
}Trie;

ll solve(int l, int r, int d){
	if (l + 1 == r)
		return 0;

	int m;
	for (; d >= 0 && ((m = cnt[r - 1][d] - cnt[l - 1][d]) == 0 || m == r - l); --d);
	if (d < 0)
		return 0;

	eput(l, r, d);

	m = r - m;
	ll ret = solve(l, m, d - 1) + solve(m, r, d - 1);

	Trie.init();
	int t = INT_MAX;
	for (int i = l; i < m; ++i)
		Trie.insert(a[i], d - 1);
	for (int i = m; i < r; ++i)
		mini(t, Trie.query(a[i], d - 1));
	return ret += t | 1 << d;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < D; ++j)
			cnt[i][j] = cnt[i - 1][j] + (a[i] >> j & 1);
	}
	printf("%lld\n", solve(1, n + 1, D - 1));
	return 0;
}