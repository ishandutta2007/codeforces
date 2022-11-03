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

const int N = 2E5 + 10;
const ll MOD = 1E9 + 7;

int n;
vector<int> E[N];
ll a[N];
ll size[N], s1[N];

ll ans;

void DFS(int u, int pre){
	size[u] = 1;
	s1[u] = 1;
	ans = (ans + n * a[u]) % MOD;
	for (auto &v: E[u]){
		if (v == pre)
			continue;
		DFS(v, u);
		size[u] += size[v];
		s1[u] += -s1[v];

		ans = (ans + -s1[v] * (n - size[v]) % MOD * a[u]) % MOD;
	}
}

void DFS2(int u, int pre, ll ups){
	ans = (ans + -ups * size[u] % MOD * a[u]) % MOD;
	for (auto &v: E[u]){
		if (v == pre)
			continue;
		DFS2(v, u, s1[u] + s1[v] - ups);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	for (int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	DFS2(1, 0, 0);
	printf("%lld\n", (ans + MOD) % MOD);

	return 0;
}