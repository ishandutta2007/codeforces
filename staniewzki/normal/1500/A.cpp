#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> a(n);
	REP(i, n) 
		cin >> a[i];

	vector<vector<pair<int, int>>> opt(5e6 + 1);
	REP(j, n) REP(i, j) {
		int sum = a[i] + a[j];
		for(auto &[x, y] : opt[sum]) {
			if(i == x || i == y || j == x || j == y)
				continue;
			cout << "YES\n";
			cout << x + 1 << " " << y + 1 << " " 
				 << i + 1 << " " << j + 1 << "\n";
			return 0;
		}
		opt[sum].emplace_back(i, j);
	}

	cout << "NO\n";
}