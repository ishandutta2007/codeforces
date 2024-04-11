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

const int N = 2E5 + 10;
const ll M = 1E9 + 7;

ll fac[N], finv[N];

ll mexp(ll e, ll n, ll m = M){
    ll ret = 1;
    for (; n; n >>= 1, e = e * e % m)
        if (n & 1)
            ret = ret * e % m;
    return ret;
}

void prework(int n = N - 1){
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; ++i)
        fac[i] = fac[i - 1] * i % M;
    finv[n] = mexp(fac[n], M - 2);
    for (int i = n; i > 0; --i)
        finv[i - 1] = finv[i] * i % M;
}

ll com(ll n, ll m){
    return 0 <= m && m <= n ? fac[n] * finv[m] % M * finv[n - m] % M : 0;
}

int main(){
    prework();
    int n;
    ll T;
    scanf("%d%lld", &n, &T);
    ll s = 0, sp = 1, ans = 0;
    ll inv2 = mexp(2, M - 2), den = 1;
    int re = n;
    for (int i = 1; i <= n; ++i){
        ll x;
        scanf("%lld", &x);
        s += x;
        if (s > T)
            continue;

        sp = (sp * 2 - com(i - 1, re) + M) % M;
        den = den * inv2 % M;

        eput(i, s, T, sp, den);

        for (; s + re > T; --re)
            sp = (sp - com(i, re) + M) % M;
        ans += sp * den % M;

        eput(re, sp, den, ans);
    }
    ans %= M;
    printf("%lld\n", ans);
    return 0;
}