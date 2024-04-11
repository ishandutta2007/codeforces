#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int MOD = 998244353;
LL l,r,k;
LL dp[20][1<<10][2][2],cnt[20][1<<10][2][2],d[20], num[1<<10], p[20];
void dfs(int now,int mask,int ismax,int has){
    //printf("now=%d, mask=%d, ismax=%d\n", now,mask,ismax);
    if(dp[now][mask][ismax][has]!=-1) return;
    dp[now][mask][ismax][has]=0;
    if(now==0) {
        if(num[mask]<=k){
            dp[now][mask][ismax][has]=0; cnt[now][mask][ismax][has]=1;
        }
        return;
    }
    int lim = ismax?d[now]:9;
    for(int i=0;i<=lim;i++){
        int bu = 1<<i; if(i==0 && has==0) bu=0;
        dfs(now-1,mask|bu,ismax&&i==lim,has||i);
        (dp[now][mask][ismax][has] += dp[now-1][mask|bu][ismax&&i==lim][has||i]) %= MOD;
        (dp[now][mask][ismax][has] += cnt[now-1][mask|bu][ismax&&i==lim][has||i] * i%MOD*p[now-1]%MOD) %= MOD;
        (cnt[now][mask][ismax][has] += cnt[now-1][mask|bu][ismax&&i==lim][has||i]) %= MOD;
    }
}

LL cac(LL x) {
    memset(dp,-1,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    int pos=0;
    while(x) {
        d[++pos]=x%10; x/=10;
    }
    dfs(pos,0,1,0);
    LL ans=dp[pos][0][1][0];
    return ans;
}
int count(int x){
    int cnt=0;
    while(x){
        if(x&1)cnt++; x>>=1;
    } return cnt;
}
int suan(LL x){
    int mask=0;
    while(x){
        mask|=1<<(x%10); x/=10;
    }
    return count(mask);
}
int main() {
    for(int i=0;i<1<<10;i++) num[i]=count(i);
    p[0]=1;for(int i=1;i<19;i++)p[i]=p[i-1]*10LL%MOD;
    cin >> l >> r >> k;
    //LL ans=0;
    //for(LL x=l;x<=r;x++) if(suan(x)<=k) (ans+=x)%=MOD;
    //cout<<ans<<endl;
    printf("%lld\n", (cac(r)-cac(l-1)+MOD)%MOD);
}