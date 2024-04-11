#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v4.0

vi elevators, stairs;
int ce, cs;
int n, m, v;

int cobaStairs(int xa, int ya, int xb, int yb, int p, int v = 1) {
	int res = abs(xa - p) + abs(xb - p);
	return res + (abs(ya - yb) + v - 1) / v;
}

int cobaElevators(int xa, int ya, int xb, int yb, int p) {
	return cobaStairs(xa, ya, xb, yb, p, v);
}

int coba(int xa, int ya, int xb, int yb) {
	if (ya == yb) {
		return abs(xa - xb);
	}
	auto s = lower_bound(ALL(stairs), xa);
	int res = INF;

	if (s != stairs.end()) res = min(res, cobaStairs(xa, ya, xb, yb, *s));
	if (s != stairs.begin()) res = min(res, cobaStairs(xa, ya, xb, yb, *(--s)));

	auto e = lower_bound(ALL(elevators), xa);
	
	if (e != elevators.end()) res = min(res, cobaElevators(xa, ya, xb, yb, *e));
	if (e != elevators.begin()) res = min(res, cobaElevators(xa, ya, xb, yb, *(--e)));

	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m >> cs >> ce >> v;
	stairs.resize(cs);
	for (auto& s : stairs) {
		cin >> s;
	}
	elevators.resize(ce);
	for (auto& e : elevators) {
		cin >> e;
	}

	int q;
	cin >> q;
	FOR (tc, 0, q) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		swap(x1, y1); swap(x2, y2);
		cout << min(coba(x1, y1, x2, y2), coba(x2, y2, x1, y1)) << "\n";
	}
}