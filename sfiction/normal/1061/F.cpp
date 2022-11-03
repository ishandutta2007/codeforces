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

int query(int a, int b, int c){
    printf("? %d %d %d\n", a, b, c);
    fflush(stdout);
    static char s[10];
    scanf("%s", s);
    return s[0] == 'Y';
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    random_device rd;
    mt19937 gen(rd());

    int u, v;
    vector<int> dep(1, 1);
    for (; dep.back() < n; )
        dep.emplace_back(dep.back() * k + 1);
    int m = dep.size() - 1;
    while (true){
        u = gen() % n;
        v = gen() % (n - 1);
        v += v >= u;
        u += 1, v += 1;

        int su = 0;
        for (int i = 1; i <= n; ++i)
            su += query(i, u, v);
        if (su == dep[m] - dep[m - 1])
            su = dep[m];
        int sv = 0;
        for (int i = 1; i <= n; ++i)
            sv += query(i, v, u);
        if (sv == dep[m] - dep[m - 1])
            sv = dep[m];
        vector<int> a;
        for (int i = 1; i <= n; ++i)
            if (i != u && i != v && query(u, i, v))
                a.push_back(i);

        int lu = lower_bound(all(dep), su) - dep.begin();
        int lv = lower_bound(all(dep), sv) - dep.begin();

        eput(su, sv, lu, lv, a);
        if (dep[lu] == su && dep[lv] == sv && lu + lv + a.size() == m * 2 - 1){
            int loc = m - lu;
            sort(all(a), [&](int l, int r){return query(u, l, r);});
            int rt = loc == 0 ? u :
                        loc > a.size() ? v : a[loc - 1];
            printf("! %d\n", rt);
            fflush(stdout);
            break;
        }
    }

    return 0;
}