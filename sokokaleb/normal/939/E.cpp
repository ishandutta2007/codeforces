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

struct Query {
	int op, x;
};

int q;
int mx;
vi vec;
vi pool;

const int MAX_N = 500005;
set<ii> SET;
int L[MAX_N], R[MAX_N], num[MAX_N];

int main(int argc, char** argv) {
	__INIT_CC__
	RESET(L, -1);
	RESET(R, -1);
	cin >> q;
	bool first = 1;

	int mmx = -1;
	ll sum = 0LL;
	int cnt = 0;
	int idx = -1;
	int sz = 0;
	int largesttc = -1;
	FOR (tc, 0, q) {
		int op, x;
		cin >> op;
		if (op == 1) {
			++sz;
			cin >> x;
			if (x >= mmx) {
				largesttc = tc;
				mmx = max(mmx, x);
			}
			num[tc] = x;
			if (first) {
				first = 0;
				SET.insert(mp(x, tc));
				idx = tc;
				cnt = 1;
				sum = x;
			} else {
				if (x >= num[idx]);
				else {
					sum += x;
					++cnt;
				}

				set<ii>::iterator it = SET.lower_bound(mp(x, tc));
				if (it == SET.end()) {
					int previdx = (--it)->ss;
					R[previdx] = tc;
					L[tc] = previdx;
				} else if (it == SET.begin()) {
					int nextidx = it->ss;
					R[tc] = nextidx;
					L[nextidx] = tc;
				} else {
					int nextidx = it->ss;
					int previdx = (--it)->ss;
					L[nextidx] = tc;
					R[previdx] = tc;
					L[tc] = previdx;
					R[tc] = nextidx;
				}

				SET.insert(mp(x, tc));
			}
		} else {
			if (sz == 1) {
				cout << "0.000000000000\n";
			} else {
				if (idx == largesttc) {
					sum -= num[idx];
					cnt -= 1;
					idx = L[idx];
				}
				double ans = 1.0 * (sum + mmx) / (cnt + 1);
				while (L[idx] != -1) {
					double tmp = 1.0 * (sum + mmx - num[L[idx]]) / cnt;
					if (tmp < ans) {
						ans = tmp;
						sum -= num[idx];
						cnt -= 1;
						idx = L[idx];
					} else break;
				}
				while (R[idx] != -1 && R[idx] != largesttc) {
					double tmp = 1.0 * (sum + mmx + num[R[idx]]) / (cnt + 2);
					if (tmp < ans) {
						ans = tmp;
						idx = R[idx];
						sum += num[idx];
						cnt += 1;
					} else break;
				}

				cout << fixed << setprecision(12) << 1.0 * mmx - ans << "\n";
			}
		}
	}
}