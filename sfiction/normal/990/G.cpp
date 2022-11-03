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

const int N = 2E5 + 10, W = 2E5 + 10;

int a[N];
pii e[N];
vector<int> b[W];
int fa[N];

ll cnt[W];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[i] = pii(u, v);
        int w = __gcd(a[u], a[v]);
        int j = 1;
        for (; j * j < w; j += 1)
            if (w % j == 0){
                b[j].push_back(i);
                b[w / j].push_back(i);
            }
        if (j * j == w)
            b[j].push_back(i);
    }
    fill_n(fa + 1, n, -1);
    vector<int> cl;
    function<int(int)>find = [&](int x){return fa[x] < 0 ? x : (fa[x] = find(fa[x]));};
    for (int i = 1; i < W; ++i){
        cl.clear();
        for (auto ei: b[i]){
            auto x = e[ei];

            cl.push_back(x.st);
            cl.push_back(x.nd);
            int u = find(x.st), v = find(x.nd);
            cnt[i] += (ll)fa[u] * fa[v];
            if (fa[u] < fa[v])
                fa[u] += fa[v], fa[v] = u;
            else
                fa[v] += fa[u], fa[u] = v;
        }

        for (auto &x: cl)
            fa[x] = -1;
    }
    for (int i = W - 1; i >= 1; --i)
        for (int j = i * 2; j < W; j += i)
            cnt[i] -= cnt[j];
    for (int i = 1; i <= n; ++i)
        cnt[a[i]] += 1;
    for (int i = 1; i < W; ++i)
        if (cnt[i])
            printf("%d %lld\n", i, cnt[i]);
    return 0;
}