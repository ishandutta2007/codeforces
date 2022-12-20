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

typedef tuple<ll, ll> tll;

#define N 2005
ll dst[2][N];
tll pt[N], o[2];
int n, arr[N];
ll a, b;

inline ll jarak(const tll& A, const tll& B)
{
	ll x = _get(A, 0) - _get(B, 0);
	ll y = _get(A, 1) - _get(B, 1);
	return x * x + y * y;
}

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n;
	FOR (i,0,2)
	{
		cin >> a >> b;
		o[i] = mt(a, b);
	}
	FOR (i,0,n)
	{
		arr[i] = i;
		cin >> a >> b;
		pt[i] = mt(a, b);
	}
	FOR (i,0,2)
		FOR (j,0,n)
			dst[i][j] = jarak(o[i], pt[j]);

	ll ans = max(*max_element(dst[0], dst[0] + n), *max_element(dst[1], dst[1] + n));
	ll tmpans;

	sort(arr, arr + n, [](const int& A, const int& B){return dst[0][A] < dst[0][B];});
	FOR (i,0,n)
	{
		tmpans = dst[0][arr[i]];
		ll asu = 0LL;
		FOR (j, i + 1, n)
			asu = max(asu, dst[1][arr[j]]);
		ans = min(ans, tmpans + asu);
	}

	sort(arr, arr + n, [](const int& A, const int& B){return dst[1][A] < dst[1][B];});
	FOR (i,0,n)
	{
		tmpans = dst[1][arr[i]];
		ll asu = 0LL;
		FOR (j, i + 1, n)
			asu = max(asu, dst[0][arr[j]]);
		ans = min(ans, tmpans + asu);
	}

	cout << ans << "\n";
	return 0;
}