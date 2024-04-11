#include <iostream>
#include <cstring>
using namespace std;
const int N=100000+10;
const int MOD=1e9+7;

char s[N];
int n,q,x,y;
int dp[N],c[100],fac[N],inv[N];
int vis[53][53], ans[53][53], newdp[N];

int mpow(int a,int x){
    if(x==0)return 1;
    int t=mpow(a,x>>1);
    if(x%2==0)return 1LL*t*t%MOD;
    return 1LL*t*t%MOD*a%MOD;
}
int main() {
    fac[0]=1,inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]<='z' && s[i]>='a') c[s[i]-'a'+1] ++;
        else c[26+s[i]-'A'+1] ++;
    }

    dp[0]=1;
    for(int i=1;i<=52;i++) {
        if(c[i])
        for(int j=n;j>=c[i];j--)
            (dp[j] += dp[j-c[i]]) %= MOD;
    }
    int M = 1LL * fac[n/2] * fac[n/2] % MOD;
    for(int i=1;i<=52;i++)
        M=1LL*M*mpow(fac[c[i]],MOD-2)%MOD;

    scanf("%d",&q);
    while(q--){
        int x,y; scanf("%d%d",&x,&y);
        x=s[x],y=s[y];
        if(x<='z' && x>='a') x=x-'a'+1; else x=26+x-'A'+1;
        if(y<='z' && y>='a') y=y-'a'+1; else y=26+y-'A'+1;
        if(x>y) swap(x,y);

        if(vis[x][y]) {
            printf("%lld\n", 1LL * ans[x][y] * M % MOD); continue;
        } 

        vis[x][y]=1; 
        for(int i=0;i<=n;i++) {
            //printf("dp[%d]=%d\n", i,dp[i]);
            newdp[i]=dp[i];
        }
        for(int i=c[x];i<=n;i++) newdp[i] = (newdp[i] - newdp[i-c[x]] + MOD) % MOD;
        if(x!=y) for(int i=c[y];i<=n;i++) newdp[i] = (newdp[i] - newdp[i-c[y]] + MOD) % MOD;
        ans[x][y]=2*newdp[n/2]%MOD;
        printf("%lld\n", 1LL * ans[x][y] * M % MOD);
    }   
}