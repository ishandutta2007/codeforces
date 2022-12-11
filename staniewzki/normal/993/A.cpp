#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

void get_square(double &x, double &y, double &a) {
	x = 0, y = 0;
	vector<int> l(4), r(4);
	REP(i, 4) {
		cin >> l[i] >> r[i];
		x += l[i], y += r[i];
	}

	x /= 4, y /= 4;
	a = 0;
	REP(i, 4) a = max(a, x - l[i]);
}

double d(double x, double y) {
	x -= y;
	if(x < 0) return -x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<PII> used;
	double x, y, a;
	get_square(x, y, a);
	debug(x, y, a);
	FOR(i, -100, 100) FOR(j, -100, 100)
		if(d(i, x) <= a && d(j, y) <= a) used.emplace(i, j);
	get_square(x, y, a);
	debug(x, y, a);
	FOR(i, -100, 100) FOR(j, -100, 100) {
		if(d(i, x) + d(j, y) <= a && used.count({i, j})) {
				cout << "YES\n";
				return 0;
		}
	}

	cout << "NO\n";

}