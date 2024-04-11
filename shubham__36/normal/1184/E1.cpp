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

int main()
{
    ll n,m;
    cin>>n>>m;
    v64 ver(n);
    forn(i, n)
    {
        ver[i] = -1;
    }
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    vector<edge> edges(m-1);
    forn(i, m-1)
    {
        cin>>edges[i].u;
        edges[i].u--;
        cin>>edges[i].v;
        edges[i].v--;
        cin>>edges[i].w;
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    bool flg = 0;
    forn(i, m-1)
    {
        if(find(edges[i].u, ver) != find(edges[i].v, ver))
        {
            ver[find(edges[i].u, ver)] = find(edges[i].v, ver);
        }
        if(find(a, ver) != find(b, ver))
        {
            ans = edges[i].w;
        }
        else
        {
            ans = edges[i].w;
            flg = 1;
            break;
        }
    }
    if(flg == 0)
    {
        ans = 1000000000;
    }
    cout<<ans<<'\n';
    return 0;
}