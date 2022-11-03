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

int query(int x){
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main(){
	int n;
	scanf("%d", &n);
	if ((n / 2) & 1){
		puts("! -1");
		return 0;
	}

	int nt = n / 2;
	int l = 1, r = nt + 1;
	int val[2] = {query(l), query(r)};
	if (val[0] == val[1]){
		printf("! %d\n", 1);
		return 0;
	}

	int lv = val[0] < val[1], rv = !lv;
	while (l + 1 < r){
		int m = l + r >> 1;
		int mval[2] = {query(m), query(nt + m)};
		if (mval[0] == mval[1]){
			printf("! %d\n", m);
			return 0;
		}

		int mv = mval[0] < mval[1];
		if (lv != mv)
			r = m, rv = mv;
		else
			l = m, lv = mv;
	}
	puts("! -1");
	return 0;
}