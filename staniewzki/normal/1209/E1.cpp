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

		debug(rev);
		int ans = 0;

		vector<int> mv(m);
		function<void(int)> solve = [&](int x) {
			if(x == size(rev)) {
				int sum = 0;
				REP(i, n) {
					int _mx = 0;
					REP(j, m)
						_mx = max(_mx, v[(i + mv[j]) % n][j]);
					sum += _mx;
				}
				ans = max(ans, sum);
				return;
			}

			REP(i, n) {
				mv[rev[x]] = i;
				solve(x + 1);
			}
		};

		solve(0);
		cout << ans << "\n";
	}

}