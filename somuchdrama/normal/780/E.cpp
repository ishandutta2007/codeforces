#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 2e5 + 1;
vector<int> g[MAXN];
vector<int> order;
bool used[MAXN];
void dfs(int v) {
	used[v] = 1;
	order.pb(v);
	for (int to : g[v])
		if (!used[to]) {
			dfs(to);
			order.pb(v);
		}
}

vector<int> ans[MAXN];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(1);	
	int step = (n + n + k - 1) / k;
	int gnome = 0;
	for (int i = 0; i < order.size(); i += step) {
		for (int j = 0; i + j < order.size() && j < step; ++j) 
			ans[gnome].pb(order[i + j]);
		gnome++;
	}

	for (int i = 0; i < k; ++i) {
		if (ans[i].empty()) ans[i].pb(1);
		cout << ans[i].size() << ' ';
		for (int j : ans[i]) cout << j << ' ';
		cout << '\n';
	}

    return 0;
}