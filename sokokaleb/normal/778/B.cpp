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

struct Ops {
	string op[5];
	int typ;
	int opz;

	inline void read() {
		cin >> op[0];
		cin >> op[1];
		cin >> op[2];
		if (op[2][0] == '0' || op[2][0] == '1') {
			typ = 0;
		} else {
			cin >> op[3] >> op[4];
			typ = 1;
			if (op[3] == "XOR") opz = 0;
			else if (op[3] == "OR") opz = 1;
			else opz = 2;
		}
	}

	inline ii eval(int pos, map<string, ii>& MAP) {
		if (typ == 0) {
			int v = op[2][pos] - '0';
			return mp(v, v);
		} else {
			ii a = MAP[op[2]];
			ii b = MAP[op[4]];
			if (opz == 0) return mp(a.ff ^ b.ff, a.ss ^ b.ss);
			else if (opz == 1) return mp(a.ff | b.ff, a.ss | b.ss);
			return mp(a.ff & b.ff, a.ss & b.ss);
		}
	}
};

int n, m;
Ops op[5005];
int itung[1005][2];
map<string, ii> MAP;

void coba(int pos) {
	MAP.clear();
	MAP["?"] = mp(0, 1);
	itung[pos][0] = itung[pos][1] = 0;
	FOR (i, 0, n) {
		ii v = op[i].eval(pos, MAP);
		if (v.ff) ++itung[pos][0];
		if (v.ss) ++itung[pos][1];
		MAP[op[i].op[0]] = v;
	}
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m;
	FOR (i, 0, n) {
		op[i].read();
	}
	FOR (i, 0, m) {
		coba(i);
	}
	string ans[2];
	ans[0] = "";
	ans[1] = "";
	FORD (i, m - 1, 0) {
		if (itung[i][0] == itung[i][1]) {
			ans[0].pb('0');
			ans[1].pb('0');
		} else if (itung[i][0] > itung[i][1]) {
			ans[0].pb('1');
			ans[1].pb('0');
		} else {
			ans[0].pb('0');
			ans[1].pb('1');
		}
	}
	reverse(ALL(ans[0]));
	reverse(ALL(ans[1]));

	cout << ans[0] << "\n" << ans[1] << endl;
}