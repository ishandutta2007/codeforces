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

	int size = 15000000;
	vector<int> divisor(size + 1);
	vector<int> cnt(size + 1);
	for(int i = 2; i * i <= size; i++)
	{
		if(divisor[i] == 0)
		{
			for(int j = i * i; j <= size; j += i)
				divisor[j] = i;
		}
	}

	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n)
		cin >> a[i];

	int gcd = a[0];
	REP(i, n) gcd = __gcd(gcd, a[i]);
	REP(i, n) a[i] /= gcd;

	int ans = 0;
	REP(i, n)
	{
		while(a[i] != 1)
		{
			int p = (divisor[a[i]] == 0 ? a[i] : divisor[a[i]]);
			debug(a[i], p);
			cnt[p]++;
			ans = max(ans, cnt[p]);
			while(a[i] % p == 0) a[i] /= p;
		}
	}

	if(ans == 0) ans = n + 1;
	cout << n - ans << "\n";
}