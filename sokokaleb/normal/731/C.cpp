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
int papa[N], renk[N];

int cp(int x) {
	if (x == papa[x]) return x;
	return papa[x] = cp(papa[x]);
}

int join(int x, int y) {
	x = cp(x); y = cp(y);
	if (x == y) return 0;
	if (renk[x] < renk[y]) {
		papa[x] = y;
	} else if (renk[y] < renk[x]) {
		papa[y] = x;
	} else {
		papa[y] = x;
		++renk[x];
	}
	return 1;
}

int ccnt = 0;
vector<vi> vec;
bitset<N> ada, kepake;
int arr[N], n, m, k;
int mapping[N];

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m >> k;
	FOR (i, 0, n) {
		cin >> arr[i];
		papa[i] = i;
	}
	FOR (i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		join(a, b);
		kepake.set(a, 1);
		kepake.set(b, 1);
	}

	FOR (i, 0, n) {
		if (kepake.test(i)) {
			int id = cp(i);
			if (!ada.test(id)) {
				ada.set(id, 1);
				vec.pb(vi());
				mapping[id] = ccnt++;
			}
			vec[mapping[id]].pb(arr[i]);
		}
	}
	int ans = 0;
	FOR (i, 0, ccnt) {
		VSORT(vec[i]);
		int banyak = 0;
		int tmp = 1;
		vec[i].pb(INF);
		FOR (z, 1, SIZE(vec[i])) {
			if (vec[i][z] != vec[i][z - 1]) {
				banyak = max(banyak, tmp);
				tmp = 0;
			}
			++tmp;
		}
		ans += SIZE(vec[i]) - 1 - banyak;
	}
	cout << ans << "\n";
}