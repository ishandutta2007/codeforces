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

using pli = pair<ll, int>;

const int N = 5E5 + 10;

int n;
pair<pii, int> b[N];
vector<int> c;

struct node{
    pli s;
    ll t;
}a[N << 2];

void build(int u, int l, int r){
    if (l + 1 == r){
        a[u].s = pli(LLONG_MIN, c[l]);
        return;
    }
    int m = l + r >> 1;
    build(u << 1, l, m);
    build(u << 1 | 1, m, r);
    a[u].s = max(a[u << 1].s, a[u << 1 | 1].s);
}

void pushDown(int u){
    ll t = a[u].t;
    a[u << 1].s.st += t;
    a[u << 1].t += t;
    a[u << 1 | 1].s.st += t;
    a[u << 1 | 1].t += t;
    a[u].t = 0;
}

void update1(int u, int l, int r, int L){
    if (l + 1 == r){
        a[u].s.st = c[l];
        return;
    }
    pushDown(u);
    int m = l + r >> 1;
    if (L < m)
        update1(u << 1, l, m, L);
    else
        update1(u << 1 | 1, m, r, L);
    a[u].s = max(a[u << 1].s, a[u << 1 | 1].s);
}

void update(int u, int l, int r, int L, int R, int C){
    if (L <= l && r <= R){
        a[u].s.st += C;
        a[u].t += C;;
        return;
    }
    pushDown(u);
    int m = l + r >> 1;
    if (L < m)
        update(u << 1, l, m, L, R, C);
    if (m < R)
        update(u << 1 | 1, m, r, L, R, C);
    a[u].s = max(a[u << 1].s, a[u << 1 | 1].s);
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        if (x < y)
            swap(x, y);
        b[i] = make_pair(pii(x, y), c);

        ::c.push_back(y);
    }
    sort(b, b + n);
    sort(all(c));
    c.erase(unique(all(c)), c.end());

    int m = c.size();
    build(1, 0, m);
    pair<ll, pii> ans(-1, pii(0, 0));
    for (int i = 0; i < m; ++i)
        if (i != c[i])
            ans = make_pair(0, pii(i, i));
    if (ans.st == -1)
        ans = make_pair(0, pii(1e9, 1e9));
    for (int r = 0, i = 0, j; i < n; i = j){
        int x = b[i].st.st;
        for (; r < m && c[r] <= x; ++r)
            update1(1, 0, m, r);

        for (j = i;  j < n && b[j].st.st == x; ++j){
            int t = lower_bound(all(c), b[j].st.nd) - c.begin();
            update(1, 0, m, 0, t + 1, b[j].nd);
        }
        
        eput(b[i], a[1].s);
        ans = max(ans, make_pair(a[1].s.st - x, pii(a[1].s.nd, x)));
    }
    printf("%lld\n", ans.st);
    printf("%d %d %d %d\n", ans.nd.st, ans.nd.st, ans.nd.nd, ans.nd.nd);
    return 0;
}