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

#define N 100005
ll n, A, cf, cm;
ll m;
ii arr[N];

priority_queue<pll> PQ;

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n >> A >> cf >> cm >> m;
	FOR (i,0,n)
	{
		cin >> arr[i].ff;
		arr[i].ss = i;
	}
	SSORT(arr, n);
	ll need = 0, ansneed;
	FOR (i,0,n) need += A - arr[i].ff;
	ll ans = -1;
	int ians = -1;
	pll cans = mp(0LL, 0LL);
	if (need <= m)
	{
		ans = 1LL * cf * n + 1LL * cm * A;
		ansneed = need;
	}
	pll current = mp(0LL, 0LL), lst = mp(0LL, 0LL);
	FOR (i,0,n)
	{
		need -= A - arr[i].ff;
		ll sisa = m - need;
		if (sisa >= 0)
		{
			while (!PQ.empty() && -1LL * PQ.top().ff <= sisa)
				current = take(PQ);
			ll cnt = -current.ss;
			ll kurang = -current.ff;
			sisa -= kurang;
			ll tmp = 1LL * cf * (n - i - 1) + 1LL * cm * min(1LL * A, 1LL * arr[cnt].ff + sisa / (cnt + 1));
			if (tmp > ans)
			{
				ans = tmp;
				ians = i;
				cans = current;
				ansneed = need;
			}
		}
		++lst.ss;
		lst.ff += lst.ss * (arr[i + 1].ff - arr[i].ff);
		PQ.push(mp(-lst.ff, -lst.ss));
	}
	cout << ans << "\n";

	FOR (i, ians + 1, n) arr[i].ff = A;
	ll sisa = m - ansneed;
	ll cnt = -cans.ss, kurang = -cans.ff;
	sisa -= kurang;
	int laennya = min(1LL * A, 1LL * arr[cnt].ff + sisa / (cnt + 1));
	FOR (i, 0, ians + 1) arr[i].ff = max(arr[i].ff, laennya);

	sort(arr, arr + n, [](const ii& A, const ii& B){return A.ss < B.ss;});
	FOR (i,0,n) cout << arr[i].ff << " ";
	cout << "\n";
	return 0;
}