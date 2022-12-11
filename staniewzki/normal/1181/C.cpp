#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define ST first
#define ND second
#define EB emplace_back
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
template<class T> int size(T &&x) {
	return int(x.size());
}
#ifdef DEBUG
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	vector<vector<char>> a(n, vector<char>(m));
	REP(i, m) REP(j, n)
		cin >> a[j][i];

	vector<vector<LL>> dp(n, vector<LL>(m));
	LL ans = 0;
	REP(i, n)
	{
		int q = 1;
		vector<int> len;
		FOR(j, 1, m)
		{
			if(j == m || a[i][j - 1] != a[i][j])
				len.EB(q), q = 0;
			q++;
		}

		debug(i, len);

		int sum = len[0];
		FOR(j, 1, size(len) - 2)
		{
			debug(i, sum);
			if(len[j - 1] < len[j] || len[j] > len[j + 1]) { sum += len[j]; continue; }
			if(i != 0)
			{
				int l = sum - len[j];
				int r = sum + 2 * len[j] - 1;
				bool ok = true;
				FOR(j, l, r)
					if(a[i - 1][j] != a[i][j])
						ok = false;
				if(ok) dp[i][sum] = dp[i - 1][sum] + 1;
				else dp[i][sum] = 1;
			}
			else dp[i][sum] = 1;
			ans += dp[i][sum];
			sum += len[j];
		}
	}

	cout << ans << "\n";
}