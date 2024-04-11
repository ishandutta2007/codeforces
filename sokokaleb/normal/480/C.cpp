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

#define N 5005
const int MOD = 1000000007;
int dp[2][N];
int n, a, b, k;

int leftlimit[N], rightlimit[N];

inline void addMod(int &a, int val)
{
	a += val;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return ;
}

int main()
{
	__INIT_CC__;
	cin >> n >> a >> b >> k;
	int now = 0, bef = 1;

	if (a < b);
	else
	{
		a = n + 1 - a;
		b = n + 1 - b;
	}

	FORN (i,1,b-1)
	{
		leftlimit[i] = 1;
		rightlimit[i] = b - 1;
		while (leftlimit[i] + 1 <= i && abs(leftlimit[i] - i) >= abs(leftlimit[i] - b)) ++leftlimit[i];
		while (rightlimit[i] - 1 >= i && abs(rightlimit[i] - i) >= abs(rightlimit[i] - b)) --rightlimit[i];
		// cerr << setw(5) << i << " = " << leftlimit[i] << " " << rightlimit[i] << "\n";
	}

	FORN (i,a,b-1)
		dp[now][i] = 1;

	FOR (i,0,k)
	{
		swap(now, bef);
		RESET(dp[now], 0);
		int gval = 0;

		FORN (j,1,b - 1)
		{
			gval = 0;
			addMod(gval, dp[bef][j-1]);
			addMod(gval, -dp[bef][leftlimit[j] - 1]);
			addMod(gval, dp[bef][rightlimit[j]]);
			addMod(gval, -dp[bef][j]);

			// cerr << setw(5) << gval;

			addMod(dp[now][j], dp[now][j-1]);
			addMod(dp[now][j], gval);
			// cerr << setw(10) << dp[now][j] << " | ";
		}
		// cerr << endl;
	}

	int ans = 0;
	addMod(ans, dp[now][b-1]);
	cout << ans << "\n";
	return 0;
}