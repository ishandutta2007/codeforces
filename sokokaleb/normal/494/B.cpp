#include <bits/stdc++.h>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

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
 
using namespace std;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
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
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v3.0

#define N 200005
const int MOD = 1000000007;
string t,p;
int fail[N];
int cum[N], cnt[N];
vi vc;

void buildFail()
{
	int i = 0, j = -1;
	fail[0] = -1;
	while (i < SIZE(p))
	{
		while (j >= 0 && p[i] != p[j]) j = fail[j];
		++i; ++j;
		fail[i] = j;
	}
}

bitset<N> OK;

void kmpSearch()
{
	int i = 0, j = 0;
	while (i < SIZE(t))
	{
		while (j >= 0 && t[i] != p[j]) j = fail[j];
		++i; ++j;
		if (j == SIZE(p))
		{
			OK.set(i-1,1);
			j = fail[j];
		}
	}
}

int main(int argc, char const *argv[])
{
	__INIT_CC__;
	cin >> t;
	cin >> p;
	buildFail();
	kmpSearch();
	int last = -1, sum = 1;
	cum[0] = 1;
	FOR (i,0,SIZE(t))
	{
		if (!OK.test(i))
		{
			if (last == -1) cnt[i] = 0;
			else cnt[i] = cnt[last];
		}
		else
		{
			last = i;
			if (i - SIZE(p) < 0) cnt[i] = 1;
			else cnt[i] = cum[i - SIZE(p)];
		}

		sum += cnt[i];
		if (sum >= MOD) sum -= MOD;

		cum[i] = (i - 1 < 0 ? 1 : cum[i-1]) + sum;
		if (cum[i] >= MOD) cum[i] -= MOD;
	}

	int ans = 0;
	FOR (i,0,SIZE(t))
	{
		// cerr << setw(10) << cnt[i] << " " << setw(10) << cum[i] << endl;
		ans += cnt[i];
		if (ans >= MOD) ans -= MOD;
	}

	cout << ans << "\n";
	return 0;
}