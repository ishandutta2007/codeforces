#include<cstdio>
#include<algorithm>
using namespace std;
#define N 111111
int p[N],a[N],l[N],r[N],n,H,q[N],L,R,b[N],m,d[N],lm[N],rm[N],k;
long long pm[N];
void ff(int a)
{
    if(l[a]!=0)ff(l[a]);
    b[++m]=a;
    if(r[a]!=0)ff(r[a]);
}
int bs(int l,int r,int x)
{
    while(l<=r)
    {
        int m=(l+r)/2;
        if(a[b[m]]<=x)l=m+1;else r=m-1;
    }
    return l;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",p+i,a+i);
    for(int i=1;i<=n;i++)if(p[i]==-1)H=i;
    for(int i=1;i<=n;i++)if(p[i]!=-1)
        if(l[p[i]]!=0&&a[l[p[i]]]>a[i])r[p[i]]=l[p[i]],l[p[i]]=i;else
        if(l[p[i]]!=0)r[p[i]]=i;else l[p[i]]=i;
    L=1;R=1;q[1]=H;
    while(L<=R)
    {
        int x=q[L++];
        if(l[x]!=0)q[++R]=l[x];
        if(r[x]!=0)q[++R]=r[x];
    }
    d[1]=0;
    for(int i=2;i<=R;i++)
    {
        int x=q[i];
        d[x]=d[p[x]]+1;
    }
    for(int i=R;i>=1;i--)
    {
        int x=q[i];
        if(l[x]==0)lm[x]=a[x];else lm[x]=lm[l[x]];
        if(r[x]==0)rm[x]=a[x];else rm[x]=rm[r[x]];
    }
    for(int i=2;i<=R;i++)
    {
        int x=q[i];
        if(x==l[p[x]])pm[x]=pm[p[x]]+lm[r[p[x]]];
        else pm[x]=pm[p[x]]+rm[l[p[x]]];
    }
    ff(H);
    scanf("%d",&k);
    while(k--)
    {
        int x;scanf("%d",&x);
        int p=bs(1,m,x);
        int ch;
        if(p>m)ch=b[p-1];else
        if(p==1)ch=b[p];else
        if(l[b[p]]==0)ch=b[p];else ch=b[p-1];
        printf("%.9lf\n",(pm[ch]+0.0)/(d[ch]));
    }
    return 0;
}