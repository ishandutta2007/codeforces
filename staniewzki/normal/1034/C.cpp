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
	REP(i, n) 
		cin >> a[i];

	vector<int> p(n);
	FOR(i, 1, n - 1)
		cin >> p[i];

	vector<LL> sum(n);
	for(int i = n - 1; i >= 0; i--) {
		sum[i] += a[i];
		if(i) sum[p[i] - 1] += sum[i];
	}

	vector<int> k(n + 1);
	REP(i, n) {
		// s[i] % (S / (q * x)) == 0
		LL q = sum[0] / __gcd(sum[0], sum[i]);
		if(q <= n) k[q]++;
		debug(i, sum[i], q);
	}

	vector<int> cnt(n + 1);
	FOR(i, 1, n) if(k[i]) {
		for(int j = i; j <= n; j += i)
			cnt[j] += k[i];
	}

	vector<bool> good_split(n + 1);
	FOR(i, 1, n)
	{
		if(cnt[i] == i) good_split[i] = true;
		debug(i, cnt[i], good_split[i]);
	}

	vector<int> ans(n + 1);
	for(int i = n; i >= 1; i--)
	{
		if(!good_split[i]) continue;
		ans[i] = 1;
		for(int j = i * 2; j <= n; j += i)
			ans[i] += ans[j];
	}

	cout << ans[1]  << "\n";
}