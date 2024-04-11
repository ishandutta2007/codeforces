#include "bits/stdc++.h"
#define rep(i, a, n) for(auto i = a; i <= (n); i++)
#define per(i, a, n) for(auto i = n; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;
 
template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v)
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }
 
void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif
 
using ll = long long;
// using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using db = double;
using ldb = long double;
 
const int maxn = 100'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
 
template<class T, T INF> struct Segtree
{
    #define ls i * 2
    #define rs i * 2 + 1
    using vt = vector<T>;
    int n;
    vector<pair<T, int>> a;
    vt lz;
    void pu(int i) 
    {
        a[i] = max(a[ls], a[rs]); // change here if you want maximum value / the rightist index.
    }
    void build(int i, int l, int r, vt &vec)
    {
        lz[i] = 0;
        if(l == r) a[i] = {vec[l], l};
        else
        {
            int mid = (l + r) >> 1;
            build(ls, l, mid, vec);
            build(rs, mid + 1, r, vec);
            pu(i);
        }
    }
    void push(int i, T x)
    {
        a[i].FI += x;
        lz[i] += x;
    }
    void pd(int i)
    {
        if(lz[i])
        {
            push(ls, lz[i]);
            push(rs, lz[i]);
            lz[i] = 0;
        }
    }
    void add(int i, int l, int r, int ql, int qr, T x)
    {
        if(ql <= l && r <= qr)
        {
            push(i, x);
            return;
        }
        if(qr < l || r < ql) return;
        int mid = (l + r) >> 1;
        pd(i);
        add(ls, l, mid, ql, qr, x);
        add(rs, mid + 1, r, ql, qr, x);
        pu(i);
    }
    pair<T, int> ask(int i, int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr) return a[i];
        if(qr < l || r < ql) return mp(INF, -1);
        int mid = (l + r) >> 1;
        pd(i);
        return max(ask(ls, l, mid, ql, qr), ask(rs, mid + 1, r, ql, qr)); // change here if you want maximum value / the rightist index.
    }
    
    Segtree(vt &vec): n(sz(vec)), a(n * 4 + 5), lz(n * 4 + 5)
    {
        build(1, 0, n - 1, vec);
    }
    void RangeAdd(int ql, int qr, T x) { add(1, 0, n - 1, ql, qr, x); }
    auto RangeMin(int ql, int qr) { return ask(1, 0, n - 1, ql, qr); }
 
    #undef ls
    #undef rs
};
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
 
    int cas; cin >> cas; while(cas--)
    {
        int n; cin >> n;
        struct node { int c, l, r; };
        vector<node> a(n);
        for(auto &[c, l, r]: a) cin >> c >> l >> r;
        sort(all(a), [&](node a, node b){ return a.l < b.l; });
        vi vec(n);
        rep(i, 0, n - 1) vec[i] = a[i].l;
        vvi R(2, vi(n));
        rep(c, 0 ,1) rep(i, 0, n - 1) R[c][i] = -inf;
        rep(i, 0, n - 1)
        {
            auto [c, l, r] = a[i];
            R[c][i] = r;
        }
        vector<Segtree<int, -inf>> segt{R[0], R[1],R[0],R[1]}; // change to use vector
        int ans = 0;
        vi dis(n, inf);
        rep(st, 0, n - 1) if(dis[st] == inf)
        {
            ans++;
            dis[st] = 0;
            queue<int> q; q.push(st);
            while(sz(q))
            {
                int now = q.front(); q.pop();
                auto [c, l, r] = a[now];
                auto pos = upper_bound(all(vec), r) - vec.begin() - 1;
                while(1)
                {
                    auto [val, id] = segt[c ^ 1].RangeMin(0, pos);
                    if(val < l) break;
                    segt[c ^ 1].RangeAdd(id, id, -inf);
                    if(chmin(dis[id], dis[now] + 1)) q.push(id);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}