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

const int N = 1E4 + 10, M = 1E2 + 10;

int n, m, d;
int A[2];
char s[N];
int f[N][M], g[N][M];

int solve(int u, char *(&p)){
	eput(u, *p, p);
	if (isdigit(*p)){
		f[u][0] = g[u][0] = *p - '0';
		++p;
		return 0;
	}

	++p;
	int l = n++, r = n++, ret = 1;
	int nl, nr;
	ret += nl = solve(l, p);
	++p;
	ret += nr = solve(r, p);
	++p;

	eput(nl, nr, ret);

	for (int i = 0; i <= m && i <= ret; ++i){
		f[u][i] = 1 << 30, g[u][i] = -f[u][i];
		int t = i - (d == 0);
		for (int j = 0; j <= t; ++j){
			if (j > nl || t - j > nr)
				continue;
			mini(f[u][i], f[l][j] + f[r][t - j]);
			maxi(g[u][i], g[l][j] + g[r][t - j]);
		}
		t = i - (d == 1);
		for (int j = 0; j <= t; ++j){
			if (j > nl || t - j > nr)
				continue;
			mini(f[u][i], f[l][j] - g[r][t - j]);
			maxi(g[u][i], g[l][j] - f[r][t - j]);
		}

		eput(u, i, f[u][i], g[u][i]);
	}
	return ret;
}

int main(){
	scanf("%s", s);
	scanf("%d%d", A, A + 1);
	d = A[0] > A[1];
	m = A[d];
	char *p = s;
	solve(n++, p);
	printf("%d\n", g[0][A[d]]);
	return 0;
}