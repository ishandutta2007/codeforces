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
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> &P){
	return os << "(" << P.st << "," << P.nd << ")";}
template <class T> ostream &operator <<(ostream &os, const vector<T> &v){
	os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
	return V(b, e);}
template <class T, class c = decltype(T().begin()), typename enable_if<!is_same<T, string>::value, T>::type* = nullptr> ostream &operator <<(ostream &os, T &v){
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

const int N = 3E2 + 10, S = 1E5 + 10;

int n, m;
string a[N][N];

vector<pair<pii, pii>> ans[2];

int read_mat(){
    static char s[S];

    int ret = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            scanf("%s", s);
            a[i][j] = s;
            ret += a[i][j].size();
        }
    return ret;
}

void solve(vector<pair<pii, pii>> &ans){
    auto mv = [&](int a, int b, int c, int d){ans.emplace_back(pii(a, b), pii(c, d));};
    for (auto c: a[1][m])
        c == '0' ? mv(1, m, 1, 1) : mv(1, m, n, m);
    for (auto c: a[n][1])
        c == '0' ? mv(n, 1, 1, 1) : mv(n, 1, n, m);
    for (int j = 2; j < m; ++j){
        for (auto c: a[1][j])
            c == '0' ? mv(1, j, 1, 1) : (mv(1, j, 1, m), mv(1, m, n, m));
        for (auto c: a[n][j])
            c == '0' ? (mv(n, j, n, 1), mv(n, 1, 1, 1)) : mv(n, j, n, m);
    }
    for (int i = 2; i < n; ++i){
        for (auto c: a[i][1])
            c == '0' ? mv(i, 1, 1, 1) : (mv(i, 1, n, 1), mv(n, 1, n, m));
        for (auto c: a[i][m])
            c == '0' ? (mv(i, m, 1, m), mv(1, m, 1, 1)) : mv(i, m, n, m);
    }
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j)
            for (auto c: a[i][j])
                c == '0' ? (mv(i, j, 1, j), mv(1, j, 1, 1)) : (mv(i, j, n, j), mv(n, j, n, m));
    for (auto c: a[1][1])
        mv(1, 1, 1, m), c == '0' ? mv(1, m, 1, 1) : mv(1, m, n, m);
    for (auto c: a[n][m])
        mv(n, m, 1, m), c == '0' ? mv(1, m, 1, 1) : mv(1, m, n, m);
}

int main(){
    scanf("%d%d", &n, &m);

    read_mat();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            reverse(all(a[i][j]));

    solve(ans[0]);

    read_mat();

    solve(ans[1]);
    reverse(all(ans[1]));
    for (auto &x: ans[1])
        swap(x.st, x.nd);

    printf("%d\n", ans[0].size() + ans[1].size());
    for (auto &x: ans[0])
        printf("%d %d %d %d\n", x.st.st, x.st.nd, x.nd.st, x.nd.nd);
    for (auto &x: ans[1])
        printf("%d %d %d %d\n", x.st.st, x.st.nd, x.nd.st, x.nd.nd);
    return 0;
}