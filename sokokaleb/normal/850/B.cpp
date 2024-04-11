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

ll cnt[2000005];
ll kurang[2000005];
int n, a;
ll x, y;
ll ans = INFLL;

bitset<1000001> isp;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n >> x >> y;
	FOR (i, 0, n) {
		cin >> a;
		++cnt[a];
	}
	FORN (i, 1, 2000000) {
		cnt[i] += cnt[i - 1];
		kurang[i] = kurang[i - 1] + cnt[i - 1];
	}

	ll garugi = x / y + 1;
	isp.set();
	FORN (i, 2, 1000000) {
		if (isp.test(i)) {
			ll tmpCost = 0LL;
			int c = 0;
			while (c <= 1000000) {
				c += i;
				if (c <= 1000000)
					isp.set(c, 0);

				ll ccnt = 0;
				ll ckurang = 0LL;

				if (i > garugi) {
					ccnt = 0;
					if (c - garugi >= 0) ccnt += cnt[c - garugi];
					if (c - i >= 0) ccnt -= cnt[c - i];
					tmpCost += x * ccnt;
					//if (i == 2 && c <= 100) {
					//
						//cerr << ccnt << " di " << c << endl;
					//}

					ckurang = kurang[c];
					if (c - garugi + 1 >= 0)
						ckurang -= kurang[c - garugi + 1];
					if (c - garugi >= 0)
						ckurang -= cnt[c - garugi] * (garugi - 1);
					tmpCost += y * ckurang;
					//if (i == 2 && c <= 100) {
						//cerr << ccnt << " di " << c << endl;
					//}
				} else {
					// i <= garugi
					// garugi > 0
					ckurang = kurang[c];
					ckurang -= kurang[c - i + 1];
					ckurang -= cnt[c - i] * (i - 1);
					tmpCost += y * ckurang;
					//if (i == 2 && c <= 100) {
						//cerr << ckurang << " dzi " << c << endl;
					//}
				}
			}
			//if (tmpCost < ans) {
				//cerr << tmpCost << " = " << i << endl;
			//}
			ans = min(ans, tmpCost);
		}
	}

	ans = min(ans, x * n);
	cout << ans << "\n";
}