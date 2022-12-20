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

bitset<1000005> ok;
int N, A, B;
vi nums;
vi ans;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> N >> A >> B;
	ok.reset();
	ok.set(0, 1);
	FORN (i, A, N) {
		ok.set(i, ok.test(i) || ok.test(i - A));
	}
	FORN (i, B, N) {
		ok.set(i, ok.test(i) || ok.test(i - B));
	}
	if (!ok.test(N)) {
		cout << -1 << "\n";
		return 0;
	}
	int now = N;
	while (now > 0) {
		if (now - A >= 0 && ok.test(now - A)) {
			nums.pb(A);
			now -= A;
		} else {
			nums.pb(B);
			now -= B;
		}
	}

	FORN (i, 1, N) {
		ans.pb(i);
	}
	int lo, hi;
	lo = hi = 0;
	for (const auto& i : nums) {
		hi = lo + i;
		rotate(ans.begin() + lo, ans.begin() + hi - 1, ans.begin() + hi);
		lo = hi;
	}
	FOR (i, 0, N) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}