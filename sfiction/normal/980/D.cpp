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

const int N = 5E3 + 10;

int n;
int a[N];
int mark[N];
int ans[N];
map<int, int> lst;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if (a[i] == 0)
			continue;

		int res = a[i] > 0 ? 1 : -1, t = res * a[i];
		for (int j = 2; j * j <= t; ++j)
			if (t % j == 0){
				bool flag = true;
				t /= j;
				for (; t % j == 0; t /= j, flag = !flag);
				if (flag)
					res *= j;
			}
		res *= t;
		if (lst.find(res) == lst.end())
			lst.emplace(res, lst.size() + 1);
		a[i] = lst[res];
	}

	for (int i = 1; i <= n; ++i){
		int cnt = 0;
		fill_n(mark + 1, n, 0);
		for (int j = i; j <= n; ++j){
			cnt += a[j] != 0 && ++mark[a[j]] == 1;
			++ans[max(1, cnt)];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}