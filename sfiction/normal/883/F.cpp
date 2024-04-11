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

int main(){
	int n;
	cin >> n;
	set<string> lst;
	for (int i = 0; i < n; ++i){
		string s, ts;
		cin >> s;
		for (auto &t: s){
			if (t == 'u')
				ts.push_back('o'), ts.push_back('o');
			else if (t == 'h'){
				while (!ts.empty() && ts.back() == 'k')
					ts.pop_back();
				ts.push_back('h');
			}
			else
				ts.push_back(t);
		}
		lst.emplace(ts);
	}
	printf("%d\n", (int)lst.size());
	return 0;
}