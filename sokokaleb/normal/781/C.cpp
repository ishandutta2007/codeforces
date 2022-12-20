#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
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
 
const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg = 0;
	num = 0;
	char c;
	while ((c = getchar_unlocked()) && (!isdigit(c) && c != '-'));
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	do num = num * 10 + c - '0';
	while ((c = getchar_unlocked()) && isdigit(c));
	if (neg) num = -num;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in = "input.txt",string out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v3.1

#define N 200005
vi adj[N];
int n, m, k;

int papa[N], renk[N];

int cp(int x) {
	if (papa[x] == x) return x;
	return papa[x] = cp(papa[x]);
}

int join(int a, int b){
	a = cp(a);
	b = cp(b);
	if (a == b) return 0;
	if (renk[a] < renk[b]) {
		papa[a] = b;
	} else if (renk[b] < renk[a]) {
		papa[b] = a;
	} else {
		papa[b] = a;
		++renk[a];
	}
	return 1;
}

int arr[N], cnt;
int batas;

int lol = 0;

void masuk(int u) {
	arr[cnt++] = u;
	if (cnt == batas) {
		++lol;
		cout << cnt;
		FOR (i, 0, cnt) cout << " " << arr[i] + 1;
		cout << "\n";
		cnt = 0;
	}
}

void dfs(int u, int par) {
	masuk(u);
	for (const auto& v : adj[u]) {
		if (v == par) continue ;
		dfs(v, u);
		masuk(u);
	}
}


int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m >> k;
	FOR (i, 0, n) {
		papa[i] = i;
		renk[i] = 0;
	}
	FOR (i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (join(a, b)) {
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}

	int batas = 2 * n;
	batas = (batas + k - 1) / k;
	::batas = batas;
	dfs(0, -1);
	if (cnt > 0) {
		cout << cnt;
		FOR (i, 0, cnt) cout << " " << arr[i] + 1;
		cout << "\n";
		++lol;
	}
	FOR (i, lol, k) {
		cout << 1 << " " << 1 << "\n";
	}
}