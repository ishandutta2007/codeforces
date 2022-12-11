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

	int h, w;
	cin >> h >> w;

	vector<string> input(h);
	REP(i, h) cin >> input[i];

	int inf = 1e8;
	vector dst(h + 1, vector(w + 1, inf));
	REP(i, w + 1) dst[h][i] = inf + 100;
	REP(i, h) dst[i][w] = inf + 100;

	for(int i = h - 1; i >= 0; i--) {
		for(int j = w - 1; j >= 0; j--) {
			if(input[i][j] == '*')
				dst[i][j] = 0;
			dst[i][j] = min({dst[i][j], dst[i + 1][j] + 1, dst[i][j + 1] + 1});
		}
	}

	int x = 0, y = 0, ans = 0;
	while(true) {
		debug(x, y);
		if(dst[x][y] == 0)
			ans++;
		if(x == h - 1 && y == w - 1)
			break;
		debug(dst[x + 1][y], dst[x][y + 1]);
		if(dst[x + 1][y] < dst[x][y + 1])
			x++;
		else
			y++;
	}

	cout << ans << "\n";
}