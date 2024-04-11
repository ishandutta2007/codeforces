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

	LL n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<LL> a(n), b(m);
	REP(i, n) cin >> a[i];
	REP(i, m) cin >> b[i];

	if(n <= k) {
		cout << "-1\n";
		return 0;
	}

	LL ans = 0, pos = 0;
	REP(i, n) {
		LL q = a[i] + ta, x = k - i;
		if(x < 0) break;
		while(pos < size(b) && b[pos] < q) pos++;
		debug(i, pos);
		if(pos + x >= size(b)) {
			cout << "-1\n";
			return 0;
		}
		ans = max(ans, b[pos + x] + tb);
	}
	cout << ans << "\n";
}