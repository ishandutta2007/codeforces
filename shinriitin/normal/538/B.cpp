#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=1e6+5;

int q[MAXN],tot;

inline int trans(int set){
    int x=0;
    for(int i=7;~i;--i)
        x=10*x+(set>>i&1);
    return x;
}

int n,ans[MAXN],cnt;

int dp[MAXN],pre[MAXN];

int DP(int x){
    if(!x)return 0;
    if(dp[x])return dp[x];
    int&res=dp[x];
    res=0x7f7f7f7f;
    for(int i=1;i<=tot&&q[i]<=x;++i){
        int tmp=DP(x-q[i])+1;
        if(res>tmp){
            res=tmp;
            pre[x]=q[i];
        }   
    }   
    return res;
}

int main(){
    for(int set=1;set<=1<<7;++set)
        q[++tot]=trans(set);
    scanf("%d",&n);
    DP(n);
    for(int i=n;i>0;i-=pre[i])
        ans[++cnt]=pre[i];
    printf("%d\n",cnt);
    sort(ans+1,ans+1+cnt);
    for(int i=1;i<=cnt;++i)
        printf("%d ",ans[i]);
    return 0;   
}