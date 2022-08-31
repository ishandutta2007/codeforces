#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

struct edge
{
    ll w;
    ll u;
    ll v;
    ll ind;
    bool operator<(const edge other)
    {
        return w < other.w;
    }
};

int find(ll v, vector<ll>& arr)
{
    if(arr[v] == -1)
    {
        return v;
    }
    else
    {
        arr[v] = find(arr[v], arr);
        return arr[v];
    }
}

void dfs(vv64& tr, vv64& cs, vp64& ances, v64& vis, v64& L,ll anc, ll cost, ll v, ll lv)
{
    if(vis[v] != -1)
    {
        return;
    }
    else
    {
        vis[v] = 0;
        L[v] = lv;
        ances[v].ff = anc;
        ances[v].ss = cost;
        for(ll i = 0; i < tr[v].size(); i++)
        {
            dfs(tr,cs,ances,vis,L,v,cs[v][i],tr[v][i], lv+1);
        }
    }
}

void process3(ll N, vp64& T, vector<vp64>& P)
{
    ll i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; 1 << j < N; j++)
        {
            P[i][j].ff = -1;
            P[i][j].ss = -1;
        }
    }

    //the first ancestor of every node i is T[i]
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    //bottom up dynamic programing
    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (P[i][j - 1].ff != -1)
            {
                P[i][j].ff = P[P[i][j - 1].ff][j - 1].ff;
                P[i][j].ss = max(P[i][j-1].ss, P[P[i][j - 1].ff][j - 1].ss);
            }
        }
    }
}

ll query(ll N, vector<vp64>& P, vp64& T, v64& L, ll p, ll q)
{
    ll tmp, log, i, mxQuan = -1;

    //if p is situated on a higher level than q then we swap them
    if (L[p] < L[q])
    tmp = p, p = q, q = tmp;

    //we compute the value of [log(L[p)]
    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    //we find the ancestor of node p situated on the same level
    //with q using the values in P
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
        {
            mxQuan = max(mxQuan, P[p][i].ss);
            p = P[p][i].ff;
        }

    if (p == q)
        return mxQuan;

    //we compute LCA(p, q) using the values in P
    for (i = log; i >= 0; i--)
        if (P[p][i].ff != -1 && P[p][i].ff != P[q][i].ff)
        {
            mxQuan = max(mxQuan, P[p][i].ss);
            mxQuan = max(mxQuan, P[q][i].ss);
            p = P[p][i].ff;
            q = P[q][i].ff;
        }

    return max(mxQuan, max(T[p].ss, T[q].ss));
}


int main()
{
    ll n,m;
    cin>>n>>m;
    v64 ver(n);
    forn(i, n)
    {
        ver[i] = -1;
    }
    vector<edge> edges(m);
    vector<edge> edges1(m);
    vector<edge> tree;
    v64 rejec(m);
    forn(i, m)
    {
        cin>>edges[i].u;
        edges[i].u--;
        cin>>edges[i].v;
        edges[i].v--;
        cin>>edges[i].w;
        edges[i].ind = i;
    }
    edges1 = edges;
    sort(edges.begin(), edges.end());
    forn(i, m)
    {
        if(find(edges[i].u, ver) != find(edges[i].v, ver))
        {
            ver[find(edges[i].u, ver)] = find(edges[i].v, ver);
            tree.pb(edges[i]);
            rejec[edges[i].ind] = 0;
        }
        else
        {
            rejec[edges[i].ind] = 1;
        }
    }
    vv64 tr(n);
    vv64 cs(n);
    forn(i, n-1)
    {
        tr[tree[i].u].pb(tree[i].v);
        cs[tree[i].u].pb(tree[i].w);
        tr[tree[i].v].pb(tree[i].u);
        cs[tree[i].v].pb(tree[i].w);
    }
    v64 vis(n);
    v64 L(n);
    forn(i, n)
    {
        vis[i] = -1;
    }
    vp64 ances(n);
    dfs(tr, cs, ances, vis, L, -1, -1, 0, 0);
    vector<vp64> lca(n);
    forn(i, n)
    {
        lca[i].resize(log(n+20)+20);
    }
    process3(n, ances, lca);
    forn(i, m)
    {
        if(rejec[i])
        {
            cout<<query(n, lca, ances, L, edges1[i].u, edges1[i].v)<<'\n';;
        }
    }
    return 0;
}