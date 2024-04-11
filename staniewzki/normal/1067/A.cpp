#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == --x.end() ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#ifdef DEBUG
  const int seed = 1;
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (#x != "" ? #x ":  " : ""), dump(x), Nl(), cerr
#else
  const int seed = chrono::system_clock::now().time_since_epoch().count();
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(seed);
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

const int N = 1e5;
const int A = 200;
int dp[N][A + 1][2];
int sum[N][A + 1][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	 cin >> n;

	vector<int> a(n);
	int mod = 998244353;
	auto fix = [&](int &val) {
		while(val < 0) val += mod;
		while(val >= mod) val -= mod;
	};

	REP(i, n)
	{
		cin >> a[i];
		if(i == 0) {
			FOR(j, 1, A) {
				if(j == a[i] || a[i] == -1) dp[i][j][0] = 1;
				sum[i][j][0] = sum[i][j - 1][0] + dp[i][j][0];
			}
			continue;
		}

		FOR(j, 1, A) {
			if(j == a[i] || a[i] == -1) {
				dp[i][j][0] = sum[i - 1][j - 1][0] + sum[i - 1][j - 1][1];
				dp[i][j][1] = sum[i - 1][A][1] - sum[i - 1][j - 1][1] + dp[i - 1][j][0];
			}

			REP(x, 2) {
				fix(dp[i][j][x]);
				sum[i][j][x] = (sum[i][j - 1][x] + dp[i][j][x]) % mod;
				fix(sum[i][j][x]);
			}

		}
	}

	cout << sum[n - 1][A][1] << "\n";
}