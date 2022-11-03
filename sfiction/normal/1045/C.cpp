#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define pd __gnu_pbds
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using namespace placeholders;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using il = initializer_list<T>;
 
template <class T> inline void mini(T &l, T r){l = min(l, r);}
template <class T> inline void maxi(T &l, T r){l = max(l, r);}
 
template <class T> void _dbg(const char *sdbg, T &&h){cerr << sdbg << "=" << h << "\n";}
template <class T, class ...R> void _dbg(const char *sdbg, T h, R... a){
	while (*sdbg != ','){cerr << *sdbg++;} cerr << "=" << h << ","; _dbg(sdbg + 1, a...);}
template <class L, class R> ostream &operator <<(ostream &os, const pair<L, R> &P){
	return os << "(" << P.st << "," << P.nd << ")";}
template <class T> ostream &operator <<(ostream &os, const vector<T> &v){
	os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
	return V(b, e);}
template <class T, class c = decltype(T().begin()), typename enable_if<!is_same<T, string>::value>::type* = nullptr> ostream &operator <<(ostream &os, T &v){
	return os << gr(v.begin(), v.end());}
template <class T, int I, int N, typename enable_if<I == N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<N>(val);}
template <class T, int I, int N, typename enable_if<I < N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<I>(val) << ","; TuplePrint<T, I + 1, N>(os, val);}
template <class... Ts> ostream &operator<<(ostream &os, tuple<Ts...> t){
	os << "("; TuplePrint<tuple<Ts...>, 0, sizeof...(Ts) - 1>(os, t); return os << ")";}
 
#ifdef SFIC
#define eput(...) do{cerr << __LINE__;_dbg("\t| "#__VA_ARGS__, __VA_ARGS__);}while(0)
#else
#define eput(...) 218
#endif
 
//pd::priority_queue<int, less<int>, pairing_heap_tag>
//pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update>
//constexpr int N = 1E5 + 10, M = 1E9 + 7;
//constexpr ll INF = LLONG_MAX >> 1;
//constexpr double eps = 1E-9;

const int N = 1E5 + 10, M = 5E5 + 10, NQ = 2E5 + 10;
const int D = 18;

int n, m, q;
int n2;
vector<pii> E[N * 2];

int s[N * 2];
int dep[N * 2];
int p[D][N * 2];

void DFS(int u, int pre){
    s[u] += (u > n);
    for (auto &x: E[u]){
        int v = x.st;
        if (v == pre)
            continue;
        s[v] = s[u] + x.nd;
        dep[v] = dep[u] + 1;
        p[0][v] = u;
        for (int i = 1; i < D; ++i)
            p[i][v] = p[i - 1][p[i - 1][v]];
        DFS(v, u);
    }

    eput(u, pre, dep[u], s[u]);
}

int query_LCA(int u, int v){
    if (dep[u] < dep[v])
        swap(u, v);
    for (int t = dep[u] - dep[v], i = 0; t; ++i, t >>= 1)
        if (t & 1)
            u = p[i][u];
    if (u == v)
        return u;
    for (int i = D - 1; i >= 0; --i)
        if (p[i][u] != p[i][v])
            u = p[i][u], v = p[i][v];
    return p[0][u];
}

vector<int> F[N];
int top, sta[N];
int ts, dfn[N], low[N];

void DFS2(int u, int pre){
    sta[++top] = u;
    dfn[u] = low[u] = ++ts;
    eput(u, pre, ts);
    for (auto &v: F[u]){
        if (!dfn[v]){
            DFS2(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]){
                eput(u, v);
                ++n2;
                do{
                    int v = sta[top];
                    E[v].emplace_back(n2, 0);
                    E[n2].emplace_back(v, 0);
                }
                while (sta[top--] != v);
                E[u].emplace_back(n2, 0);
                E[n2].emplace_back(u, 0);
            }
        }
        else if (v != pre)
            low[u] = min(low[u], dfn[v]);
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        F[u].emplace_back(v);
        F[v].emplace_back(u);
    }

    n2 = n;
    DFS2(1, 0);
    for (int i = 1; i <= n; ++i)
        eput(i, E[i]);

    DFS(1, 0);
    for (int i = 0; i < q; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        int w = query_LCA(u, v);
        eput(u, v, w);
        int ans = s[u] + s[v] - s[w] * 2 + (w > n);
        printf("%d\n", ans);
    }
    return 0;
}