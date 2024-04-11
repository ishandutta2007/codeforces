#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL inf = 1e18+1;
const int N = 200000 + 10;
int t,n; 
LL k,dp[52],fac[52];
LL add(LL x, LL y){
    return min(x+y, inf);
}
LL mul(LL x, LL y){
    if(x<(inf+y-1)/y)return x*y;
    return inf;
}

int par[52];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}

LL chk(int a[], int m) {
    LL ans=1;
    int i,j;
    /*
    printf("m=%d, seq: ", m);
    for(int i=1;i<=m;i++)printf("%d ", a[i]);
    printf("\n");
    */
    for(i=1,j=1;i<=m;i=j+1){
        j=a[i];
        if(j<=m){
            for(int x=i;x<=a[i];x++) {
                if(a[x]>a[i]||a[x]<i){
                    //printf("NG!\n");
                    return 0;
                }
            }
            continue;
        }else{
            int in[52]={0};
            for(int x=i;x<=a[i];x++) par[x]=x;
            for(int x=i;x<=m;x++){
                if(find(x)==find(a[x])) return 0;
                par[find(x)]=find(a[x]);
            }
            int r=0;
            for(int x=i;x<=a[i];x++)if(find(x)==x)r++;
            
            ans=fac[r-1];
            //printf("r=%d\n", r);
            //printf("ans=%lld\n", ans);
        }
    }
    //printf("i=%d %lld\n", i, ans);
    // printf("ans=%lld\n", mul(ans,dp[n-i+1]));
    return ans=mul(ans,dp[n-i+1]);
}
int main() {
    fac[0]=1; 
    for(int i=1;i<=50;i++)fac[i]=mul(fac[i-1],i);
    dp[0]=1; 
    for(int i=1;i<=50;i++)for(int j=1;j<=i;j++)dp[i]=add(dp[i],mul(j>=2?fac[j-2]:1,dp[i-j]));
        
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        bool vis[52]={0};
        if(dp[n]<k){
            printf("-1\n");continue;
        }
        int a[52]={0}; int m=0;
        for(int i=1;i<=n;i++){
            //printf("dp[%d]=%lld\n", i,dp[i]);
            ++m;
            for(int j=1;j<=n;j++){
                if(vis[j])continue;
                a[m]=j;
                LL tmp=chk(a,m);
                if(tmp<k){
                    k-=tmp;
                }else{
                    vis[j]=1;break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
/*
*/