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
int dp[41][N];
int A, B, H, W, n;
int a[N];

int f(int pos, int w, int h) {
	int& res = dp[pos][w];
	if (res != -1) return res;
	res = 1000;
	ll nH, nW;
	// ga ambil
	nH = h;
	nW = w;
	if (nH >= A && nW >= B) return res = 0;

	if (pos < n) {
		nH = 1LL * a[pos] * h;
		nW = 1LL * w;
		if (nH >= A) {
			int cnt = 0;
			FOR (i, pos + 1, n) {
				if (nW >= B) break;
				nW *= a[i];
				++cnt;
			}
			if (nW >= B) {
				res = min(res, 1 + cnt);
			}
		} else {
			res = min(res, f(pos + 1, nW, nH) + 1);
		}

		nH = 1LL * h;
		nW = 1LL * w * a[pos];
		if (nW >= B) {
			int cnt = 0;
			FOR (i, pos + 1, n) {
				if (nH >= A) break;
				nH *= a[i];
				++cnt;
			}
			if (nH >= A) {
				res = min(res, 1 + cnt);
			}
		} else {
			res = min(res, f(pos + 1, nW, nH) + 1);
		}
	}
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	RESET(dp, -1);
	cin >> A >> B >> H >> W >> n;
	tie(A, B) = mt(min(A, B), max(A, B));
	FOR (i, 0, n) cin >> a[i];
	SSORT(a, n);
	reverse(a, a + n);
	n = min(n, 40);
	int res = f(0, W, H);
	RESET(dp, -1);
	res = min(res, f(0, H, W));
	cerr << res << endl;
	if (res > n) cout << -1 << "\n";
	else cout << res << "\n";
}