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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 1001;
vector<int> comp;
bool used[MAXN];
bool edge[MAXN][MAXN];
vector<int> g[MAXN];

void dfs(int v) {
	used[v] = true;
	comp.pb(v);
	for (int to : g[v])
		if (!used[to])
			dfs(to);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(k);
	while (k--)
		cin >> c[k];
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		edge[a][b] = edge[b][a] = true;
	}

	ll ans = 0;
	int mx = 0;
	for (int x : c) {
		comp.clear();
		dfs(x);
		mx = max(mx, int(comp.size()));
		for (uint i = 0; i < comp.size(); ++i)
			for (uint j = i + 1; j < comp.size(); ++j)
				if (!edge[comp[i]][comp[j]])
					++ans;
		dbg(x, ans);
	}

	comp.clear();
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (!used[i])
		{
			++cnt;
			comp.pb(i);
		}

	for (uint i = 0; i < comp.size(); ++i)
		for (uint j = i + 1; j < comp.size(); ++j)
			if (!edge[comp[i]][comp[j]])
				++ans;

	dbg(ans, mx, cnt);
	ans += mx * cnt;

	cout << ans << '\n';


    return 0;
}