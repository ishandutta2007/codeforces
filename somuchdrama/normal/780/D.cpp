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

const int MAXN = 2017;
string a[MAXN], b[MAXN], ans[MAXN], kek[MAXN];
vector<int> g[MAXN];
int kl[MAXN], kr[MAXN];
bool used[MAXN];

bool dfs(int v) {
    if (used[v]) 
        return false;
    used[v] = true;
    for (int to : g[v]) 
        if (!kr[to]) 
            return kl[kr[to] = v] = to;
    for (int to : g[v]) 
        if (dfs(kr[to])) 
            return kl[kr[to] = v] = to;
    return false;
}

int main() {
	int n;
	cin >> n;
	set<string> all, bad;
	for (int i = 1; i <= n; ++i) {
		string x, y;
		cin >> x >> y;
		a[i] = {x[0], x[1], x[2]};
		b[i] = {x[0], x[1], y[0]};
		if (all.count(a[i]))
			bad.insert(a[i]);
		all.insert(a[i]);
		all.insert(b[i]);
	}

	map<string, int> num;
	for (auto s : all) {
		int sz = num.size() + 1;
		num[s] = sz;
		kek[sz] = s;
	}

	for (int i = 1; i <= n; ++i) {
		if (!bad.count(a[i])) 
			g[i].pb(num[a[i]]);
		g[i].pb(num[b[i]]);
	}

    for (int go = 1; go--;) {
        memset(used, 0, sizeof used);
        for (int i = 1; i <= n; ++i)
            if (!kl[i] && dfs(i))
                go = 1;
    }

    int yay = 0;
    for (int i = 1; i <= n; ++i) 
    	if (kl[i]) {
    		++yay;
    		ans[i] = kek[kl[i]];
    	}

    if (yay == n) {
    	cout << "YES\n";
    	for (int i = 1; i <= n; ++i)
    		cout << ans[i] << '\n';
	} else cout << "NO\n";

    return 0;
}