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

	LL n, l;
	cin >> n >> l;

	vector<LL> c(n);
	REP(i, n) cin >> c[i];

	n = 35;
	c.resize(35, 1e18);
	FOR(i, 1, n - 1) c[i] = min(c[i], c[i - 1] * 2);
	LL ans = 0;
	vector<LL> pref(n);
	REP(i, n) {
		if(l & (1LL << i))
			ans += c[i];
		pref[i] = ans;
	}

	LL res = ans;
	for(int i = n - 1; i >= 1; i--)
		res = min(res, ans - pref[i - 1] + c[i]);

	cout << res << "\n";
}