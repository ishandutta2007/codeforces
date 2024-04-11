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

namespace logging {
#ifdef DEBUG
	constexpr bool enable_logging = true;
#else
	constexpr bool enable_logging = false;
#endif
	template<typename T>
	std::ostream& operator << (std::ostream& os, vector<T> vec) {
		bool first = true;
		for (const T& v : vec) {
			os << (first ? "" : " ") << v;
			first = false;
		}
		return os;
	}

	template<typename A, typename B>
	std::ostream& operator << (std::ostream& os, pair<A, B> p) {
		os << "(" << p.first << ", " << p.second << ")";
		return os;
	}
}  // namespace logging

#define LOG \
	if (!logging::enable_logging) {} \
	else cerr

constexpr int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
constexpr int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
constexpr double eps = 1e-9;
constexpr int kInf = 0x7FFFFFFF;
constexpr ll kInfll = 0x7FFFFFFFFFFFFFFFLL;
constexpr double pi = acos(-1);

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

//using sokokaleb's template v6.0

int DP[2005][2005];
int arr[2005];
int N, K;
constexpr int binrep[10] = {
    //1234567
	0b1110111, // 0
	0b0010010, // 1
	0b1011101, // 2
    0b1011011, // 3
    0b0111010, // 4
    0b1101011, // 5
    0b1101111, // 6
    0b1010010, // 7
    0b1111111, // 8
    0b1111011  // 9
};

constexpr int NeedFor(int from_bin, int to) {
	int binrep = ::binrep[to];
	if ((0b1111111 ^ binrep) & from_bin) {
		return 3000;
	}
	return __builtin_popcount(binrep ^ from_bin);
}

int f(int pos, int kleft) {
	int &res = DP[pos][kleft];
	if (res != -1) return res;
	if (pos == N) {
		return res = (kleft == 0 ? 1 : 0);
	}
	res = 0;
	FORD (i, 9, 0) {
		const int needed = NeedFor(arr[pos], i);
		if (needed <= kleft) {
			res |= f(pos + 1, kleft - needed);
		}
	}
	return res;
}

void Trace(int pos, int kleft) {
	if (pos == N) {
		cout << "\n";
		return;
	}
	FORD (i, 9, 0) {
		const int needed = NeedFor(arr[pos], i);
		if (needed <= kleft && f(pos + 1, kleft - needed)) {
			cout << i;
			Trace(pos + 1, kleft - needed);
			return;
		}
	}
}

void solve() {
	cin >> N >> K;
	FOR (i, 0, N) {
		string s;
		cin >> s;
		arr[i] = 0;
		for (const auto c : s) {
			arr[i] <<= 1;
			arr[i] += c - '0';
		}
	}
	RESET(DP, -1);
	if (!f(0, K)) {
		cout << -1 << "\n";
	} else {
		Trace(0, K);
	}
}

int main(int argc, char** argv) {
	__INIT_CC__
	solve();
}