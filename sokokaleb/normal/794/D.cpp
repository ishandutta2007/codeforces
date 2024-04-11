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

const vi HASHES = {1000000007, 1000000009};
const int szh = 2;
const int BASE = 300005;

int PKT[szh][BASE];

struct HashValue {
	int hv[szh];

	void init(int val) {
		FOR (i, 0, szh) {
			hv[i] = val;
		}
	}

	bool operator == (const HashValue& o) const {
		FOR (i, 0, szh) {
			if (hv[i] != o.hv[i]) {
				return 0;
			}
		}
		return 1;
	}

	HashValue operator * (const HashValue& o) const {
		HashValue res;
		res.init(0);
		FOR (i, 0, szh) {
			res.hv[i] = (1LL * hv[i] * o.hv[i]) % HASHES[i];
		}
		return res;
	}

	HashValue operator + (const HashValue& o) const {
		HashValue res;
		res.init(0);
		FOR (i, 0, szh) {
			res.hv[i] = hv[i] + o.hv[i];
			if (res.hv[i] >= HASHES[i]) res.hv[i] -= HASHES[i];
		}
		return res;
	}

	bool operator < (const HashValue& o) const {
		FOR (i, 0, szh) {
			if (hv[i] < o.hv[i]) return 1;
			else if (hv[i] > o.hv[i]) return 0;
		}
		return 0;
	}

	string to_string() {
		ostringstream oss;
		oss << "(";
		FOR (i, 0, szh) {
			if (i) oss << ",";
			oss << hv[i];
		}
		oss << ")";
		return oss.str();
	}
};

#define N 300005
vector<int> adj[N];
int adjHash[N];
HashValue hv[N];
int V, E;

int pl[N];
vi members[N];
vi adj_members[N];
int members_count;
int id_members[N];
bitset<N> vis;
int ans_members[N];

void dfs(int u) {
	int uu = members[u][0];
	vis.reset();
	vis.set(u, 1);
	for (const auto& vv : adj[uu]) {
		int v = id_members[vv];
		if (vis.test(v));
		else {
			adj_members[u].pb(v);
		}
		vis.set(v, 1);
	}
	return ;
}

void dfsAns(int u, int num, int par=-1) {
	ans_members[u] = num;
	for (const auto& v : adj_members[u]) {
		if (v == par) continue ;
		dfsAns(v, num + 1, u);
	}
	return ;
}

int main(int argc, char** argv) {
	__INIT_CC__
	
	FOR (i, 0, szh) {
		PKT[i][0] = 1;
		FOR (j, 1, BASE) {
			PKT[i][j] = (1LL * BASE * PKT[i][j - 1]) % HASHES[i];
		}
	}
	
	cin >> V >> E;
	FOR (i, 0, E) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FORN (i, 1, V) {
		hv[i].init(0);
		adj[i].pb(i);
		VSORT(adj[i]);
		HashValue tmp;
		FOR (j, 0, SIZE(adj[i])) {
			FOR (z, 0, szh) {
				tmp.hv[z] = (1LL * adj[i][j] * PKT[z][j]) % HASHES[z];
			}
			hv[i] = hv[i] + tmp;
		}
		pl[i] = i;
	}

	sort(pl + 1, pl + V + 1, [](const auto& A, const auto& B) {
			return hv[A] < hv[B];
	});

	HashValue lst = hv[pl[1]];
	members[0].pb(pl[1]);
	id_members[pl[1]] = 0;
	FORN (i, 2, V) {
		if (hv[pl[i]] == lst);
		else {
			++members_count;
		}
		id_members[pl[i]] = members_count;
		members[members_count].pb(pl[i]);
		lst = hv[pl[i]];
	}
	++members_count;

	FOR (i, 0, members_count) {
		dfs(i);
	}

	int root = -1;
	int cntWan = 0, cntTwo = 0, cntZero = 0;
	FOR (i, 0, members_count) {
		if (SIZE(adj_members[i]) > 2) {
			cout << "NO\n";
			return 0;
		}
		if (SIZE(adj_members[i]) == 1) {
			root = i;
			++cntWan;
		} else if (SIZE(adj_members[i]) == 2) {
			++cntTwo;
		} else if (SIZE(adj_members[i]) == 0) {
			++cntZero;
		}
	}

	if (cntZero == 1 && cntWan == 0 && cntTwo == 0) {
		cout << "YES\n";
		FORN (i, 1, V) {
			cout << 1;
			if (i == V) cout << "\n";
			else cout << " ";
		}
	} else if (cntWan == 2 && cntWan + cntTwo ==  members_count && cntZero == 0) {
		dfsAns(root, 1);
		cout << "YES\n";
		FORN (i, 1, V) {
			cout << ans_members[id_members[i]];
			if (i == V) cout << "\n";
			else cout << " ";
		}
	} else {
		cout << "NO\n";
		return 0;
	}
}