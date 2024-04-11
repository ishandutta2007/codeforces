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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(101);
	int sum = 0;
	int dif = 0;
	REP(i, n) 
	{
		cin >> a[i];
		sum += a[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
	dp[0][0] = 1;
	REP(i, n)
	{
		for(int j = n; j > cnt[a[i]]; j--) for(int k = a[i]; k <= sum; k++)
		{
			if(dp[j][k] >= 2) continue;
			if(dp[j - 1][k - a[i]]) dp[j][k]++;
		}
		if(cnt[a[i]] == 0) dif++;
		cnt[a[i]]++;
	}

	if(dif == 1 || dif == 2)
	{
		cout << n << "\n";
		return 0;
	}

	int ans = 0;
	FOR(x, 1, 100)
	{
		FOR(k, 1, cnt[x])
		{
			int m = k * x;
			if(dp[k][m] == 1)
				ans = max(ans, k);
		}
	}

	cout << ans << "\n";
}