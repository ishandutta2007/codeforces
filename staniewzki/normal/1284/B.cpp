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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	LL n;
	cin >> n;
	LL bad = 0;
	vector<int> c1(1e6 + 1);
	auto c2 = c1;
	LL q = 0;
	REP(i, n) {
		int l;
		cin >> l;
		int mn = 1e6 + 1, mx = 0;
		bool ok = false;
		REP(j, l) {
			int s;
			cin >> s;
			if(s > mn) ok = true;
			mn = min(mn, s);
			mx = max(mx, s);
			debug(i, j, s);
		}
		debug(i, ok, mn, mx);
		bad += ok;
		if(!ok) {
			c1[mn]++;
			c2[mx]++;
		}
	}

	LL ans = (LL) n * bad + LL(n - bad) * bad;
	debug(ans);

	LL sum = 0;
	FOR(i, 0, 1e6) {
		if(i <= 9) debug(i, sum, c1[i], c2[i]);
		ans += sum * c2[i];
		sum += c1[i];
	}

	debug(q);

	cout << ans + q << "\n";
}