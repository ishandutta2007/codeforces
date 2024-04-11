#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;
using LD = long double;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(n);
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];

	auto check = [&](LD w) {
		LD x = w + m;
		REP(i, n) {
			LD q = x / a[i];
			debug(i, a[i], x, q, w);
			x -= q;
			w -= q;
			if(w < 0) return false;
			int nxt = (i == n - 1 ? 0 : i + 1);
			q = x / b[nxt];
			debug(nxt, b[nxt], x, q, w);
			x -= q;
			w -= q;
			if(w < 0) return false;
		}
		return true;
	};

   	LD l = 0, r = 1e9 + 1;
	while(abs(l - r) > 1e-7) {
		LD _m = (l + r) / 2;
		if(check(_m)) 
			r = _m;
		else
			l = _m;
	}


	if(l >= 1e9) {
		cout << "-1\n";
		return 0;
	}
	cout << setprecision(10) << fixed;
	cout << l << "\n";
}