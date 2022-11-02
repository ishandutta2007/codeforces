#include<cstdio>
#include<algorithm>

#define N 100010
#define fi first
#define se second
#define mp make_pair

using namespace std;

struct lhy{
    int val,id;
}a[N];

int n,A,cf,cm,maxx,minx,minval,c[N];
long long ans,m,b[N];
pair<int,int>nowmin;

pair<int,int> work(int R,long long nowm)
{
    int l=1,r=A,mid,nowans=0,nowansx=0;
    while(l<=r)
    {
        mid=(l+r)>>1;
        int nowx=lower_bound(c+1,c+R+1,mid)-c-1;
        if(1ll*mid*nowx-b[nowx]<=nowm)l=mid+1,nowans=mid,nowansx=nowx;
        else r=mid-1;
    }
    return mp(nowans,nowansx);
}

inline int cmp1(const lhy &a,const lhy &b)
{
    return a.val<b.val;
}

inline int cmp2(const lhy &a,const lhy &b)
{
    return a.id<b.id;
}

int main()
{
    scanf("%d%d%d%d%I64d",&n,&A,&cf,&cm,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].val),a[i].id=i;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
        c[i]=a[i].val;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i].val;
    maxx=n+1;
    for(int i=n;i>=0;i--)
    {
        nowmin=work(i,m);
        if(1ll*(n-i)*cf+1ll*nowmin.fi*cm>ans)
        {
            ans=1ll*(n-i)*cf+1ll*nowmin.fi*cm;
            maxx=i;
            minx=nowmin.se;
            minval=nowmin.fi;
        }
        m-=A-a[i].val;
        if(m<0)break;
    }
    printf("%I64d\n",ans);
    for(int i=n;i>maxx;i--)
        a[i].val=A;
    for(int i=1;i<=minx;i++)
        a[i].val=minval;
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].val);
}