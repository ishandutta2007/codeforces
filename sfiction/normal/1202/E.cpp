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
template <class T, class c = decltype(T().begin()), typename enable_if<!is_same<T, string>::value>::type* = nullptr> ostream &operator <<(ostream &os, const T &v){
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

const int N = 2E5 + 10, L = 2E5 + 10;

int n;
char buf[L];
string t;
vector<string> s;

vector<int> E[L * 2];
int cnt[L * 2];

constexpr int C = 26;
struct node{
    int len;
    node *fa, *a[C];
    node(int len = 0): len(len), fa(nullptr){
        memset(a, 0, sizeof(a));
    }
    node* extend(node *rt, int t);
}pool[L * 2], *pr;

node* node::extend(node *rt, int t){
    node *p = this, *np = new(pr++) node(len + 1);
    for (; p && !p->a[t]; p = p->fa)
        p->a[t] = np;
    if (!p)
        np->fa = rt;
    else{
        node *q = p->a[t];
        if (p->len + 1 == q->len)
            np->fa = q;
        else{
            node *nq = new(pr++) node(p->len + 1);
            memcpy(nq->a, q->a, sizeof(q->a));
            nq->fa = q->fa;
            np->fa = q->fa = nq;
            for (; p && p->a[t] == q; p = p->fa)
                p->a[t] = nq;
        }
    }
    return np;
}

void DFS(int u, int pre){
    for (auto &v: E[u]){
        if (v == pre)
            continue;
        cnt[v] += cnt[u];
        DFS(v, u);
    }
}

vector<int> solve(const string &t, const vector<string> &s){
    pr = pool;
    node *rt = new(pr++) node(0), *p = rt;
    for (auto &c: t){
        p = p->extend(rt, c - 'a');
    }
    int m = pr - pool;
    for (int i = 0; i < m; ++i)
        E[i].clear();
    for (int i = 1; i < m; ++i){
        E[pool[i].fa - pool].push_back(i);
    }
    fill_n(cnt, m, 0);
    for (auto &x: s){
        node *t = rt;
        for (int i = 0; t && i < x.size(); t = t->a[x[i] - 'a'], ++i);
        if (t)
            ++cnt[t - pool];
    }

    DFS(0, -1);

    vector<int> res(t.size());
    node *x = rt;
    for (int i = 0; i < t.size(); x = x->a[t[i] - 'a'], ++i)
        res[i] = cnt[x - pool];
    return res;
}

int main(){
    scanf("%s", buf);
    t = string(buf);
    int m = t.size();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%s", buf);
        s.emplace_back(buf);
    }
    
    auto a = solve(t, s);
    reverse(all(t));
    for (auto &x: s)
        reverse(all(x));
    auto b = solve(t, s);
    ll ans = 0;
    for (int i = 1; i < m; ++i)
        ans += (ll)a[i] * b[m - i];
    printf("%lld\n", ans);
    return 0;
}