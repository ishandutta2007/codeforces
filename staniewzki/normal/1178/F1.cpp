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

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];

	int mod = 998244353;
	auto mul = [&](int a, int b) -> int { return (LL) a * b % mod; };
	auto add = [&](int a, int b) { a += b; return a < mod ? a : a - mod; };
	vector<vector<int>> dp(n, vector<int>(n, -1));
	function<int(int, int)> get_dp = [&](int l, int r) {
		if(l > r) return 1;
		int &v = dp[l][r];	
		if(v != -1) return v;

		int mn = l;
		FOR(i, l, r) if(a[i] < a[mn]) mn = i;

		int left = get_dp(l, mn - 1);
		int right = get_dp(mn + 1, r);
		FOR(x, l, mn - 1) left = add(left, mul(get_dp(l, x), get_dp(x + 1, mn - 1)));
		FOR(x, mn + 1, r) right = add(right, mul(get_dp(x, r), get_dp(mn + 1, x - 1)));
		return v = mul(left, right);
	};
	
	cout << get_dp(0, n - 1) << "\n";
}