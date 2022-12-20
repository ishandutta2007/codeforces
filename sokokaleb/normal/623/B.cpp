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

#define WWW 32768
bitset<WWW> isp;
vi primes, used;
int cnt[WWW];

#define N 1000005
int arr[N], n;
ll ans, a, b;

inline void proc(int x, int val)
{
	FOR (i,0,SIZE(primes))
	{
		const int& p = primes[i];
		if (x % p == 0)
		{
			cnt[i] |= val;
			while (x % p == 0) x/= p;
		}
	}
	if (x != 1LL) used.pb(x);
	return ;
}

ll pcost[N];

inline void coba(int p)
{
	ll res = INFLL;
	ll cost = 0LL;
	fill(pcost, pcost + n, INFLL);
	pcost[n] = a * n;
	FORD (i, n - 1, 0)
	{
		if (arr[i] % p == 0); // free
		else if ((arr[i] - 1) % p == 0 || (arr[i] + 1) % p == 0)
			cost += b;
		else break;
		pcost[i] = a * i + cost;
		res = min(res, pcost[i]);
	}
	FORD (i, n - 1, 0)
		pcost[i] = min(pcost[i], pcost[i + 1]);

	cost = 0LL;
	FOR (i,0,n)
	{
		if (arr[i] % p == 0);
		else if ((arr[i] - 1) % p == 0 || (arr[i] + 1) % p == 0)
			cost += b;
		else break;
		res = min(res, cost + pcost[i + 1] - a * (i + 1));
	}
	ans = min(ans, res);
}

int main(int argc, const char *argv[])
{
	__INIT_CC__
	
	isp.set();
	FOR (i,2,WWW)
		if (isp.test(i))
		{
			primes.pb(i);
			ll c = 1LL * i * i;
			while (c < WWW)
			{
				isp.set(c, 0);
				c += i;
			}
		}

	ans = INFLL;
	cin >> n >> a >> b;
	FOR (i,0,n) cin >> arr[i];
	FORN (i,-1,1)
	{
		proc(arr[0] + i, 1);
		proc(arr[n - 1] + i, 2);
	}
	FOR (i,0,SIZE(primes))
		if (cnt[i])
			used.pb(primes[i]);

	for (const auto& p : used)
		coba(p);

	cout << ans << "\n";
	return 0;
}