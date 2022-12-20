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

string arr[15];
int n, m;
int L, R;

int main(int argc, char** argv) {
    __INIT_CC__
    cin >> n >> m;
    m += 2;
    FORD (i, n - 1, 0) cin >> arr[i];
    while (n > 0) {
        if (count(ALL(arr[n - 1]), '1') > 0) break ;
        --n;
    }

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    if (n == 1) {
        int latest = -1;
        FOR (i, 0, m) {
            if (arr[0][i] == '1') latest = max(latest, i);
        }
        if (latest != -1) L = 2 * latest;
        cout << latest << "\n";
        return 0;
    }
    R = m - 1;
    L = 0;

    if (count(ALL(arr[0]), '1') > 0) {
        int latest = -1;
        FOR (i, 0, m) {
            if (arr[0][i] == '1') latest = max(latest, i);
        }
        if (latest != -1) L = 2 * latest;
    }

    ++L; ++R;
    // cerr << L << " " << R << endl;
    FOR (i, 1, n - 1) {
        int mi = INF, ma = -1;
        FOR (j, 0, m) {
            if (arr[i][j] == '1') {
                mi = min(mi, j);
                ma = max(ma, j);
            }
        }
        if (ma != -1) {
            tie(L, R) = mt(min(L + 2 * ma, R + m - 1), min(L + m - 1, R + 2 * (m - mi - 1)));
        }
        ++L; ++R;
        // cerr << L << " " << R << endl;
    }

    int mi = INF, ma = -1;
    FOR (j, 0, m) {
        if (arr[n - 1][j] == '1') {
            mi = min(mi, j);
            ma = max(ma, j);
        }
    }
    tie(L, R) = mt(L + ma, R + (m - mi - 1));

    cout << min(L, R) << "\n";
}