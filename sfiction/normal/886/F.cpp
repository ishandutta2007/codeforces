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

const int N = 2E3 + 10;

int n;
ll x[N], y[N];
ll sx, sy;

bool sym(const multiset<ll> &a){
    multiset<ll> b;
    for (auto &x: a)
        b.emplace(-x);
    return a == b;
}

bool checkc(ll cx, ll cy){
    multiset<ll> lst;
    eput(cx, cy);
    for (int i = 0; i < n; ++i)
        lst.emplace(cx * x[i] + cy * y[i]);
    eput(lst);
    return sym(lst);
}

ll gcd(ll a, ll b){
    ll t;
    while (b != 0){ 
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", x + i, y + i);
    ll sx = accumulate(x, x + n, 0ll);
    ll sy = accumulate(y, y + n, 0ll);
    for (int i = 0; i < n; ++i)
        x[i] = n * x[i] - sx, y[i] = n * y[i] - sy;

    for (int i = 0; i < n; ++i){
        if (x[0] == 0 && y[0] == 0){
            --n;
            x[i] = x[n], y[i] = y[n];
            --i;
            continue;
        }

        int j = i + 1;
        for (; j < n && !(x[i] == -x[j] && y[i] == -y[j]); ++j);
        if (j < n){
            --n;
            x[j] = x[n], y[j] = y[n];
            --n;
            x[i] = x[n], y[i] = y[n];
            --i;
        }
    }
    
    if (n == 0){
        puts("-1");
        return 0;
    }

    eput(gr(x, x + n));
    eput(gr(y, y + n));

    set<pll> lst;
    x[n] = y[n] = 0;
    for (int i = 1; i <= n; ++i){
        ll a = -(y[0] + y[i]), b = x[0] + x[i];
        ll d = gcd(a, b);
        a /= d, b /= d;

        if (a < 0)
            a = -a, b = -b;
        if (checkc(a, b))
            lst.emplace(a, b);
    }
    printf("%d\n", (int)lst.size());
    return 0;
}