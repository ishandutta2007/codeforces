#include<bits/stdc++.h>
#define MAXV 400005
#define MAXQ 400005
#define MAXLOGV 20
#define INF 10000000000000000
using namespace std;
typedef long long ll;
ll parent[MAXLOGV][MAXV],sum[MAXLOGV][MAXV],w[MAXV];
ll n,q;
int main()
{
    memset(parent,0,sizeof(parent));
    memset(sum,0,sizeof(sum));
    memset(w,0,sizeof(w));
    w[0]=INF;
    for(ll i=0;i<20;i++)
        sum[i][1]=INF;
    ll cnt=1,last=0;
    scanf("%I64d",&q);
    for(ll i=0;i<q;i++)
    {
        ll type,p,q;
        scanf("%I64d",&type);
        if(type==1)
        {
            scanf("%I64d%I64d",&p,&q);
            p^=last;q^=last;
            cnt++;
            w[cnt]=q;
            if(w[p]>=w[cnt]) parent[0][cnt]=p;
            else
            {
                ll from=p;
                for(ll i=19;i>=0;i--)
                    if(parent[i][from]!=0&&w[parent[i][from]]<w[cnt])
                        from=parent[i][from];
                parent[0][cnt]=parent[0][from];
            }
            sum[0][cnt]=(parent[0][cnt]==0?INF:w[parent[0][cnt]]);
            for(ll i=1;i<20;i++)
            {
                parent[i][cnt]=parent[i-1][parent[i-1][cnt]];
                sum[i][cnt]=(parent[i][cnt]==0?INF:sum[i-1][cnt]+sum[i-1][parent[i-1][cnt]]);
            }
        }
        else
        {
            scanf("%I64d%I64d",&p,&q);
            p^=last;q^=last;
            if(w[p]>q)
            {
                puts("0");
                last=0;
            }
            else
            {
                q-=w[p];
                ll ans=1;
                for(ll i=19;i>=0;i--)
                {
                    if(sum[i][p]<=q){
                        ans+=(1<<i);
                        q-=sum[i][p];
                        p=parent[i][p];
                    }
                }
                printf("%I64d\n",ans);
                last=ans;
            }
        }
    }
    return 0;
}