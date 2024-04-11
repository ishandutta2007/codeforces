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

const int N = 5E5 + 10;

char s[N], t[N];
int n, m, K;
vector<int> a;

int allmat = -1;

vector<int> solve(char *s, int n, char *t, int m, int K){
    static int fa[N]{-1};
    for (int j, i = 1; i < m; ++i){
        for (j = fa[i - 1]; j >= 0 && t[j + 1] != t[i]; j = fa[j]);
        fa[i] = t[j + 1] == t[i] ? j + 1 : -1;
    }
    eput(string(s, n));
    eput(string(t, m));
    eput(gr(fa, fa + m));
    vector<int> res(m, INT_MAX);
    for (int j = -1, i = 0; i < n; ++i){ 
        for (; j >= 0 && t[j + 1] != s[i]; j = fa[j]);
        j += t[j + 1] == s[i];
        eput(i, j);
        if (j >= 0 && i >= K - 1 && j < K){
            mini(res[j], i);
            res[j] = min(res[j], i);
        }

        if (j == m - 1 && allmat == -1)
            allmat = i;
    }
    for (int i = m - 1; i > 0; --i)
        if (fa[i] >= 0)
            mini(res[fa[i]], res[i]);
    eput(res);
    return res;
}

int main(){
    scanf("%d%d%d", &n, &m, &K);
    scanf("%s", s);
    scanf("%s", t);

    a = solve(s, n, t, m, K);
    reverse(s, s + n);
    reverse(t, t + m);
    auto b = solve(s, n, t, m, K);

    reverse(all(b));
    for (auto &x: b)
        x = n - 1 - x;

    eput(a);
    eput(b);

    pii ans(-1, -1);
    if (allmat != -1){
        int l = max(0, allmat - 2 * K + 1);
        ans = pii(l, l + K);
    }
    for (int i = 1; i < m; ++i)
        if (a[i - 1] < b[i])
            ans = pii(a[i - 1] - K + 1, b[i]);
    
    if (ans.st == -1)
        puts("No");
    else
        printf("Yes\n%d %d\n", ans.st + 1, ans.nd + 1);
    return 0;
}