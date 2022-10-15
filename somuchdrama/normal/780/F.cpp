#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using std::cin;
using std::cout;
using std::cerr;
using std::min;
using std::max;
using std::abs;
using std::pair;
using std::swap;
using std::vector;
using std::set;
using std::map;
using std::string;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
	vector<string> _v;\
	string _cur, _loc;\
	std::stringstream _ss(#as);\
	while (getline(_ss, _cur, ',')) {\
		while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
			getline(_ss, _loc, ',');\
			_cur += _loc;\
		}\
		_v.pb(_cur);\
	}\
	err(_v.begin(), as);\
}
#else
#define dbg(as...) {}
#endif

struct init{
	init() {
		std::iostream::sync_with_stdio(0);
		cin.tie(0);
		cout << std::fixed << std::setprecision(10);
		cerr << std::fixed << std::setprecision(10);
		srand(123);
	}
	~init() {
		#ifdef LOCAL
		cerr << "Time elapsed: " << clock() * 1.0 / CLOCKS_PER_SEC << " s.\n";
		#endif
	}
} init;

template<typename T> 
void err(vector<string>::iterator it, T a) {
	cerr << *it << " = " << a << '\n';
} 
template<typename...Ts, typename T>
void err(vector<string>::iterator it, T a, Ts...as) {
	cerr << *it << " = " << a << ",";
	err(++it, as...);
} 

#ifdef LOCAL
const int MAXN = 7, MAXB = 5;
#else
const int MAXN = 501, MAXB = 62;
#endif
std::bitset<MAXN> dp[2][MAXB][MAXN];
int n, m;
ll res[2][MAXB][MAXN];
bool used[2][MAXB][MAXN];

ll dfs(int j, int i, int v) {
	dbg(j, i, v);
	if (used[j][i][v]) return res[j][i][v];
	ll ans = 0;
	used[j][i][v] = true;
	for (int lvl = i; lvl; --lvl) {
		dbg(lvl, dp[j][lvl][v], dp[j][lvl][v][2]);
		bool f = false;
		for (int to = 1; to <= n; ++to) {
			dbg(to, lvl, dp[j][lvl][v], dp[j][lvl][v][to]);
			if (dp[j][lvl][v][to]) {
				dbg(to);
				f = true;
				ans = max(ans, dfs(j ^ 1, lvl - 1, to) + (1LL << lvl));
				dbg(ans);
			}
		}
		if (f) return res[j][i][v] = ans;
	}
	for (int to = 1; to <= n; ++to)
		if (dp[j][0][v][to])
			return res[j][i][v] = 1;
	return res[j][i][v] = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[c][0][a][b] = 1; 
		dbg(a, b, c, dp[c][0][a]);
	}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 2; ++j)
			for (int v = 1; v <= n; ++v)
				dbg(i, j, v, dp[j][i][v]);

	for (int i = 1; i < MAXB; ++i) 
		for (int j = 0; j < 2; ++j) 
			for (int v = 1; v <= n; ++v) 
				for (int to = 1; to <= n; ++to)
					if (dp[j][i - 1][v][to]) {
						dbg(i, j, v, to, dp[j][i - 1][v]);
						dp[j][i][v] |= dp[j ^ 1][i - 1][to];
					}

	// for (int v = 1; v <= n; ++v)
	// 	if (dp[0][MAXB - 1][v].count()) {
	// 		cout << "-1\n";
	// 		return 0;
	// 	}


	for (int v = 1; v <= n; ++v)
		for (int j = 0; j < 2; ++j) {
			used[j][0][v] = 1;
			res[j][0][v] = dp[j][0][v].count() ? 1 : 0;
		}

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 2; ++j)
			for (int v = 1; v <= n; ++v)
				dbg(i, j, v, dp[j][i][v], res[j][i][v]);

	// for (int v = 1; v <= n; ++v)
	// 	for (int i = MAXB - 1; i ; --i)
	// 		for (int j = 0; j < 2; ++j)
	// 			dfs(j, i, v);

	// ll ans = 0;
	// for (int i = 0; i < MAXB; ++i)
	// 	ans = max(ans, dfs(0, i, 1));
			
	ll ans = dfs(0, MAXB - 1, 1);

	const ll MX = 1e18;
	if (ans > MX) cout << "-1\n";
	else cout << ans << '\n';

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 2; ++j)
			for (int v = 1; v <= n; ++v)
				dbg(i, j, v, dp[j][i][v], res[j][i][v]);


	return 0;
}