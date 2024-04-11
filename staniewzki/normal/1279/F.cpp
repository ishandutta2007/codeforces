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

	int n, k, d;
	cin >> n >> k >> d;

	vector<int> a(n + 1);
	FOR(i, 1, n) {
		char c; cin >> c;
		a[i] = ('a' <= c && c <= 'z');
	}

	LL ans = n;
	REP(q, 2) {
		auto get = [&](LL cost) {
			vector<pair<LL, int>> dp(n + 1);
			FOR(i, 1, n) {
				int p = max(i - d, 0);
				auto x = dp[i - 1];
				auto y = dp[p];
				x.ST += a[i];
				y.ST += cost;
				y.ND++;
				dp[i] = min(x, y);
			}
			return dp[n];
		};

		LL l = 0, r = 1e9;
		while(l < r) {
			LL m = (l + r) / 2;
			if(get(m).ND <= k) 
				r = m;
			else
				l = m + 1;
		}

		auto x = get(l);
		ans = min(ans, x.ST - k * l);
		FOR(i, 1, n) a[i] ^= 1;
	}

	cout << ans << "\n";
}