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

char ans[55][55];

void isi(int x, int y, int lx, int ly, char c) {
	FOR (i, x, x + lx) {
		FOR (j, y, y + ly) {
			ans[i][j] = c;
		}
	}
	return ;
}

vii isian;
const string LOL = "ABCDA";
int arr[5];

int main(int argc, char** argv) {
	__INIT_CC__
	isi(0, 0, 25, 25, 'A');
	isi(0, 25, 25, 25, 'B');
	isi(25, 0, 25, 25, 'C');
	isi(25, 25, 25, 25, 'D');
	for (int i = 1; i <= 23; i += 2) {
		for (int j = 1; j <= 23; j += 2) {
			isian.pb({i, j});
		}
	}
	FOR (i, 0, 4) {
		cin >> arr[i]; --arr[i];
	}
	arr[4] = arr[0];
	FORN (i, 0, 1) {
		FORN (j, 0, 1) {
			int X = 25 * i;
			int Y = 25 * j;
			int idx = (i * 2 + j) + 1;
			FOR (k, 0, arr[idx]) {
				const ii& POS = isian[k];
				isi(X + POS.ff, Y + POS.ss, 1, 1, LOL[idx]);
			}
		}
	}
	cout << 50 << " " << 50 << "\n";
	FOR (i, 0, 50) {
		FOR (j, 0, 50) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
}