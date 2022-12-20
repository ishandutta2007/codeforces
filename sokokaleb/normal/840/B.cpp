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

template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
    return ;
}

//using sokokaleb's template v4.0

#define MAX_N 300005
struct Edge {
    int x;
};
Edge edge[MAX_N];
vi adj[MAX_N];
int n, m, reality[MAX_N];
int d[MAX_N];
bitset<MAX_N> take;
bitset<MAX_N> visit;

int dfs(int u, int par) {
    visit.set(u, 1);
    int res = 0;

    for (const auto& e : adj[u]) {
        int v = edge[e].x ^ u;
        if (visit.test(v)) continue ;
        int tmp = dfs(v, e);
        if (tmp) {
            take.flip(e);
        }
        res ^= tmp;
    }

    if (d[u] == -1) {
        res = 0;
    } else {
        res ^= reality[u] ^ d[u];
    }
    return res;
}

int main(int argc, char** argv) {
    __INIT_CC__
    cin >> n >> m;
    int root = 0;
    FOR (i, 0, n) {
        cin >> d[i];
        if (d[i] == -1) {
            root = i;
        }
    }
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        edge[i].x = a ^ b;
        adj[a].pb(i);
        adj[b].pb(i);
        reality[a] ^= 1;
        reality[b] ^= 1;
    }

    FOR (i, 0, m) {
        take.set(i, 1);
    }
    if (dfs(root, -1) != 0) {
        cout << -1 << "\n";
        return 0;
    }
    cout << take.count() << "\n";
    FOR (i, 0, m) {
        if (take.test(i)) {
            cout << (i + 1) << "\n";
        }
    }
}