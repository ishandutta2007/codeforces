#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define x               first
#define y               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 100005;

ld dp[N][10][2];

pair<int,int> par[N][10][2];

int a[N];

int runtimeTerror()
{
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=0;i<=n;++i)
        for(int j=0;j<=9;++j)
            dp[i][j][0] = dp[i][j][1] = -INF;
    dp[0][1][0] = 0;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=9;++j)
        {
            if(dp[i+1][j][0] < dp[i][j][0]){
                    dp[i+1][j][0] = dp[i][j][0];
                    par[i+1][j][0] = {j,0};
            } 
            if(dp[i+1][j][0] < dp[i][j][1]){
                    dp[i+1][j][0] = dp[i][j][1];
                    par[i+1][j][0] = {j,1};
            }   
            int new_st = j*a[i+1]%10;
            if(dp[i+1][new_st][1] < dp[i][j][0] + log2(a[i+1])){
                    dp[i+1][new_st][1] = dp[i][j][0] + log2(a[i+1]);
                    par[i+1][new_st][1] = {j,0};
            } 
            if(dp[i+1][new_st][1] < dp[i][j][1] + log2(a[i+1])){
                    dp[i+1][new_st][1] = dp[i][j][1] + log2(a[i+1]);
                    par[i+1][new_st][1] = {j,1};
            }    
        }
    }
    pair<ld,pii>mx = {dp[n][d][0],{d,0}};
    amax(mx,make_pair(dp[n][d][1],make_pair(d,1)));
    if(mx.x < 0 || abs(mx.x) <= 1e-8)
    {
        cout<<"-1\n";return 0;
    }
    //cout << pow(2,mx.x) << endl;
    vector<int>v;
    int cur = n;
    pair<int,int>pt = mx.y;
    while(cur > 0){
            if(pt.y){
                    v.push_back(a[cur]);
            }
            pt = par[cur][pt.x][pt.y];
            cur--;   
    }
    cout << v.size() << endl;
    for(auto i:v)cout << i << " ";
        cout << endl;
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
        runtimeTerror();
    return 0;
}