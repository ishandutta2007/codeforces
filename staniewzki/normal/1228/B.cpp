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

	int h, w;
	cin >> h >> w;
	vector<vector<int>> state(h, vector<int>(w, -1));

	REP(i, h) {
		int x;
		cin >> x;
		REP(j, x)
			state[i][j] = 1;
		if(x < w) state[i][x] = 0;
	}

	REP(j, w) {
		int x;
		cin >> x;
		REP(i, x) {
			if(state[i][j] == 0) {
				cout << "0\n";
				return 0;
			}
			state[i][j] = 1;
		}
		if(x < h) {
			if(state[x][j] == 1) {
				cout << "0\n";
				return 0;
			}
			state[x][j] = 0;
		}
	}

	int ans = 1;
	int mod = 1e9 + 7;

	REP(i, h) REP(j, w)
		if(state[i][j] == -1)
			ans = ans * 2 % mod;

	cout << ans << "\n";
}