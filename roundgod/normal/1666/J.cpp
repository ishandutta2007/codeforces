// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
// const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=307;
const int K=360*10000;
mt19937 rng(1234);

int n,dp[N][N],c[N][N],sum[N][N],idx[N][N],par[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep1(i,n) rep1(j,n) cin>>c[i][j];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            sum[i][j]=c[i][j]+sum[i][j-1];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            sum[j][i]+=sum[j-1][i];
        }
    }
    auto get_ans=[&](int x1,int x2,int y1,int y2){
        return sum[x2][y2]+sum[x1][y1]-sum[x1][y2]-sum[x2][y1];
    };
    memset(idx,-1,sizeof(idx));
    for (int l=1;l<=n;++l){
        for (int i=0;i+l<=n;++i){
            dp[i][i+l]=INF;
            for (int k=i;k<i+l;++k){
                auto ret0=get_ans(0,i,i,k+1)+get_ans(i+l,n,i,k+1);
                auto ret1=get_ans(0,i,k+1,i+l)+get_ans(i+l,n,k+1,i+l);
                auto ret=get_ans(i,k+1,k,i+l);
                if (dp[i][k]+dp[k+1][i+l]+ret0+ret1+ret<dp[i][i+l]){
                    idx[i][i+l]=k, dp[i][i+l]=dp[i][k]+dp[k+1][i+l]+ret0+ret1+ret;
                }
            }
        }
    }
    memset(par,-1,sizeof(par));
    queue<pii> q;
    q.push({0,n});
    while (sz(q)){
        auto ret=q.front();
        q.pop();
        int k=idx[ret.F][ret.S];
        if (k!=ret.F){
            par[idx[ret.F][k]]=idx[ret.F][ret.S];
            q.push({ret.F,k});
        } 
        if (k+1!=ret.S){
            par[idx[k+1][ret.S]]=idx[ret.F][ret.S];
            q.push({k+1,ret.S});
        }
    } 
    rep(i,n) cout<<par[i]+1<<" ";
    return 0;
}