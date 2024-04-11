/*

Code for problem J by cookiedoth
Generated 18 Sep 2022 at 07.56 PM
The Moon is Waning Crescent (40% of Full)


                                           /
                        _,.------....___,.' ',.-.
                     ,-'          _,.--"        |
                   ,'         _.-'              .
                  /   ,     ,'                   `
                 .   /     /                     ``.
                 |  |     .                       \.\
       ____      |___._.  |       __               \ `.
     .'    `---""       ``"-.--"'`  \               .  \
    .  ,            __               `              |   .
    `,'         ,-"'  .               \             |    L
   ,'          '    _.'                -._          /    |
  ,`-.    ,".   `--'                      >.      ,'     |
 . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'
 ||:, .           ,'  ;  /  / \ `        `.    .      .'/
 j|:D  \          `--'  ' ,'_  . .         `.__, \   , /
/ L:_  |                 .  "' :_;                `.'.'
.    ""'                  """""'                    V
 `.                                 .    `.   _,..  `
   `,_   .    .                _,-'/    .. `,'   __  `
    ) \`._        ___....----"'  ,'   .'  \ |   '  \  .
   /   `. "`-.--"'         _,' ,'     `---' |    `./  |
  .   _  `""'--.._____..--"   ,             '         |
  | ." `. `-.                /-.           /          ,
  | `._.'    `,_            ;  /         ,'          .
 .'          /| `-.        . ,'         ,           ,
 '-.__ __ _,','    '`-..___;-...__   ,.'\ ____.___.'
 `"^--'..'   '-`-^-'"--    `-^-'`.''"""""`.,^.`.--' mh
 
^_^
-_-
z_z

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#include <array>
#define int long long
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Bag {
	Bag() {}

	vector<pair<int, ll>> dt;

	void insert(int key, ll val) {
		dt.emplace_back(val, key);
	}

	void prepare() {
		sort(rall(dt));
	}

	ll get_max() {
		return dt.empty() ? 0 : dt[0].first;
	}

	ll get_max2() {
		return dt.empty() ? 0 : dt.size() == 1 ? dt[0].first : dt[0].first + dt[1].first;
	}

	ll get_max_without(int key) {
		if (dt[0].second == key) {
			return dt.size() == 1 ? 0 : dt[1].first;
		} else {
			return dt[0].first;
		}
	}

	ll get_max2_without(int key) {
		if (dt[0].second == key) {
			return dt.size() == 1 ? 0 : dt.size() == 2 ? dt[1].first : dt[1].first + dt[2].first;
		} else if (dt.size() >= 2 && dt[1].second == key) {
			return dt.size() >= 3 ? dt[0].first + dt[2].first : dt[0].first;
		} else {
			return get_max2();
		}
	}

	int size() {
		return dt.size();
	}
};

const int MAX_N = 1e5 + 228;
int n, par[MAX_N];
ll path_down[MAX_N], path_up[MAX_N], diam_down[MAX_N], diam_up[MAX_N], up_cost[MAX_N], ans;
Bag down_p[MAX_N], diam_bag[MAX_N];
vector<vector<pair<int, int>>> g;

void read() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c);
		ans += 2 * c;
	}
}

void dfs_down(int v, int pv) {
	for (auto [v1, cost] : g[v]) {
		if (v1 != pv) {
			up_cost[v1] = cost;
			dfs_down(v1, v);
			down_p[v].insert(v1, path_down[v1] + cost);
			diam_bag[v].insert(v1, diam_down[v1]);
		}
	}
	down_p[v].prepare();
	diam_bag[v].prepare();
	diam_down[v] = diam_bag[v].get_max();
	if (down_p[v].size() == 1) {
		path_down[v] = down_p[v].get_max();
		chkmax(diam_down[v], path_down[v]);
	} else if (down_p[v].size() >= 2) {
		path_down[v] = down_p[v].get_max();
		chkmax(diam_down[v], down_p[v].get_max2());
	}
}

ll opt;

void dfs_up(int v, int pv) {
	if (v) {
		path_up[v] = up_cost[v] + max(path_up[pv], down_p[pv].get_max_without(v));
		diam_up[v] = max(diam_up[pv], max(diam_bag[pv].get_max_without(v), max(path_up[pv] + down_p[pv].get_max_without(v), down_p[pv].get_max2_without(v))));
	}
	for (auto [v1, cost] : g[v]) {
		if (v1 != pv) {
			dfs_up(v1, v);
		}
	}
	multiset<ll> S;
	for (auto [val, key] : down_p[v].dt) {
		S.insert(val);
	}
	S.insert(path_up[v]);
	ll cur_opt = 0;
	for (int it = 0; it < 4; ++it) {
		if (!S.empty()) {
			cur_opt += *prev(S.end());
			S.erase(prev(S.end()));
		}
	}
	chkmax(opt, cur_opt);
}

void solve() {
	for (int i = 1; i < n; ++i) {
		chkmax(opt, 2 * up_cost[i] + diam_up[i] + diam_down[i]);
	}
	cout << ans - opt << '\n';
}

signed main() {
	fast_io();
	read();
	dfs_down(0, 0);
	dfs_up(0, 0);
	solve();
}