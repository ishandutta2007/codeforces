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
 
mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) {
	return uniform_int_distribution<int>(a, b)(_gen);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
 
	REP(_t, t) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> v(n, vector<int>(m));
		REP(i, n) REP(j, m) cin >> v[i][j];
 
		vector<int> ord(m);
		vector<int> mx(m);
		REP(j, m) {
			ord[j] = j;
			REP(i, n)
				mx[j] = max(mx[j], v[i][j]);
		}
 
		sort(ord.begin(), ord.end(), [&](int a, int b) { return mx[a] > mx[b]; });
 
		vector<int> rev;
		REP(i, min(n, m))
			rev.emplace_back(ord[i]);
 
		vector<vector<int>> t(n, vector<int>(size(rev)));
		REP(i, n) REP(j, size(rev))
			t[i][j] = v[i][rev[j]];

		m = size(rev);

		int p = (1 << n);
		vector<vector<int>> dp(m, vector<int>(p));
		vector<vector<int>> sum(m, vector<int>(p));
		auto mymod = [&](int val) { if(val >= n) return val - n; return val; };

		REP(j, m) {
			REP(k, p) {
				REP(r, n) {
					int sumka = 0;
					REP(i, n) {
						if(k & (1 << mymod(i + r)))
							sumka += t[i][j];
					}
					sum[j][k] = max(sum[j][k], sumka);
				}
				debug(j, k, sum[j][k]);
			}
		}

		REP(j, m) {
			if(j != 0) dp[j] = dp[j - 1];
			REP(k, p) {
				if(j == 0)
					dp[j][k] = sum[j][k];
				else {
					for(int l = k; l > 0; l = (l - 1) & k) {
						dp[j][k] = max(dp[j][k], dp[j - 1][k ^ l] + sum[j][l]);
					}
				}
			}

			debug(dp[j]);
		}

		cout << dp[m - 1][p - 1] << "\n";
	}
 
}