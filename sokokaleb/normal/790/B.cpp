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

struct Data {
	int cnt[5];
	ll ans;
	int MOD;

	Data (int MOD) {
		this->MOD = MOD;
		ans = 0;
		RESET(cnt, 0);
	}

	void adv() {
		ans += cnt[MOD - 1];
		rotate(cnt, cnt + MOD - 1, cnt + MOD);
	}

	void rollback() {
		rotate(cnt, cnt + 1, cnt + MOD);
		ans -= cnt[MOD - 1];
	}

	void add() {
		++cnt[MOD - 1];
	}

	void remove() {
		--cnt[MOD - 1];
	}

	void add(const Data& d) {
		FOR (i, 0, MOD) {
			cnt[i] += d.cnt[i];
		}
		ans += d.ans;
	}

	void remove(const Data& d) {
		FOR (i, 0, MOD) {
			cnt[i] -= d.cnt[i];
		}
		ans -= d.ans;
	}
};

#define N 200005

ll ans;
vi adj[N];
int n, k;

Data dfs(int u, int par, Data& data) {
	ans += data.ans;

	Data cum(k);
	cum.add();

	for (const auto& v : adj[u]) {
		if (v == par) continue ;
		data.add(cum);
		data.adv();
		Data dz = dfs(v, u, data);
		data.rollback();
		data.remove(cum);
		cum.add(dz);
	}


	cum.adv();
	return cum;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> k;
	FOR (i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	Data d(k);
	dfs(0, -1, d);

	cout << ans << "\n";
}