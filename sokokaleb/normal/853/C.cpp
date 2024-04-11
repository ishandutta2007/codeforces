#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
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

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v4.0

#define N 200005
int bit[N];
int cnt;
int n, q;

struct Point {
	int x, y;
};

struct Query {
	int l, d, r, u;
	int idx;
	ll ans = 0LL;

	friend istream& operator >> (istream& is, Query& q) {
		is >> q.l >> q.d >> q.r >> q.u;
		return is;
	}
};

Point point[N];
Query query[N];

int read(int pos) {
	int res = 0;
	for (; pos; pos -= pos & -pos) {
		res += bit[pos];
	}
	return res;
}

ll read(int x, int y) {
	if (x > y) return 0;
	int z = read(y) - read(x - 1);
	return 1LL * z * (z - 1) / 2;
}

void update(int pos, int val) {
	for (; pos < N; pos += pos & -pos) {
		bit[pos] += val;
	}
	return ;
}

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> q;
	FOR (col, 0, n) {
		cin >> point[col].y;
		point[col].x = col + 1;
	}
	FOR (i, 0, q) {
		cin >> query[i];
		query[i].idx = i;
	}

	sort(query, query + q, [](const auto& A, const auto& B) {
		return A.l < B.l;
	});
	sort(point, point + n, [](const auto& A, const auto& B) {
		return A.x < B.x;
	});

	RESET(bit, 0);
	int patok = 0;
	FOR (i, 0, q) {
		Query& qq = query[i];
		while (patok < n && point[patok].x < qq.l) {
			update(point[patok].y, 1);
			++patok;
		}
		qq.ans += read(1, n);
		qq.ans -= read(1, qq.d - 1);
		qq.ans -= read(qq.u + 1, n);
	}

	sort(query, query + q, [](const auto& A, const auto& B) {
		return A.r > B.r;
	});
	sort(point, point + n, [](const auto& A, const auto& B) {
		return A.x > B.x;
	});

	RESET(bit, 0);
	patok = 0;
	FOR (i, 0, q) {
		Query& qq = query[i];
		while (patok < n && qq.r < point[patok].x) {
			update(point[patok].y, 1);
			++patok;
		}
		qq.ans += read(1, n);
		qq.ans -= read(1, qq.d - 1);
		qq.ans -= read(qq.u + 1, n);
	}

	sort(query, query + q, [](const auto& A, const auto& B) {
		return A.d < B.d;
	});
	sort(point, point + n, [](const auto& A, const auto& B) {
		return A.y < B.y;
	});

	RESET(bit, 0);
	patok = 0;
	FOR (i, 0, q) {
		Query& qq = query[i];
		while (patok < n && point[patok].y < qq.d) {
			update(point[patok].x, 1);
			++patok;
		}
		qq.ans += read(1, n);
	}

	sort(query, query + q, [](const auto& A, const auto& B) {
		return A.u > B.u;
	});
	sort(point, point + n, [](const auto& A, const auto& B) {
		return A.y > B.y;
	});

	RESET(bit, 0);
	patok = 0;
	FOR (i, 0, q) {
		Query& qq = query[i];
		while (patok < n && qq.u < point[patok].y) {
			update(point[patok].x, 1);
			++patok;
		}
		qq.ans += read(1, n);
	}

	sort(query, query + q, [](const auto& A, const auto& B) {
		return A.idx < B.idx;
	});

	ll total = 1LL * n * (n - 1) / 2;
	FOR (i, 0, q) {
		const auto& qq = query[i];
		cout << total - qq.ans << "\n";
	}
	
	return 0;
}