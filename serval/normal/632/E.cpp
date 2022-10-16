#include <cstdio>
#include <cstring>
#define maxn 1005
using namespace std;
int n,k,a[maxn],i,j,x,min,top,t,f[maxn*maxn],q[maxn*maxn],l,r,c;
bool inq[maxn*maxn];
int main()
{
    scanf("%d%d",&n,&k);
    min=0x3f3f3f3f;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]<min)
            min=a[i];
    }
    for (i=1;i<=n;i++)
        a[i]-=min;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    q[l=r=c=1]=0;
    inq[0]=1;
    while (c)
    {
        for (i=1;i<=n;i++)
            if (f[a[i]+q[l]]>f[q[l]]+1)
            {
                f[a[i]+q[l]]=f[q[l]]+1;
                if (a[i]+q[l]>top)
                    top=a[i]+q[l];
                if (f[a[i]+q[l]]<k&&!inq[a[i]+q[l]])
                {
                    r++;
                    if (r>maxn*maxn)
                        r=0;
                    q[r]=a[i]+q[l];
                    inq[q[r]]=1;
                    c++;
                }
            }
        inq[q[l]]=0;
        l++;
        if (l>maxn*maxn)
            l=0;
        c--;
    }
    for (i=0;i<=top;i++)
        if (f[i]<=k)
            printf("%d ",i+k*min);
    return 0;
}