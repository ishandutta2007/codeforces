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

	int n;
	cin >> n;

	vector<int> a(n);
	REP(i, n) cin >> a[i];

	vector<vector<int>> dp(n, vector<int>(n));
	REP(len, n) REP(l, n - len) {
		int r = l + len;
		if(len == 0) dp[l][r] = a[l];
		else {
			dp[l][r] = -1;
			FOR(k, l, r - 1) {
				if(dp[l][k] != -1 && dp[l][k] == dp[k + 1][r])
					dp[l][r] = dp[l][k] + 1;
			}
		}
	}

	vector<int> pref(n + 1, n);
	pref[0] = 0;
	FOR(i, 1, n) {
		REP(j, i) if(dp[j][i - 1] != -1)
			pref[i] = min(pref[i], pref[j] + 1);
	}

	cout << pref[n] << "\n";
}