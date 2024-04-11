#include<bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		LL ans = 0, sum = 0;
		REP(i, n) {
			cin >> a[i];
			if(i % 2 == 0) sum += a[i];
		}

		array<LL, 2> opt = {int(1e18), 0};
		LL pref = 0;
		REP(i, n) {
			if(i % 2 == 0) pref -= a[i];
			else pref += a[i];
			ans = max(ans, pref - opt[i % 2]);
			opt[i % 2] = min(opt[i % 2], pref);
	
			debug(i, pref, opt[0], opt[1], ans);
		}

		cout << ans + sum << "\n";
	}
}