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

#define N 4005
vi adj[N];
int arr[N][2];
int n;

map<string, int> MAP;
vi vec[N];
int mapc;
int dcnt;
int S[N];
int ssize;
int dlow[N], dnum[N];

int getid(const string& s) {
	if (!MAP.count(s)) MAP[s] = mapc++;
	return MAP[s];
}

bitset<N> vis;
bitset<N> SET;

int SCCCount;
vi SCCMember[N];
int SCCId[N];

vi topo;

void dfs(int u, int par) {
	dlow[u] = dnum[u] = dcnt++;
	S[ssize++] = u;
	vis.set(u, 1);
	for (const auto& v : adj[u]) {
		if (dnum[v] == -1) dfs(v, u);
		if (vis.test(v)) dlow[u] = min(dlow[u], dlow[v]);
	}
	if (dlow[u] == dnum[u]) {
		SET.reset();
		int cur;
		do {
			cur = S[--ssize];
			SCCId[cur] = SCCCount;
			SCCMember[SCCCount].pb(cur);
			SET.set(cur, 1);
			vis.set(cur, 0);
			if (SET.test(cur ^ 1)) {
				cout << "NO\n";
				exit(0);
			}
		} while (cur != u);
		++SCCCount;
	}
}

void dfs(int u) {
	if (vis.test(u)) return ;
	vis.set(u, 1);
	for (const auto& mem : SCCMember[u]) {
		for (const auto& v : adj[mem]) {
			int vscc = SCCId[v];
			if (vscc != u) {
				dfs(vscc);
			}
		}
	}
	topo.pb(u);
}

int ans[N];
string aa[N], bb[N];

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n;
	FOR (i, 0, n) {
		string a, b;
		cin >> a >> b;
		aa[i] = a;
		bb[i] = b;

		string s = "   ";
		s[0] = a[0];
		s[1] = a[1];
		s[2] = a[2];
		int id = getid(s);
		arr[i][0] = id;
		vec[id].pb(i << 2);

		s[2] = b[0];
		id = getid(s);
		arr[i][1] = id;
		vec[id].pb(i << 2 | 2);

		int x = i << 2;
		int y = x | 2;
		adj[x ^ 1].pb(y);
		adj[y ^ 1].pb(x);
	}

	//FOR (i, 0, n) {
		//int x = i << 2;
		//for (const auto& v : vec[arr[i][0]]) {
			//if (v == x || (v >> 2) == (x >> 2)) continue ;
			//adj[x].pb(v ^ 1);
			//adj[v].pb(x ^ 1);
		//}
		//x |= 2;
		//for (const auto& v : vec[arr[i][1]]) {
			//if (v == x || (v >> 2) == (x >> 2)) continue ;
			//adj[x].pb(v ^ 1);
			//adj[v].pb(x ^ 1);
		//}
	//}
	
	FOR (i, 0, n) {
		int x = (i << 2) | 2;
		for (const auto& v : vec[arr[i][0]]) {
			if ((v >> 2) == (x >> 2) || (v & 2) > 0) continue ;
			adj[x].pb(v ^ 1);
			adj[v].pb(x ^ 1);
		}
	}

	FOR (i, 0, mapc) {
		if (SIZE(vec[i]) > 1) {
			FOR (j, 0, SIZE(vec[i])) {
				FOR (k, j + 1, SIZE(vec[i])) {
					int u = vec[i][j];
					int v = vec[i][k];
					adj[u].pb(v ^ 1);
					adj[v].pb(u ^ 1);
				}
			}
		}
	}

	FOR (i, 0, n * 4) {
		VSORT(adj[i]);
		adj[i].erase(unique(ALL(adj[i])), adj[i].end());
	}

	RESET(dnum, -1);
	RESET(dlow, -1);
	FOR (i, 0, n * 4) {
		if (dnum[i] == -1) {
			dfs(i, -1);
		}
	}

	vis.reset();
	FOR (i, 0, n * 4) {
		dfs(SCCId[i]);
	}

	vis.reset();
	for (const auto& scid : topo) {
		if (!vis.test(scid)) {
			vis.set(scid, 1);
			for (const auto& mem : SCCMember[scid]) {
				ans[mem] = 1;
				ans[mem ^ 1] = 0;
				vis.set(SCCId[mem ^ 1], 1);
			}
		}
	}

	cout << "YES\n";
	FOR (i, 0, n) {
		cout << aa[i][0] << aa[i][1] << (ans[i << 2] ? aa[i][2] : bb[i][0]) << "\n";
	}
}