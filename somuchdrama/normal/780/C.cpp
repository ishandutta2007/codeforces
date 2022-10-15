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

const int MAXN = 2e5 + 1;
int c[MAXN];
bool used[MAXN];
vector<int> g[MAXN];

void dfs(int v, int cp = 0) {
	used[v] = true;
	int cc = 1;
	for (int to : g[v]) {
		if (!used[to]) {
			while (cc == c[v] || cc == cp)
				++cc;
			c[to] = cc++;
		}
	}
	for (int to : g[v])
		if (!used[to])
			dfs(to, c[v]);
}


int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	c[1] = 1;
	dfs(1);

	int mx = 0;
	for (int i = 1; i <= n; ++i)
		mx = max(mx, c[i]);
	cout << mx << '\n';
	for (int i = 1; i <= n; ++i)
		cout << c[i] << ' ';
	cout << '\n';



	return 0;
}