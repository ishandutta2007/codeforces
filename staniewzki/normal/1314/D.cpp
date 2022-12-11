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

int n, k;
vector<vector<int>> cost;
vector<vector<vector<PII>>> opt;

vector<int> chosen, ord;

LL ans = 1e18;
void solve(int left) {
	if(left == 0) {
		ord.emplace_back(0);

		LL sum = 0;
		FOR(i, 1, size(ord) - 1) {
			int x = ord[i - 1];
			int y = ord[i];
			
			int pos = 0;
			while(chosen[opt[x][y][pos].ND]) {
				pos++;
				if(pos == size(opt[x][y])) {
					ord.pop_back();
					return;
				}
			}

			sum += opt[x][y][pos].ST;
		}

		ans = min(ans, sum);

		ord.pop_back();
		return;
	}

	REP(i, n) {
		chosen[i]++;
		ord.emplace_back(i);
		solve(left - 1);	
		ord.pop_back();
		chosen[i]--;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cost.resize(n, vector<int>(n));
	REP(i, n) REP(j, n) {
		cin >> cost[i][j];		
	}

	opt.resize(n, vector<vector<PII>>(n));
	REP(i, n) REP(j, n) {
		REP(m, n) opt[i][j].emplace_back(cost[i][m] + cost[m][j], m);
		sort(opt[i][j].begin(), opt[i][j].end());
	}

	chosen.resize(n);
	chosen[0] = 1;
	ord = {0};
	solve(k / 2 - 1);

	cout << ans << "\n";
}