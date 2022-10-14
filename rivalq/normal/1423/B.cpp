#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double
#define fr(a,b,c) for(int a=b; a<=c; a++)


const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

struct BipartiteMatcher{
    vector<vector<int>> G;
    vector<int> L, R, Viz;
    void init(int n, int m){
        G.clear(), L.clear(), R.clear(), Viz.clear();
        G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
    }
    void AddEdge(int a, int b){if(a==0||b==0)
        return; G[a].push_back(b); }
    bool Match(int node){
        if(Viz[node]) return 0;
        Viz[node] = 1;
        for(auto vec : G[node]){
            if(R[vec] == -1 || Match(R[vec])) {
                L[node] = vec;
                R[vec] = node;
                return 1;
            }
        }
        return 0;
    }
    int Solve(){
        bool ok = 1;
        while(ok){
            ok = 0;
            fill(Viz.begin(), Viz.end(), 0);
            fr(i, 0, L.size() - 1)
                if(L[i] == -1)
                    ok |= Match(i);
        }
        int ret = 0;
        fr(i, 0, L.size() - 1)
            ret += (L[i] != -1);
        return ret;
    }
}bm;

struct E
{
    int x,y,w;
};

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<E> ed(m);
    for(int i=0;i<m;++i)
    {
        cin>>ed[i].x>>ed[i].y>>ed[i].w;
        ed[i].y += n;
    }
    sort(all(ed),[&](E a,E b){
        return a.w<b.w;
    }); 
    int lo = 1,hi = 1e9;
    int ans = -1;  
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        bm.init(n+2,m+2);
        for(auto &j:ed)
        {
            if(j.w<=mid)
                bm.AddEdge(j.x,j.y);
            else
                break;
        }
        int l = bm.Solve();
        if(l==n)
            ans = mid,hi =mid-1;
        else
            lo = mid+1;
    }
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}