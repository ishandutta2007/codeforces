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
struct Node {
	unordered_set<int> SSET;
	ll cost, prop;
	int idx, propidx;
	set<int> SET;

	void merge(const Node& A, const Node& B) {
		if (A.SSET.empty() && B.SSET.empty()) {
			prop = -1LL;
			propidx = -1;
			return ;
		} else if (A.SSET.empty()) {
			cost = B.cost;
			idx = B.idx;
		} else if (B.SSET.empty()) {
			cost = A.cost;
			idx = A.idx;
		} else {
			if (A.cost < B.cost) {
				cost = A.cost;
				idx = A.idx;
			} else {
				cost = B.cost;
				idx = B.idx;
			}
		}
		return ;
	}

	void waris(Node& A, Node& B) const {
		if (A.SSET.empty()) {
			A.cost = INFLL;
			A.idx = -1;
			A.prop = -1LL;
			A.propidx = -1;
		} else A.propagate(prop, *A.SSET.begin());

		if (B.SSET.empty()) {
			B.cost = INFLL;
			B.idx = -1;
			B.prop = -1LL;
			B.propidx = -1;
		} else B.propagate(prop, *B.SSET.begin());
	}

	void propagate(ll cost, int idx) {
		if (SSET.empty()) {
			prop = -1LL;
			propidx = -1;
			return ;
		}
		if (this->cost > cost) {
			this->cost = cost;
			this->idx = idx;
		}

		if (prop == -1LL || cost < prop) {
			prop = cost;
			propidx = idx;
		}
	}
};

struct Plan {
	int typ;
	int u, v, l, r;
	ll w;

	inline void read() {
		cin >> typ;
		if (typ == 1) {
			cin >> v >> u >> w;
		} else {
			cin >> v >> l >> r >> w;
		}
	}
};

Node st[N << 2];
int n, q, s;
Plan plan[N];
vi adj[N];

void lebur(int node, int l, int r, int a, int b, int idx) {
	if (a <= l && r <= b) {
		st[node].SET.insert(idx);
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= a) lebur(A, l, mid, a, b, idx);
	if (mid + 1 <= b) lebur(B, mid + 1, r, a, b, idx);
	return ;
}

void update(int node, int l, int r, int a, int b, ll cost) {
	if (a <= l && r <= b) {
		if (st[node].SSET.empty()) {
			st[node].prop = -1LL;
			st[node].propidx = -1;
			st[node].cost = INFLL;
			st[node].idx = -1;
		}
		else {
			st[node].propagate(cost, *st[node].SSET.begin());
		}
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;

	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
	}
	if (mid >= a) update(A, l, mid, a, b, cost);
	if (mid + 1 <= b) update(B, mid + 1, r, a, b, cost);
	st[node].merge(st[A], st[B]);
	return ;
}

typedef pair<ll, int> pli;

pli getmin(int node, int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return mp(st[node].cost, st[node].idx);
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;

	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
	}
	pli Aa, Bb;
	if (mid >= a) Aa = getmin(A, l, mid, a, b);
	if (mid + 1 <= b) Bb = getmin(B, mid + 1, r, a, b);
	st[node].merge(st[A], st[B]);

	return min(Aa, Bb);
}

int lol[N];
int szlol;

void dfs(int node, int l, int r, int pos) {
	for (const auto& idx : st[node].SET) {
		lol[szlol++] = idx;
	}
	if (l == r && r == pos) {
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;

	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
	}

	if (mid >= pos) dfs(A, l, mid, pos);
	if (mid + 1 <= pos) dfs(B, mid + 1, r, pos);

	st[node].merge(st[A], st[B]);

	return ;
}

void apus(int node, int l, int r, int a, int b, int pos) {
	if (a <= l && r <= b) {
		st[node].SET.erase(pos);
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;

	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
		st[node].prop = -1LL;
		st[node].propidx = 1;
	}

	if (mid >= a) apus(A, l, mid, a, b, pos);
	if (mid + 1 <= b) apus(B, mid + 1, r, a, b, pos);

	st[node].merge(st[A], st[B]);

	return ;
}

void kelar(int node, int l, int r, int pos) {
	st[node].SSET.erase(pos);
	if (l == r && l == pos) {
		st[node].cost = INFLL;
		st[node].idx = -1;
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;

	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
	}

	if (mid >= pos) kelar(A, l, mid, pos);
	if (mid + 1 <= pos) kelar(B, mid + 1, r, pos);

	st[node].merge(st[A], st[B]);
}

void jawab(int node, int l, int r) {
	if (l == r) {
		if (st[node].cost >= INFLL - 1) {
			cout << -1;
		} else {
			cout << st[node].cost;
		}

		if (l == n);
		else cout << " ";
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;

	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
	}

	jawab(A, l, mid);
	jawab(B, mid + 1, r);
}

void masukin(int node, int l, int r) {
	FORN (z, l, r) {
		st[node].SSET.insert(z);
	}
	if (l == r) {
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	masukin(A, l, mid);
	masukin(B, mid + 1, r);
	return ;
}

void keluarin(int node, int l, int r, int pos) {
	st[node].SSET.erase(pos);

	if (l == r) {
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (st[node].prop != -1LL) {
		st[node].waris(st[A], st[B]);
	}
	if (mid >= pos) keluarin(A, l, mid, pos);
	if (mid + 1 <= pos) keluarin(B, mid + 1, r, pos);
	return ;
}

ll ans[N];

int main(int argc, char** argv) {
	__INIT_CC__
	fill(ans, ans + N, INFLL);
	cin >> n >> q >> s;
	FOR (i, 0, N << 2) {
		st[i].cost = INFLL;
		st[i].idx = -1;
		st[i].prop = -1;
		st[i].propidx = -1;
	}
	masukin(1, 1, n);
	FOR (i, 0, q) {
		plan[i].read();
		if (plan[i].typ == 1) {
			adj[plan[i].v].pb(i);
		} else if (plan[i].typ == 3) {
			lebur(1, 1, n, plan[i].l, plan[i].r, i);
		} else {
			adj[plan[i].v].pb(i);
		}
	}

	update(1, 1, n, s, s, 0);

	FORN (i, 1, n) {
		pli LOL = getmin(1, 1, n, 1, n);
		ll cost = LOL.ff;
		int idx = LOL.ss;
		if (cost >= INFLL - 1) break ;
		ans[idx] = cost;

		for (const auto& idxplan : adj[idx]) {
			const auto& plan = ::plan[idxplan];
			ll tcost;
			int v;
			switch (plan.typ) {
				case 1:
					v = plan.u;
					tcost = cost + plan.w;
					update(1, 1, n, v, v, tcost);
					break ;
				case 3:
					break ;
				case 2:
					tcost = cost + plan.w;
					update(1, 1, n, plan.l, plan.r, tcost);
					break ;
			}
		}
		szlol = 0;
		dfs(1, 1, n, idx);
		FOR (z, 0, szlol) {
			const auto& pplan = ::plan[lol[z]];
			ll tcost = cost + pplan.w;
			update(1, 1, n, pplan.v, pplan.v, tcost);
			apus(1, 1, n, pplan.l, pplan.r, lol[z]);
		}

		kelar(1, 1, n, idx);
	}

	FORN (i, 1, n) {
		if (i > 1) cout << " ";
		if (ans[i] >= INFLL - 1) ans[i] = -1LL;
		cout << ans[i];
	}
	cout << "\n";
}