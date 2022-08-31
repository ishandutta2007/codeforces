#include<stdio.h>
#include<algorithm>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL sum[MAXN];
#define fi first
#define se second
#define pii pair< int,int >
pii data[MAXN];
pii temp[MAXN];
int n;
LL dis(pii a,pii b){return (a.fi-b.fi)*1ll*(a.fi-b.fi)+(a.se-b.se)*1ll*(a.se-b.se);}
void Min(LL &a,LL b){if(b<a)a=b;}
LL ans=-1;
LL sqr(int x){return x*1ll*x;}
void work(int l,int r)
{
            if(l==r){if(ans==-1)ans=(LL)1e18;return;}
            int mid=(l+r)>>1;work(l,mid);work(mid+1,r);int tot=0;
            for(int i=l;i<=r;i++)
            if(sqr(data[i].fi-data[mid].fi)<=ans)temp[++tot]=pii(data[i].se,data[i].fi);
            sort(temp+1,temp+1+tot);
            for(int i=1;i<=tot;i++)
            for(int j=i+1;j<=tot;j++)
            {
                    if(sqr(temp[i].fi-temp[j].fi)>=ans)break;
                    Min(ans,dis(temp[i],temp[j]));
                    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&sum[i]);sum[i]+=sum[i-1];data[i]=pii(i,sum[i]);}
    work(1,n);printf("%I64d\n",ans);
    return 0;
}