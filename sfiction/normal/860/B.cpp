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

int a[80000];
vector<int> b[8];
map<int, int> c[10];

int e[10];

int main(){
	e[0] = 1;
	for (int i = 1; i < 10; ++i)
		e[i] = e[i - 1] * 10;
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 7; ++i)
		b[i].assign(e[i], 0);

	set<int> lst;
	for (int i = 0; i < n; ++i){
		scanf("%d", a + i);
		for (int j = 9; j >= 8; --j){
			lst.clear();
			for (int k = 9 - j; k >= 0; --k)
				lst.insert(a[i] / e[k] % e[j]);
			for (auto t: lst)
				++c[j][t];
		}
		for (int j = 7; j >= 1; --j){
			lst.clear();
			for (int k = 9 - j; k >= 0; --k)
				lst.insert(a[i] / e[k] % e[j]);
			for (auto t: lst)
				++b[j][t];
		}
	}

	for (int i = 0; i < n; ++i){
		int t;
		for (int j = 1; j <= 7; ++j)
			for (int k = 9 - j; k >= 0; --k)
				if (b[j][t = a[i] / e[k] % e[j]] == 1){
					printf("%0*d\n", j, t);
					goto end;
				}
		for (int j = 8; j <= 9; ++j){
			for (int k = 9 - j; k >= 0; --k)
				if (c[j][t = a[i] / e[k] % e[j]] == 1){
					printf("%0*d\n", j, t);
					goto end;
				}
		}
end:
		t = 3;
	}
	return 0;
}