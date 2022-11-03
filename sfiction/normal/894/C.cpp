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

const int N = 1E3 + 10;

int a[N];

int main(){
	int n;
	scanf("%d", &n);
	int t = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", a + i);
		t = t == 0 ? a[i] : __gcd(t, a[i]);
	}
	if (t != *min_element(a, a + n))
		puts("-1");
	else{
		printf("%d\n", n << 1 | 1);
		for (int i = 0; i < n; ++i)
			printf("%d %d ", t, a[i]);
		printf("%d\n", t);
	}
	return 0;
}