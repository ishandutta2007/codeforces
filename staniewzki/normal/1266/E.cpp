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

	int n; cin >> n;
	vector<int> a(n + 1), c(n + 1);
	LL ans = 0;
	FOR(i, 1, n) cin >> a[i], ans += a[i];
	int q; cin >> q;
	map<PII, int> m;
	REP(i, q) {
		int s, t, u;
		cin >> s >> t >> u;
		PII p = {s, t};
		if(m[p] != 0) {
			if(c[m[p]] <= a[m[p]]) ans++;
			c[m[p]]--;
		}
		m[p] = u;
		if(m[p] != 0) {
			c[m[p]]++;
			if(c[m[p]] <= a[m[p]]) ans--;
		}
		cout << ans << "\n";
	}
}