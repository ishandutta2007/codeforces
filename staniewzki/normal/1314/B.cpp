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

vector<bool> is_fav;
vector<vector<int>> solve(int l, int r) {
	vector<vector<int>> ret(2, vector<int>(2, -1));
	ret[0][0] = 0;
	if(l + 1 == r) {
		if(is_fav[l] || is_fav[r]) ret[1][0] = 1, ret[0][1] = 1;
		if(is_fav[l] && is_fav[r]) ret[1][1] = 1;
		debug(l, r, ret[0], ret[1]);
		return ret;
	}
	int m = (l + r) / 2;
	auto left = solve(l, m), right = solve(m + 1, r);
	REP(a, 2) REP(b, 2) REP(p, 2) REP(q, 2) {
		if(left[a][b] == -1 || right[p][q] == -1) continue;
		int x = left[a][b] + right[p][q] + (a || p) + (b || q);
		if(a || p) {
			ret[1][0] = max(ret[1][0], x);
			if(b || q) ret[1][1] = max(ret[1][1], x + 1);
		}
		if(a || b || p || q)
			ret[0][1] = max(ret[0][1], x + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	is_fav.resize(1 << n);
	REP(i, k) {
		int x;
		cin >> x;
		is_fav[x - 1] = true;
	}

	int ans = 0;
	auto get = solve(0, (1 << n) - 1);
	REP(i, 2) REP(j, 2) 
		ans = max(ans, get[i][j]);
	if(k) ans++;

	cout << ans << "\n";
}