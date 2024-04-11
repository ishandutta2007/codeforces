#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckxjb
#define y0 fuxkcjb
#define x1 fxckcjb
#define y1 fuckcxb
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e5+5,MOD=998244353,inf=0x3f3f3f3f;
const ld eps=1e-9;
int a[N],dp[N][2][205],n,ans;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    dp[0][0][1]=1;
    rep(i,n){
        rep(j,200)
            (dp[i-1][0][j]+=dp[i-1][0][j-1])%=MOD,
            (dp[i-1][1][j]+=dp[i-1][1][j-1])%=MOD;
        rep(j,200){
            dp[i][0][j]=(dp[i-1][0][j-1]+dp[i-1][1][j-1])%MOD;
            dp[i][1][j]=(0ll+dp[i-1][0][j]-dp[i-1][0][j-1]+MOD+dp[i-1][1][200]-dp[i-1][1][j-1]+MOD)%MOD;
        }
        if(a[i]!=-1)rep(j,200)if(j!=a[i])dp[i][0][j]=dp[i][1][j]=0;
    }
    rep(i,200)ans=(ans+dp[n][1][i])%MOD;
    printf("%d\n",ans);
    return 0;
}