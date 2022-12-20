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

int R, C, W;
int cost[2005][2005];

using Pos = tuple<ll, int, int>;
set<Pos> pq;
ll total_cost[2005][2005];

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> R >> C >> W;
	FOR (i, 0, R) {
		FOR (j, 0, C) {
			cin >> cost[i][j];
			total_cost[i][j] = INFLL >> 2;
		}
	}

	pq.insert({0LL, 0, 0});
	total_cost[0][0] = 0LL;
	while (!pq.empty()) {
		auto [ctc, x, y] = *pq.begin();
		pq.erase({ctc, x, y});
		if (ctc != total_cost[x][y]) continue;

		FOR (i, 0, 4) {
			auto [nx, ny] = mt(x + dr[i], y + dc[i]);
			if (inRange(nx, 0, R - 1) && inRange(ny, 0, C - 1) && cost[nx][ny] >= 0) {
				if (ctc + W < total_cost[nx][ny]) {
					pq.erase({total_cost[nx][ny], nx, ny});
					total_cost[nx][ny] = ctc + W;
					pq.insert({total_cost[nx][ny], nx, ny});
				}
			}
		}
	}
	ll best_direct = total_cost[R - 1][C - 1];
	ll best_from_source = INFLL >> 2;
	FOR (i, 0, R) {
		FOR (j, 0, C) {
			if (cost[i][j] > 0) {
				best_from_source = min(best_from_source, total_cost[i][j] + cost[i][j]);
			}
			total_cost[i][j] = INFLL >> 2;
		}
	}

	// cerr << best_direct << " " << best_from_source << " ASU" << endl;

	pq.insert({0LL, R - 1, C - 1});
	total_cost[R - 1][C - 1] = 0LL;
	while (!pq.empty()) {
		auto [ctc, x, y] = *pq.begin();
		pq.erase({ctc, x, y});
		if (ctc != total_cost[x][y]) continue;

		FOR (i, 0, 4) {
			auto [nx, ny] = mt(x + dr[i], y + dc[i]);
			if (inRange(nx, 0, R - 1) && inRange(ny, 0, C - 1) && cost[nx][ny] >= 0) {
				if (ctc + W < total_cost[nx][ny]) {
					pq.erase({total_cost[nx][ny], nx, ny});
					total_cost[nx][ny] = ctc + W;
					pq.insert({total_cost[nx][ny], nx, ny});
				}
			}
		}
	}

	ll best_from_sink = INFLL >> 2;
	FOR (i, 0, R) {
		FOR (j, 0, C) {
			if (cost[i][j] > 0) {
				best_from_sink = min(best_from_sink, total_cost[i][j] + cost[i][j]);
			}
		}
	}

	// cerr << best_from_sink << " ASOE" << endl;

	ll ans = min(best_direct, best_from_sink + best_from_source);
	if (ans >= (INFLL >> 2)) ans = -1;
	cout << ans << "\n";
}