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

const int N = 5E5 + 10, NP = 1E2 + 10;

int n, K, P;
int a[N], sa[N];
int f[N];

struct Node{
    int val, t;
}s[NP << 2];
int m;

int tt[NP];

inline void init(){
    int tm = m << 1;
    ++m;
    for (int i = 1; i < tm; ++i)
        s[i].val = -N, s[i].t = 0;
}

inline void collect(int u){
    s[u].val = max(s[u << 1].val, s[u << 1 | 1].val) + s[u].t;
}

inline void update(int u, int val){
    u += m;
    for (int v = u >> 1; v > 0; v >>= 1)
        val -= s[v].t;
    if (s[u].val < val){
        s[u].val = val;
        for (int v = u >> 1; v > 0; v >>= 1)
            collect(v);
    }
}

inline void updateR(int l, int r){
    l += m - 1, r += m + 1;
    
    for (; l ^ r ^ 1; l >>= 1, r >>= 1, collect(l), collect(r)){
        if (~l & 1)
            s[l + 1].val += 1, s[l + 1].t += 1;
        if (r & 1)
            s[r - 1].val += 1, s[r - 1].t += 1;
    }

    l >>= 1;
    for (; l > 0; l >>= 1)
        collect(l);
}

int main(){
    scanf("%d%d%d", &n, &K, &P);

    for (int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        a[i] %= P;
        sa[i] = (sa[i - 1] + a[i]) % P;
    }
    if (n >= K * P){
        for (int i = 1; i <= n; ++i){
            int t = sa[i];
            for (int j = 0; j <= t; ++j)
                tt[t] = max(tt[t], tt[j] + 1);
        }
        printf("%d\n", sa[n] + (tt[sa[n]] >= K ? 0 : P));
        return 0;
    }

    fill_n(f + 1, n, -N);
    m = 1 << 32 - __builtin_clz(P + 1);
    for (int k = 1; k <= K; ++k){
        init();

        int last = f[k - 1];
        for (int i = k; i <= n; ++i){
            // bias = sa[i - 1]
            update(sa[i - 1], last);
            if (a[i]){
                int l = (sa[i - 1] + 1) % P, r = (sa[i]) % P;
                if (l <= r)
                    updateR(l, r);
                else{
                    updateR(0, r);
                    updateR(l, P - 1);
                }
            }

            last = f[i];
            f[i] = s[1].val;
        }
    }
    printf("%d\n", accumulate(a + 1, a + n + 1, 0) - P * f[n]);
    return 0;
}