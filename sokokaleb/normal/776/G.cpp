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

ll dp[16][16][2][2][2];
string a, b;
int dig[20];
int pvalid;

ll f(int pos, int hi, int udah, int flag, int lobit, int hibit, int sdz) {
	ll& res = dp[pos][hi][udah][flag][sdz];
	if (res != -1) return res;
	if (pos == 15) {
		return res = udah;
	}
	res = 0;
	if (inRange(hi, lobit, hibit)) {
		int z = hi % 4;
		FORD (i, hi, 0) {
			if (i & (1 << z)) {
				flag = flag || (i < dig[pos]);
				if (i > dig[pos]) {
					if (flag)
						res += f(pos + 1, hi, udah || (pos >= pvalid && i == hi), flag, lobit - 4, hibit - 4, sdz || i > 0);
				}
				else {
					res += f(pos + 1, hi, udah || (pos >= pvalid && i == hi), flag, lobit - 4, hibit - 4, sdz || i > 0);
				}
			}
		}
	} else {
		FORD (i, hi, 0) {
			flag = flag || (i < dig[pos]);
			if (i > dig[pos]) {
				if (flag) {
			   		res += f(pos + 1, hi, udah || (pos >= pvalid && i == hi), flag, lobit - 4, hibit - 4, sdz || i > 0);
				}
			}
			else {
				int _udah = udah;
				if (hi == i) {
					if (hi == 0) {
						_udah = _udah || sdz;
					} else {
						_udah = 1;
					}
				}
				res += f(pos + 1, hi, _udah, flag, lobit - 4, hibit - 4, sdz || i > 0);
			}
		}
	}
	return res;
}

ll conv(string s) {
	ll res = 0;
	for (const char& c : s) {
		res <<= 4;
		if (isdigit(c)) {
			res += c - '0';
		} else {
			res += 10 + c - 'a';
		}
	}
	return res;
}

ll coba(ll x) {
	RESET(dig, 0);
	pvalid = 14;
	FORD (i, 14, 0) {
		dig[i] = x & 0xf;
		if (dig[i] > 0) pvalid = i;
		x >>= 4;
	}
	RESET(dp, -1);
	ll res = 0LL;
	FORN (i, 0, 15) {
		ll z = f(0, i, 0, 0, 56, 59, 0);
		res += z;
	}
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__
	RESET(dp, -1);
	int q;
	cin >> q;
	FORN (tc, 1, q) {
		cin >> a >> b;
		ll ans = 0;
		ll num = conv(a);
		if (num == 0);
		else {
			--num;
			ans -= coba(num);
		}
		num = conv(b);
		ans += coba(num);
		cout << ans << "\n";
	}
}