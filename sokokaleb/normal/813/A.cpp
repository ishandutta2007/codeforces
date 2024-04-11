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

#define MAX_N 100005
int n, m;
int dp[2][MAX_N];
bitset<MAX_N> can_do;
int dur[MAX_N];

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n;
	FOR (i, 0, n) {
		cin >> dur[i];
	}
	cin >> m;
	FOR (i, 0, m) {
		int a, b;
		cin >> a >> b;
		FORN (i, a, b) {
			can_do.set(i, 1);
		}
	}
	fill(dp[0], dp[0] + MAX_N, -1);
	fill(dp[1], dp[1] + MAX_N, 0);
	FOR (i, 0, n) {
		int y = i & 1;
		int z = (i & 1) ^ 1;
		FORD (t, MAX_N - 1, dur[i]) {
			dp[y][t] = max(dp[y][t], dp[z][t - dur[i]] + 1);
		}
	}

	int ans = INF;
	int z = (n - 1) & 1;
	FORN (t, 0, MAX_N - 1) {
		if (can_do.test(t) && dp[z][t] == n) {
			ans = t;
			break ;
		}
	}
	ans = (ans == INF ? -1 : ans);
	cout << ans << "\n";
	return 0;
}