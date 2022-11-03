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

int a[N], b[N];
int s[N];

int main(){
    ll sy, A, B;
    scanf("%lld%lld%lld", &sy, &A, &B);
    int n;
    scanf("%d", &n);
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", a + i, b + i);
        s[i] = s[i - 1] + (b[i] - a[i]);
    }
    a[n + 1] = b[n + 1] = 1e9 + 10;
    s[n + 1] = s[n];
    
    int q;
    scanf("%d", &q);
    while (q--){
        int x, y;
        scanf("%d%d", &x, &y);

        double l = (double)(x * -sy + A * y) / (y - sy);
        double r = (double)(x * -sy + B * y) / (y - sy);
        double tot = r - l;

        int i = upper_bound(a, a + n + 2, l) - a - 1;
        int j = upper_bound(a, a + n + 2, r) - a - 1;
        eput(l, r);
        if (b[i] < l)
            l = b[i];
        if (b[j] < r)
            r = b[j];

        eput(l, r, i, j);

        double cover = i == j ? r - l : s[j - 1] - s[i] + (b[i] - l) + (r - a[j]);
        double ans = cover / tot * (B - A);
        printf("%.12f\n", ans);
    }
    return 0;
}