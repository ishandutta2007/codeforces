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

#define N 505
int n, m;
int a, b;
bool adjm[N][N];
vi adj[N];
string color = "acb";
int ans[N];
bool fail = 0;
int stc[2], szstc[2];

void dfs(int u, int c)
{
	ans[u] = 1 << c;
	for (const auto& v : adj[u])
	{
		if (ans[v] == 7)
		{
			dfs(v, c ^ 1);
		}
		else
		{
			if (ans[v] == ans[u])
				fail = 1;
			if (ans[v] == 4)
				fail = 1;
		}
	}
	return ;
}

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n >> m;
	fill(ans, ans + n, 7);
	FOR (i,0,m)
	{
		cin >> a >> b;
		--a; --b;
		adjm[a][b] = adjm[b][a] = 1;
	}

	FOR (i,0,n)
		FOR (j,i+1,n)
			if (adjm[i][j] == 0)
			{
				adj[i].pb(j);
				adj[j].pb(i);
			}

	FOR (i,0,n)
		FOR (j,i+1,n)
			if (!adjm[i][j])
			{
				FOR (k,0,n)
					if (k != i && k != j)
					{
						if (adjm[i][k] && adjm[j][k])
							ans[k] = 4;
					}
			}

	FOR (i,0,n)
		if (ans[i] == 4)
		{
			if (SIZE(adj[i]))
				fail = 1;
		}
		else if (ans[i] == 7)
		{
			dfs(i, 0);
		}

	if (fail) cout << "No\n";
	else
	{
		cout << "Yes\n";
		FOR (i,0,n) cout << color[__builtin_ctz(ans[i])];
		cout << "\n";
	}


	return 0;
}