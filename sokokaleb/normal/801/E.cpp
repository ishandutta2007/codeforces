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

#define N 200005
map<int, vi> MAP;
map<int, int> SZ;
int gcd[N];
int n, MOD;
bitset<N> larang;
int dp[N];
int prevz[N];
vi faktor;

ll __gcdll(ll A, ll B) {
	while (B != 0LL) {
		tie(A, B) = mt(B, A % B);
	}
	return A;
}

int f(int nz) {
	int& res = dp[nz];
	if (res != -1) return res;
	res = 0;
	for (const auto& item : faktor) {
		int gg = __gcdll(1LL * item * nz, MOD);
		if (gg != nz) {
			int lol = f(gg);
			if (lol > res) {
				res = max(res, f(gg));
				prevz[nz] = item;
			}
		}
	}
	res += SZ[nz];
	return res;
}

pll ext_gcd(int a, int b) {
	if (b == 0) return mp(1LL, 0LL);
	pll u = ext_gcd(b, a % b);
	return mp(u.ss, u.ff - (a / b) * u.ss);
}

void trace(int num, vi& vc, int lst = -1) {
	num = gcd[num];
	const vi& lol = MAP[gcd[num]];
	for (const auto& item : lol) {
		if (!larang.test(item)) {
			if (lst == -1) {
				vc.pb(item % MOD);
				lst = item;
			}
			else {
				pll tmp = ext_gcd(lst, MOD);
				int zz = tmp.ff;
				zz %= MOD;
				if (zz < 0) zz += MOD;
				zz = (1LL * zz * item) / __gcdll(MOD, lst) % MOD;
				vc.pb(zz);
				lst = (1LL * lst * zz) % MOD;
			}
		}
	}

	int gg = __gcdll(1LL * num * prevz[num], MOD);
	if (gg != num)
		trace(gg, vc, lst);
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> MOD;
	FOR (i, 0, n) {
		int a;
		cin >> a;
		larang.set(a, 1);
		if (a == 0) larang.set(MOD, 1);
	}

	FORN (i, 1, MOD) {
		int g = __gcd(i, MOD);
		MAP[g].pb(i);
		if (!larang.test(i)) {
			++SZ[g];
		}
		gcd[i] = g;
	}
	FORN (i, 1, MOD) {
		if (1LL * i * i > MOD) break;
		if (MOD % i == 0) {
			faktor.pb(i);
			if (MOD / i != i) faktor.pb(MOD / i);
		}
	}
	RESET(dp, -1);
	RESET(prevz, -1);
	int mx = -1;
	int idx = -1;
	FORN (i, 1, MOD) {
		int z = f(gcd[i]);
		if (z > mx) {
			mx = z;
			idx = i;
		}
	}
	cout << mx << "\n";
	vi vc;
	vc.clear();
	trace(idx, vc);
	for (const auto& item : vc) {
		cout << item << " ";
	}
	cout << "\n";
}