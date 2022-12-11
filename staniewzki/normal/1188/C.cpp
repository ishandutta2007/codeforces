#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

template<class T> int size(T && a) {
	return a.size();
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

mt19937_64 _gen(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(_gen); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	sort(a.begin(), a.end());

	int mod = 998244353;
	auto add = [&](int a, int b) { 
		int ret = a + b;
		while(ret >= mod) ret -= mod;
		return ret;
	};

	auto get = [&](int x) {
		vector<int> last(n);
		int l = -1, r = 0;
		while(r < n) {
			while(l + 1 < r && a[r] - a[l + 1] >= x) l++;
			last[r++] = l;
		}

		debug(x, last);

		vector<vector<int>> dp(2, vector<int>(n));
		vector<int> sums(n);
		REP(i, n) dp[0][i] = 1;
		FOR(i, 2, k) {
			REP(j, n) {
				sums[j] = add((j != 0 ? sums[j - 1] : 0), dp[0][j]);
				dp[1][j] = (last[j] != -1 ? sums[last[j]] : 0);
				debug(i, j, dp[1][j]);
			}

			swap(dp[0], dp[1]);
		}

		int ret = 0;
		REP(i, n) ret = add(ret, dp[0][i]);
		return ret;
	};

	int max_beauty = 1e5 / (k - 1);
	int ans = 0;
	FOR(i, 1, max_beauty)
		ans = add(ans, get(i));

	cout << ans << "\n";
}