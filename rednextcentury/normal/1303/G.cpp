#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        if (empty())return 0;
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
} cht;
int sz[1000000];
bool done[1000000];
vector<int> adj[1000000];
void pre(int v,int p)
{
    sz[v]=1;
    for (auto u:adj[v]){
        if (done[u] || u==p)continue;
        pre(u,v);
        sz[v]+=sz[u];
    }
}
int tot;
int best,node;
void get_centroid(int v,int p)
{
    int mx = tot-sz[v];
    for (auto u:adj[v]){
        if (done[u] || u==p)continue;
        get_centroid(u,v);
        mx=max(mx,sz[u]);
    }
    if (mx<best)best=mx,node=v;
}
ll a[1000000];
long long ret=0;
ll cur;
ll sum;
void Add(int v,int p,ll dep) {
    cur+=a[v]*(dep+1);
    sum+=a[v];
    cht.add(sum, cur);
    for (auto u:adj[v]) {
        if (done[u] || u==p)continue;
        Add(u,v,dep+1);
    }
    sum-=a[v];
    cur-=a[v]*(dep+1);
}
void process(int v,int p,ll S, ll val, int dep){
    S+=a[v];
    val+=S;
    ret=max(ret, val + cht.query(dep));
    for (auto u:adj[v]) {
        if (done[u] || u==p)continue;
        process(u,v,S,val,dep+1);
    }
}
void centroid(int v=1)
{
    best=1e9,node=-1;
    pre(v,0);
    tot=sz[v];
    get_centroid(v,0);
    v=node;
    done[v]=1;
    cht.clear();
    for (auto u:adj[v]) {
        if (!done[u]){
            sum=a[v];
            cur=a[v];
            process(u,0,0,0,1);
            Add(u,0,1);
        }
    }
    reverse(adj[v].begin(),adj[v].end());
    cht.clear();
    for (auto u:adj[v]) {
        if (!done[u]){
            sum=a[v];
            cur=a[v];
            process(u,0,0,0,1);
            Add(u,0,1);
        }
    }
    for (auto u:adj[v]) {
        if (!done[u])centroid(u);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    centroid();
    cout<<ret<<endl;
}