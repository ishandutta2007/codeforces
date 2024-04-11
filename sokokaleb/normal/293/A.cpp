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

struct Data {
	int dat; // [0, 3]
	int idx;
};

#define MAX_N 2000005
string s[2];
int n;
bitset<MAX_N> used;
Data data[2][MAX_N];
int cnt;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n;
	FOR (i, 0, 2) {
		cin >> s[i];
	}
	FOR (i, 0, 2 * n) {
		data[0][i].dat = (s[0][i] - '0') * 2 + (s[1][i] - '0');
		data[0][i].idx = i;
		data[1][i] = data[0][i];
	}

	sort(data[0], data[0] + 2 * n, [](const auto& A, const auto& B) {
		return A.dat > B.dat;
	});
	sort(data[1], data[1] + 2 * n, [](const auto& A, const auto& B) {
		int a = ((A.dat << 1) | (A.dat >> 1)) & 3;
		int b = ((B.dat << 1) | (B.dat >> 1)) & 3;
		return a > b;
	});

	int ptrB = 0;
	FOR (ptrA, 0, 2 * n) {
		if (used.test(data[0][ptrA].idx)) continue ;
		cnt += data[0][ptrA].dat >> 1;
		used.set(data[0][ptrA].idx, 1);

		while (ptrB < 2 * n && used.test(data[1][ptrB].idx)) ++ptrB;
		if (ptrB < 2 * n) {
			cnt -= data[1][ptrB].dat & 1;
			used.set(data[1][ptrB].idx, 1);
		}
	}

	string ans = "Draw";
	if (cnt > 0) {
		ans = "First";
	} else if (cnt < 0) {
		ans = "Second";
	}

	cout << ans << "\n";
}