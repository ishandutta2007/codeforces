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

const int s = 1200000;
bitset<s + 1> dp[51][25];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;
	cin >> n;
	vector<int> a(n * 2);
	REP(i, n * 2) cin >> a[i];
	sort(a.begin(), a.end());
	dp[n * 2][0][0] = true;
	for(int i = n * 2 - 1; i >= 2; i--) {
		sum += a[i];
		for(int j = n - 1; j >= 1; j--)
			dp[i][j] = dp[i + 1][j] | (dp[i + 1][j - 1] << a[i]);
		dp[i][0] = dp[i + 1][0];
	}
	int ans = 1e9, id = -1, pos = 2;
	FOR(i, 0, s) if(dp[2][n - 1][i] && ans > max(i, sum - i))
		ans = max(i, sum - i), id = i;
	vector<bool> used(n * 2);
	for(int j = n - 1; j >= 1; j--) {
		while(ans < a[pos] || !dp[pos + 1][j - 1][ans - a[pos]]) pos++;
		used[pos] = true, ans -= a[pos++];
	}
	vector<int> top = {a[0]}, bot = {a[1]};
	FOR(i, 2, n * 2 - 1) {
		if(used[i]) top.emplace_back(a[i]);
		else bot.emplace_back(a[i]);
	}
	REP(i, n) cout << top[i] << " ";
	cout << "\n";
	for(int i = n - 1; i >= 0; i--) cout << bot[i] << " ";
	cout << "\n";
}