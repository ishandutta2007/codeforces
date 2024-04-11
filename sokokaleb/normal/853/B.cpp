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

#define N 1000005
priority_queue<ii> PQ[N];
int caw[N];
ll ans = INFLL;
int n, m, k;

struct Data {
	int d, f, t, c, idx;

	friend istream& operator >> (istream& is, Data& d) {
		is >> d.d >> d.f >> d.t >> d.c;
		return is;
	}
};

Data data[N];
vector<int> dvec[N];
int adacnt = 0;
bitset<N> ada;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> m >> k;
	FOR (i, 0, m) {
		cin >> data[i];
		dvec[data[i].d].pb(i);
		data[i].idx = i;
	}

	FORD (z, 1000000, k + 1) {
		for (const int& id : dvec[z]) {
			const Data& d = data[id];
			if (d.f == 0) {
				PQ[d.t].push(mp(-d.c, d.idx));
			}
		}
	}

	ll tmpAns = 0LL;
	FORN (i, 1, n) {
		if (PQ[i].empty()) {
			cout << "-1\n";
			return 0;
		}
		tmpAns += -PQ[i].top().ff;
	}
	int ed = k + 1;
	FORN (st, 1, 1000000 - k + 1) {
		for (const int& id : dvec[st]) {
			const Data& d = data[id];
			if (d.t == 0) {
				tmpAns -= caw[d.f];
				if (!ada.test(d.f)) {
					++adacnt;
					caw[d.f] = INF;
				}
				ada.set(d.f, 1);
				caw[d.f] = min(caw[d.f], d.c);
				tmpAns += caw[d.f];
			}
		}
		bool abis = 0;
		for (const int& id : dvec[ed]) {
			const Data& d = data[id];
			if (d.f == 0) {
				auto& PQ = ::PQ[d.t];
				tmpAns -= -PQ.top().ff;
				while (!PQ.empty() && data[PQ.top().ss].d <= ed) {
					PQ.pop();
				}
				if (PQ.empty()) {
					abis = 1;
					break ;
				}
				tmpAns += -PQ.top().ff;
			}
		}
		++ed;
		if (abis) break ;
		if (adacnt == n) {
			ans = min(ans, tmpAns);
		}
	}

	if (ans == INFLL) {
		cout << -1 << "\n";
		return 0;
	}
	cout << ans << "\n";
}