#include<stdio.h>
#include<cstring>
#define MAXN 1010000
#define jsb 1000000007
using namespace std;
int n;int fac[MAXN];int nw;
int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)if(b&1)c=c*1ll*a%jsb;
    return c;
}
inline int get(int x){
    int res=fac[x];
    res=res*1ll*x%jsb;
    res=res*1ll*(x-1)%jsb;
    res=res*1ll*nw%jsb;
    //printf("%d %d\n",x,res);
    return res;
}
int cnt[MAXN];
inline void add(int x,int v){for(;x<=n;x+=x&-x)cnt[x]+=v;}
inline int ask(int x){int res=0;for(;x;x-=x&-x)res+=cnt[x];return res;}
int main()
{
    scanf("%d",&n);fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*1ll*i%jsb;
    for(int i=1;i<=n;i++)add(i,1);
    nw=Pow(4,jsb-2);
    int res=0;int bef=0;
    for(int i=1;i<=n;i++){
            int v;scanf("%d",&v);
            int th=ask(v);add(v,-1);
            //printf("%d ",bef);
            if(th==1)continue;
            int tot=0;
            tot=(th-1)*1ll*th%jsb;
            tot=tot*1ll*Pow(2,jsb-2)%jsb;
            tot=(tot-(th-1))%jsb;tot=tot*1ll*fac[n-i]%jsb;
            res=(res+tot)%jsb;
            tot=(th-1)*1ll*bef%jsb;
            tot=tot*1ll*fac[n-i]%jsb;
            res=(res+tot)%jsb;
            tot=(th-1)*1ll*get(n-i)%jsb;
            res=(res+tot)%jsb;
            bef=(bef+ask(v-1))%jsb;
            }
    res=(res+bef)%jsb;
    printf("%d\n",(res+jsb)%jsb);
    return 0;
}