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

const int N = 1E5 + 10;
const int M = 1E9 + 7;

char s[N], t[N];
int cnt[4];

ll inv[N], fac[N], finv[N];

void prework(int n = N - 1, int m = M){
    inv[0] = 0, inv[1] = 1;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i <= n; ++i){
        inv[i] = inv[m % i] * (m - m / i) % m;
        fac[i] = fac[i - 1] * i % m;
        finv[i] = finv[i - 1] * inv[i] % m;
    }
}

int C(int n, int m){
    return 0 <= m && m <= n ? fac[n] * finv[m] % M * finv[n - m] % M : 0;
}

int check(const char *s, const int (&cnt)[4]){
    int a[4]{0};
    for (const char *p = s + 1; *p; ++p)
        ++a[p[-1] - '0' << 1 | p[0] - '0'];
    bool ret = true;
    for (int i = 0; i < 4; ++i)
        ret &= cnt[i] == a[i];
    return ret;
}

template <typename T>
int calc(const T& a, int pre){
    int t[2];
    if (a[1] == a[2] || a[1] + pre == a[2] + !pre)
        t[0] = a[2] + !pre, t[1] = a[1] + pre;
    else
        t[0] = t[1] = -1;
    eput(a[0], a[1], a[2], a[3]);
    eput(gr(t, t + 2));
    int A = a[0] == 0 && t[0] == 0 ? 1 : C(a[0] + t[0] - 1, t[0] - 1);
    int B = a[3] == 0 && t[1] == 0 ? 1 : C(a[3] + t[1] - 1, t[1] - 1);
    int ret = (ll)A * B % M;
    eput(ret);
    return ret;
}

int solve(const char *s, const int (&cnt)[4]){
    int n = strlen(s);
    int tn = accumulate(cnt, cnt + 4, 0);
    if (n - 1 != tn){
        return n - 1 < tn ? 0 : calc(cnt, 1);
    }

    vector<int> a(cnt, cnt + 4);
    ll ans = 0;
    for (int i = 1; i < n; ++i){
        int cur = s[i - 1] - '0' << 1 | s[i] - '0';
        if (s[i] == '1'){
            --a[cur - 1];
            ans += calc(a, 0);
            ++a[cur - 1];
        }

        --a[cur];
    }

    ans %= M;
    return ans;
}

int main(){
    prework();

    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; i < 4; ++i)
        scanf("%d", cnt + i);
    int ans = (solve(t, cnt) - solve(s, cnt) + M + check(t, cnt)) % M;
    printf("%d\n", ans);
    return 0;
}