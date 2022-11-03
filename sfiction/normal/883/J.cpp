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

const int N = 1E5 + 10;

pii b[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	typedef pair<int, ll> pil;
	vector<pil> a;
	for (int i = 0; i < n; ++i){
		int t;
		scanf("%d", &t);
		ll s = 0;
		for (; !a.empty() && a.back().st <= t; a.pop_back())
			s += a.back().nd;
		a.emplace_back(t, s + t);
	}
	a.emplace_back(0, 0);

	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i].st);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i].nd);
	sort(b, b + m, greater<pii>());

	priority_queue<int> Q;
	int k = 0;
	for (; k < m && b[k].st > a[0].st; ++k);
	ll s = 0;
	for (int i = 0; i < a.size() - 1; ++i){
		s += a[i].nd;
		for (; k < m && b[k].st > a[i + 1].st; ++k)
			if (b[k].nd <= s){
				s -= b[k].nd;
				Q.emplace(b[k].nd);
			}
			else if (!Q.empty() && b[k].nd <= Q.top()){
				s += Q.top() - b[k].nd;
				Q.pop();
				Q.emplace(b[k].nd);
			}
	}
	printf("%d\n", (int)Q.size());
	return 0;
}