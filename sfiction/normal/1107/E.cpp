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

const int N = 1E2 + 10;

int n;
char s[N];
int a[N];
ll f[N][N], g[N][N];

int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        f[i][i] = a[1];
    for (int l = n - 1; l >= 1; --l){
        for (int ch = '0'; ch <= '1'; ++ch){
            int tn = n - l + 1;
            fill_n(g[l], tn + 1, LLONG_MIN);
            g[l][0] = f[l][l];
            if (s[l] == ch)
                g[l][1] = 0;
            for (int r = l + 1; r <= n; ++r){
                fill_n(g[r], tn + 1, LLONG_MIN);
                if (s[r] == ch){
                    for (int j = 1; j <= tn; ++j)
                        g[r][j] = max(g[r][j], g[r - 1][j - 1]);
                }
                for (int i = l + 1; i <= r; ++i){
                    int len = r - i + 1;
                    for (int j = 0; j <= tn; ++j)
                        g[r][j] = max(g[r][j], g[r - len][j] + f[i][r]);
                }

                for (int j = 0; j <= tn; ++j)
                    f[l][r] = max(f[l][r], g[r][j] + a[j]);
            }
        }
    }
    printf("%lld\n", f[1][n]);
    return 0;
}