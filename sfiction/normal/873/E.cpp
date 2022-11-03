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

const int N = 3E3 + 10;

int n;
pii a[N];
pii val[N][N];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i].st);
        a[i].nd = i;
    }
    sort(a, a + n, greater<pii>());
    using result = tuple<int, int, int>;

    for (int i = 1; i <= n; ++i)
        val[i][i] = pii(a[i - 1].st - a[i].st, i);
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            val[i][j] = max(val[i][j - 1], val[j][j]);

    eput(val[7][9], val[9][9]);

    result ans(-1, -1, -1), split;
    for (int i = 1; i <= n - 2; ++i){
        int x = a[i - 1].st - a[i].st;
        if (x < get<0>(ans))
            continue;
        int lj = i + (i + 1) / 2, rj = min(n - 1, i * 3);
        for (int j = lj; j <= rj; ++j){
            int y = a[j - 1].st - a[j].st;
            int lk = j + (max(i, j - i) + 1) / 2, rk = min(n, j + min(i, j - i) * 2);
            if (lk <= rk){
                int z = val[lk][rk].st, k = val[lk][rk].nd;
                eput(i, j, x, y, lk, rk, z, k);
                result t(x, y, z);
                if (ans < t){
                    ans = t;
                    split = result(i, j, k);
                }
            }
        }
    }
    
    int i, j, k;
    tie(i, j, k) = split;
    for (int l = 0; l < n; ++l)
        a[l].st = l < i ? 1 : l < j ? 2 : l < k ? 3 : -1;
    sort(a, a + n, [](const pii &l, const pii &r){return l.nd < r.nd;});
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i].st, "\n "[i + 1 < n]);

    return 0;
}