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

const int MOD = 1000000007;
#define N 5005
int dp[N][N];
int dp2[N][N];
int asu[20][N];
int buc[N];
string s;
int n;

struct Data
{
	int a, b, p;

	inline bool operator == (const Data& O) const
	{
		return a == O.a && b == O.b;
	}
};

Data dat[N], tmp[N];
int freq[N], start[N];

inline bool kecilan(int a, int b, int c, int d)
{
	int len = (b - a + 1);
	for (int dz = 13; dz >= 0; --dz)
		if ((1 << dz) & len)
		{
			if (asu[dz][a] > asu[dz][c]) return 0;
			else if (asu[dz][a] < asu[dz][c]) return 1;
			a += (1 << dz);
			c += (1 << dz);
		}
	return 0;
}

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n >> s;

	int len, id;
	for (len = 1, id = 0; len <= n; len <<= 1, ++id)
	{
		if (id == 0)
		{
			FOR (i,0,n)
				asu[0][i] = s[i] - '0';
		}
		else
		{
			FOR (i,0,n)
			{
				int iz = i + (len >> 1);
				dat[i].a = asu[id - 1][i];
				dat[i].b = (iz >= n ? -1 : asu[id - 1][iz]);
				dat[i].p = i;
			}
			fill(freq, freq + N, 0);
			FOR (j,0,n)
				++freq[dat[j].b + 1];
			start[0] = 0;
			FORN (j, 1, max(256, n))
			{
				start[j] = freq[j - 1];
				freq[j] += freq[j - 1];
			}
			FOR (j,0,n)
			{
				tmp[start[dat[j].b + 1]++] = dat[j];
			}
			fill(freq, freq + N, 0);
			FOR (j,0,n)
				++freq[tmp[j].a + 1];
			start[0] = 0;
			FORN (j, 1, max(256, n))
			{
				start[j] = freq[j - 1];
				freq[j] += freq[j - 1];
			}
			FOR (j,0,n)
				dat[start[tmp[j].a + 1]++] = tmp[j];
			FOR (j,0,n)
				asu[id][dat[j].p] = (j > 0 && dat[j] == dat[j - 1] ? asu[id][dat[j - 1].p] : j);
		}
	}


	RESET(dp, 0);
	RESET(dp2, 0);
	fill(dp[n], dp[n] + N, 1);
	fill(dp2[n], dp2[n] + N, 1);
	FORD (i, n - 1, 0)
		FORD (j, i, 0)
		{
			dp2[i][j] = dp2[i + 1][j + 1];
			if (s[i] == '0');
			else
			{
				if (j == 0) dp[i][j] = dp2[i + 1][j + 1];
				else if (i + j <= n && kecilan(i - j, i - 1, i, i + j - 1))
					dp[i][j] = dp2[i + j][j];
				else
					dp[i][j] = dp2[i + j + 1][j + 1];
			}
			dp2[i][j] += dp[i][j];
			if (dp2[i][j] >= MOD) dp2[i][j] -= MOD;
		}

	cout << dp[0][0] << "\n";
	return 0;
}