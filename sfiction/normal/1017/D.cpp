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
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
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

const int N = 12, M = 5E5 + 10, K = 100;

int n, m, Q;
int w[N];
int a[1 << N], b[1 << N];
int c[1 << N][K + 1];

char s[20];

int getNum(){
	scanf("%s", s);
	int t = 0;
	for (int j = 0; j < n; ++j)
		t |= (s[j] == '1') << j;
	return t;
}

int main(){
	scanf("%d%d%d", &n, &m, &Q);
	a[0] = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", w + i);
		int l = 1 << i;
		for (int j = 0; j < l; ++j)
			a[l | j] = a[j], a[j] += w[i];
	}
	for (int i = 0; i < m; ++i)
		++b[getNum()];

	int n0 = 1 << n;
	for (int i = 0; i < n0; ++i){
		for (int j = 0; j < n0; ++j)
			if (a[j] <= K){
				c[i][a[j]] += b[i ^ j];
				eput(i, j, i ^ j, a[j], b[i ^ j], c[i][a[j]]);
			}
		partial_sum(c[i], c[i] + K + 1, c[i]);
	}

	for (int i = 0; i < Q; ++i){
		int t = getNum(), K;
		scanf("%d", &K);
		printf("%d\n", c[t][K]);
	}
	
	return 0;
}