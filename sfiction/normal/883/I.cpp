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

const int MAXN = 3E5 + 10;

int n, m;
int a[MAXN];
int s[MAXN];

int solve(int L){
	int res = 0;
	s[0] = 1;
	for (int j = 1, i = 1; i <= n; ++i){
		for (; a[i] - a[j] > L; ++j);
		int t = j - 1 <= i - m && s[i - m] - (j - 2 >= 0 ? s[j - 2] : 0);
		s[i] = s[i - 1] + t;
	}
	return s[n] - s[n - 1];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);

	int low = 0, high = 1e9, mid;
	while (low < high){
		mid = low + (high - low >> 1);
		if (solve(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n", low);
	return 0;
}