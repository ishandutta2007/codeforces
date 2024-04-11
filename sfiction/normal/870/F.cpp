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

const int N = 1E7 + 10;

int isnp[N];
int np, prime[N / 5];
int phi[N], cmd[N];

void getprime(int n = N - 1){
    for (int i = 2; i <= n; ++i){
        if (!isnp[i])
            prime[np++] = i, phi[i] = i - 1, ++cmd[i];
        for (int t, j = 0; j < np && (t = i * prime[j]) <= n; ++j){
            isnp[t] = true;
            ++cmd[prime[j]];
            if (i % prime[j] == 0){
                phi[t] = phi[i] * prime[j];
                break;
            }
            phi[t] = phi[i] * (prime[j] - 1);
        }
    }
}

int isqrt(int n){
    int x = n, y = (n + 1) / 2;
    while (x > y){
        x = y;
        y = (y + n / y) / 2;
    }
    return x;
}

int main(){
    int n;
    scanf("%d", &n);
    getprime(n);
    int n2 = n / 2;
    int p2 = upper_bound(prime, prime + np, n2) - prime;
    int sg = np - p2 + 1;

    eput(np, n2, p2, sg);

    ll d1 = (n - sg) * (n - sg - 1ll) / 2;
    ll d2 = d1 - (n * (n - 1ll) / 2 - accumulate(phi + 1, phi + n + 1, 0ll));

    eput(d1, d2);
    eput(gr(phi + 1, phi + n + 1));

    int nr = isqrt(n);
    int pr = upper_bound(prime, prime + np, nr) - prime;
    int npr = p2 - pr;
    ll d3 = (ll)npr * (n - sg - npr) + npr * (npr - 1ll) / 2;
    eput(nr, pr, d3);
    eput(gr(cmd, cmd + prime[pr]));
    partial_sum(cmd, cmd + prime[pr], cmd);
    for (int i = pr; i < p2; ++i)
        d3 -= cmd[n / prime[i]];

    eput(d3);
    
    ll ans = d1 + d2 + d3;
    printf("%lld\n", ans);

    return 0;
}