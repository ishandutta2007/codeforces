// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #define int long long
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng(1234);
const int maxn=507;
const int inf=1e9;
const int mod=1e9+7;

int n,m;
string s,t;
int dp[maxn][maxn][maxn];
int trans[maxn][2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15);
    cin>>n>>m>>s>>t;
    auto brute=[&](int i,int ret){
        int mx=0;
        for (int j=1;j<=sz(t);++j){
            bool ok=1;
            if (t[j-1]!=ret+'0') continue;
            for (int k=0;k<j-1;++k){
                if (t[i-1-k]!=t[j-2-k]) ok=0;
            }
            if (ok) mx=max(mx,j);
        }
        return mx;
    };
    rep(i,sz(t)+1){
        if (i<sz(t)){
            int ret=t[i]-'0';
            trans[i][ret]=i+1;
            trans[i][ret^1]=brute(i,ret^1);
        } 
        else{
            trans[i][0]=brute(i,0);
            trans[i][1]=brute(i,1);
        }
    }
    rep(i,n+1) rep(j,n+1) rep(k,n+1) dp[i][j][k]=inf;
    dp[0][0][0]=0;
    rep(i,n){
        rep(j,n) rep(k,n){
            rep(x,2){
                dp[i+1][trans[j][x]][k+(trans[j][x]==m)]=min(dp[i+1][trans[j][x]][k+(trans[j][x]==m)],dp[i][j][k]+(s[i]!=x+'0'));
            }
        }
    }
    rep(i,n-m+2){
        int mn=inf;
        for (int j=0;j<=n;++j){
            mn=min(mn,dp[n][j][i]);
        }
        if (mn<inf) cout<<mn<<" ";
        else cout<<"-1 ";
    }
    return 0;
}