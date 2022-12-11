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

	LL n, m;
	cin >> n >> m;
	if(n > m) swap(n, m);
	if(n == 1)
	{
		LL ans = m - (m % 6);
		if(m % 6 == 4) ans += 2;
		if(m % 6 == 5) ans += 4;
		cout << ans << "\n";
		return 0;
	}
	else if(n == 2)
	{
		LL ans = 0;
		if(m <= 2) ans = 0;
		else if(m == 3) ans = 4;
		else if(m == 7) ans = 12;
		else ans = n * m;
		cout << ans << "\n";
	}
	else if(n % 2 == 0 || m % 2 == 0)
		cout << n * m << "\n";
	else cout << n * m - 1 << "\n";
}