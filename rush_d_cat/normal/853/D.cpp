#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)
const int N=300000+10;
const int INF=1e9+7;
const double EPS = 1e-8;
int n,a[N];
int dp[N][102];
int main(){
    rd(n);
    rep(i,1,n) rd(a[i]),a[i]/=100;
    rep(i,0,n) rep(j,0,50) dp[i][j]=INF;
    dp[0][0]=0;

    int ret=INF;
    rep(i,1,n) {
        rep(j,0,50) {
            dp[i][j] = INF;
            if(j>=a[i]/10) dp[i][j] = min(dp[i-1][j-a[i]/10] + a[i], dp[i][j]);
            //if(dp[i][j]!=INF) printf("dp[%d][%d]=%d\n", i,j,dp[i][j]);  
            rep(k,1,a[i])  if(j+k<=50) dp[i][j] = min(dp[i-1][j+k] + a[i]-k,dp[i][j]); 
            if(i==n) ret=min(ret,dp[i][j]);
            //if(dp[i][j]!=INF) printf("dp[%d][%d]=%d\n", i,j,dp[i][j]);
        }        
    }
    printf("%lld\n", (LL)ret*100L);
}