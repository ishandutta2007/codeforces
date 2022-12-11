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

	int t;
	cin >> t;
	REP(_t, t) {
		int n, m;
		cin >> n >> m;
		vector<int> ile(n + 1);
		vector<vector<int>> f(m);
		vector<int> ans(m);
		REP(i, m) {
			int k;
			cin >> k;
			f[i].resize(k);
			for(int &x : f[i])
				cin >> x;
			ile[f[i][0]]++;
			ans[i] = f[i][0];
		}

		pair<int, int> opt = {-1, -1};
		REP(i, n + 1) {
			debug(i, ile[i]);
			opt = max(opt, {ile[i], i});
		}

		int q = (m + 1) / 2;
		int left = max(opt.first - q, 0);
		REP(i, m) {
			if(f[i][0] == opt.second && left) {
				if(size(f[i]) > 1) {
					ans[i] = f[i][1];
					left--;
				}
			}
		}

		if(left) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		REP(i, m)
			cout << ans[i] << " ";
		cout << "\n";
	}
}