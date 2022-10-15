#include<bits/stdc++.h>
#define MAXN 200005
#define INF 10000000000000000
using namespace std;
typedef long long ll;
ll a[MAXN],b[MAXN],n,m,q;
ll sum[MAXN],save[MAXN];
int main()
{
    scanf("%I64d %I64d %I64d",&n,&m,&q);
    ll s=0;
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%I64d",&b[i]);
    for(int i=1;i<=n;i++)
        if(i%2==1) s+=a[i]; else s-=a[i];
    sum[0]=0;
    for(int i=1;i<=m;i++)
        if(i%2==1) sum[i]=sum[i-1]-b[i]; else sum[i]=sum[i-1]+b[i];
    for(int i=1;i<=m-n+1;i++)
        if(i%2==1) save[i]=sum[i-1]-sum[i+n-1]; else save[i]=sum[i+n-1]-sum[i-1];
    save[m-n+2]=INF;
    sort(save+1,save+m-n+2);
    int id=lower_bound(save+1,save+m-n+2,s)-save;
    if(id==1) printf("%I64d\n",max(save[id]-s,s-save[id]));
    else if(id==m-n+2) printf("%I64d\n",max(save[id-1]-s,s-save[id-1]));
    else printf("%I64d\n",min(max(save[id]-s,s-save[id]),max(save[id-1]-s,s-save[id-1])));
    ll l,r,x;
    for(int i=0;i<q;i++)
    {
        scanf("%I64d %I64d %I64d",&l,&r,&x);
        if((r-l)%2==0)
            if(l%2==1) s+=x; else s-=x;
        id=lower_bound(save+1,save+m-n+2,s)-save;
        if(id==1) printf("%I64d\n",max(save[id]-s,s-save[id]));
        else if(id==m-n+2) printf("%I64d\n",max(save[id-1]-s,s-save[id-1]));
        else printf("%I64d\n",min(max(save[id]-s,s-save[id]),max(save[id-1]-s,s-save[id-1])));
    }
    return 0;
}