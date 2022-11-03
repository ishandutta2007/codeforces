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

template <class T> inline void mini(T& l, const T& r){l = min(l, r);}
template <class T> inline void maxi(T& l, const T& r){l = max(l, r);}

template <class T> void _dbg(const char* sdbg, T h){cerr << sdbg << "=" << h << "\n";}
template <class T, class ...R> void _dbg(const char* sdbg, T h, R... a){
    while (*sdbg != ','){cerr << *sdbg++;} cerr << "=" << h << ","; _dbg(sdbg + 1, a...);}
template <class L, class R> ostream& operator <<(ostream& os, const pair<L, R>& pr){
    return os << "(" << pr.st << "," << pr.nd << ")";}
template <class T> ostream& operator <<(ostream& os, const vector<T>& v){
    os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
    return V(b, e);}
template <class T, class c = decltype(T().begin()), typename enable_if<!is_same<T, string>::value>::type* = nullptr> ostream& operator <<(ostream& os, T& v){
    return os << gr(all(v));}
template <class T, int I, int N> typename enable_if<I == N, T>::type TuplePrint(ostream& os, T val){
    os << get<N>(val);}
template <class T, int I, int N> typename enable_if<I < N, T>::type TuplePrint(ostream& os, T val){
    os << get<I>(val) << ","; TuplePrint<T, I + 1, N>(os, val);}
template <class... Ts> ostream& operator<<(ostream& os, tuple<Ts...> t){
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

const int N = 1E5 + 10;
const int LIMIT = 250;

int n, m;
vector<int> c;
vector<int> E[N];
vector<int> G[N * 2];
int mark[N * 2];

int main(){
    int cas = 1;
    scanf("%d", &cas);
    for (int casi = 1; casi <= cas; ++casi){
        scanf("%d", &n);
        c.clear();
        for (int i = 0; i < n; ++i)
            E[i].clear();
        for (int i = 0; i < n; ++i){
            int m;
            scanf("%d", &m);
            E[i].resize(m);
            for (int j = 0; j < m; ++j)
                scanf("%d", &E[i][j]);
            c.insert(c.end(), all(E[i]));
        }
        sort(all(c));
        c.erase(unique(all(c)), c.end());
        m = c.size();
        for (int i = 0; i < n; ++i)
            for (auto& x: E[i])
                x = lower_bound(all(c), x) - c.begin();

        for (int i = 0; i < m; ++i)
            G[i].clear();
        fill_n(mark, max(n, m), 0);
        pii ans{-1, -1};
        for (int u = 0; u < n; ++u){
            if (E[u].size() < LIMIT){
                for (auto x: E[u]) G[x].push_back(u);
                continue;
            }
            for (auto x: E[u]) mark[x] = true;
            for (int v = 0; v < n; ++v){
                if (u == v) continue;
                int cnt = 0;
                for (auto x: E[v])
                    if (mark[x] && cnt++) {
                        ans = pii(u, v);
                        goto fin;
                    }
            }
            for (auto x: E[u]) mark[x] = false;
        }
        for (int u = 0; u < m; ++u){
            for (auto v: G[u])
                for (auto x: E[v])
                    if (x != u){
                        if (mark[x]) {
                            ans = pii(v, mark[x] - 1);
                            goto fin;
                        }
                        mark[x] = v + 1;
                    }
            for (auto v: G[u])
                for (auto x: E[v])
                    mark[x] = 0;
        }
fin:
        if (ans.st == -1)
            puts("-1");
        else
            printf("%d %d\n", ans.st + 1, ans.nd + 1);
    }
    return 0;
}