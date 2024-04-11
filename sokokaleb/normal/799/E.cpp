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

struct Deco {
	int like_flag;
	int cost;
};

#define MAX_N 200005
int n, m, k;
int c[MAX_N];
int like[2][MAX_N], n_like[2];
Deco deco[MAX_N];

struct Node {
	ll sum;
	int largest;
	int cnt;
};

vll vec[4];
int nvec[4];

struct STree {
	Node st[MAX_N << 2];

	void build(int node, int l, int r) {
		if (l == r) {
			st[node].largest = c[l];
			st[node].cnt = 0;
			st[node].sum = 0LL;
			return ;
		}

		int mid = (l + r) >> 1, A = node << 1, B = A | 1;
		build(A, l, mid);
		build(B, mid + 1, r);
		st[node].largest = st[B].largest;
	}

	void update(int node, int l, int r, int value, int cnt) {
		st[node].sum += 1LL * value * cnt;
		st[node].cnt += cnt;
		if (l == r) return ;

		int mid = (l + r) >> 1, A = node << 1, B = A | 1;
		if (value <= st[A].largest) update(A, l, mid, value, cnt);
		else update(B, mid + 1, r, value, cnt);
	}

	ll getNSmallest(int node, int l, int r, int n) {
		if (n == 0 || n < 0) return 0LL;
		if (st[node].cnt <= n) return st[node].sum;
		if (l == r) return 1LL * n * st[node].largest;

		int mid = (l + r) >> 1, A = node << 1, B = A | 1;
		return getNSmallest(A, l, mid, n) + getNSmallest(B, mid + 1, r, n - st[A].cnt);
	}
};
int stn;

STree stree;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m >> k;
	FORN (i, 1, n) {
		cin >> deco[i].cost;
		c[i - 1] = deco[i].cost;
	}
	FOR (z, 0, 2) {
		cin >> n_like[z];
		FOR (i, 0, n_like[z]) {
			cin >> like[z][i];
			deco[like[z][i]].like_flag |= (1 << z);
		}
	}

	FORN (i, 1, n) {
		vec[deco[i].like_flag].pb(i);
		++nvec[deco[i].like_flag];
	}
	FOR (i, 0, 4) {
		sort(ALL(vec[i]), [](const auto& A, const auto& B) {
			return deco[A].cost > deco[B].cost;
		});
		vec[i].pb(0);
		reverse(ALL(vec[i]));
		FOR (z, 1, SIZE(vec[i])) {
			vec[i][z] = vec[i][z - 1] + deco[vec[i][z]].cost;
		}
	}

	SSORT(c, n);
	stn = distance(c, unique(c, c + n));
	stree.build(1, 0, stn - 1);

	FOR (i, 0, 3)
		FOR (z, 1, SIZE(vec[i])) {
			stree.update(1, 0, stn - 1, vec[i][z] - vec[i][z - 1], 1);
		}

	ll ans = INFLL;
	ll base_ans = 0LL;
	int bareng = nvec[3];
	reverse(ALL(vec[3]));
	int lul = 0;
	for (const auto& bareng_cost : vec[3]) {
		base_ans = bareng_cost;

		int terbeli = bareng;

		int idx = max(0, k - bareng);
		while (lul < idx) {
			++lul;
			FOR (o, 0, 2) {
				if (lul <= nvec[1 << o]) {
					stree.update(1, 0, stn - 1, vec[1 << o][lul] - vec[1 << o][lul - 1], -1);
				}
			}
		}

		bool ok = 1;
		int jir = max(k - bareng, 0);
		FOR (o, 0, 2) {
			ok &= (jir <= nvec[1 << o]);
			terbeli += jir;
		}

		ok &= (terbeli <= m);

		if (ok) {
			FOR (o, 0, 2) {
				base_ans += vec[1 << o][jir];
			}
			int sisa = m - terbeli;
			if (stree.st[1].cnt >= sisa) {
				base_ans += stree.getNSmallest(1, 0, stn - 1, sisa);
				ans = min(base_ans, ans);
			}
		}

		--bareng;
	}

	if (ans == INFLL) cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}