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

struct Data
{
	int a, b, c, d;

	inline void getData()
	{
		cin >> a >> b >> c >> d;
	}
};

#define N 200005
set<ii> SET[N << 2];
unordered_map<int, int> MX;
vi vx;
int n, sz;
Data arr[N];
int dist[N];

void insert(int node, int l, int r, int x, int y, int idx)
{
	if (l == r && l == x)
	{
		SET[node].insert(mp(y, idx));
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= x) insert(A, l, mid, x, y, idx);
	if (mid + 1 <= x) insert(B, mid + 1, r, x, y, idx);
	SET[node].insert(mp(y, idx));
	return ;
}

inline void insert(int x, int y, int idx)
{
	insert(1, 0, sz - 1, x, y, idx);
}

void getList(int node, int l, int r, int x, int y, vi& res)
{
	if (x <= l)
	{
		for (set<ii>::iterator it = SET[node].lower_bound(mp(y, -1)); it != SET[node].end(); ++it)
			res.pb(it->ss);
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= x) getList(A, l, mid, x, y, res);
	getList(B, mid + 1, r, x, y, res);
	return ;
}

inline vi getList(int idx)
{
	vi res;
	res.clear();

	getList(1, 0, sz - 1, arr[idx].a, arr[idx].b, res);

	return move(res);
}

void erase(int node, int l, int r, int x, int y, int idx)
{
	if (l == r && l == x)
	{
		SET[node].erase(mp(y, idx));
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= x) erase(A, l, mid, x, y, idx);
	if (mid + 1 <= x) erase(B, mid + 1, r, x, y, idx);
	SET[node].erase(mp(y, idx));
}

inline void erase(int x, int y, int idx)
{
	erase(1, 0, sz - 1, x, y, idx);
}

int bef[N];

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n;
	FOR (i,0,n) arr[i].getData();
	FOR (i,0,n)
	{
		vx.pb(arr[i].c);
		vx.pb(arr[i].a);
	}
	VSORT(vx);
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	FOR (i,0,SIZE(vx)) MX[vx[i]] = i;
	FOR (i,0,n) arr[i].c = MX[arr[i].c], arr[i].a = MX[arr[i].a];

	sz = SIZE(vx);
	FOR (i,0,n) insert(arr[i].c, arr[i].d, i);

	fill(dist, dist + n, INF);
	dist[n - 1] = 0;
	erase(arr[n - 1].c, arr[n - 1].d, n - 1);
	queue<int> Q;
	bef[n - 1] = -1;
	Q.push(n - 1);
	while (!Q.empty())
	{
		auto now = take(Q);
		vi res = getList(now);
		for (const auto& idx : res)
		{
			erase(arr[idx].c, arr[idx].d, idx);
			dist[idx] = dist[now] + 1;
			bef[idx] = now;
			Q.push(idx);
		}
	}

	int ans = INF, argans;

	FOR (i,0,n)
	{
		if (dist[i] < ans && mt(arr[i].a, arr[i].b) == mt(0, 0))
		{
			ans = dist[i];
			argans = i;
		}
	}

	if (ans == INF) cout << "-1\n";
	else
	{
		cout << ans + 1 << "\n";
		int now = argans;
		while (now != -1)
		{
			cout << now + 1 << " ";
			now = bef[now];
		}
		cout << "\n";
	}
	return 0;
}