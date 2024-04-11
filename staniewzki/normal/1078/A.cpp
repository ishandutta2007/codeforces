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

	long double a, b, c;
	long double x1, y1, x2, y2;
	cin >> a >> b >> c;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << setprecision(10) << fixed;
	if(a == 0 || b == 0)
	{
		cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
		return 0;
	}
	long double X1 = (b * y1 + c) / a * -1;
	long double Y1 = (a * x1 + c) / b * -1;
	long double X2 = (b * y2 + c) / a * -1;
	long double Y2 = (a * x2 + c) / b * -1;
	auto get_x1 = [&](int i){ return (i == 0 ? x1 : X1); };
	auto get_y1 = [&](int i){ return (i == 1 ? y1 : Y1); };
	auto get_x2 = [&](int i){ return (i == 0 ? x2 : X2); };
	auto get_y2 = [&](int i){ return (i == 1 ? y2 : Y2); };

	long double ans = abs(x1 - x2) + abs(y1 - y2);
	REP(i, 2) REP(j, 2)
	{
		long double _x1 = get_x1(i);
		long double _y1 = get_y1(i);
		long double _x2 = get_x2(j);
		long double _y2 = get_y2(j);
		long double dist = sqrt((_x1 - _x2) * (_x1 - _x2) + (_y1 - _y2) * (_y1 - _y2));
		dist += abs(x1 - _x1) + abs(y1 - _y1) + abs(x2 - _x2) + abs(y2 - _y2);
		debug(_x1, _y1, _x2, _y2, dist);
		ans = min(ans, dist);
	}

	cout << ans << "\n";
}