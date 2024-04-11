#include<cstdio>
#include<algorithm>
using namespace std;
#define N 2000010
int n,m,a[N],b[N],cb[N],fa[N],le[N];
bool chk(int x,int y,int z)
{
    if(x==y)return 1;
    if(x==z)return 0;
    if(y>x)return z<x||z>y;
    return y<z&&z<x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i),cb[b[i]]=i;
    if(n==1)
    {
        int S=0;
        for(int i=1;i<=m;i++)if(b[i]==a[1])S=1;
        printf("%d\n",S);
        return 0;
    }
    for(int i=1;i<=n;i++)a[i+n]=a[i];
    for(int i=1;i<=n*2;i++)
    {
        if(!cb[a[i]])le[i]=fa[i]=0;else
        if(le[i-1])
        {
            int p=fa[i-1];
            while(!chk(cb[a[p]],cb[a[i-1]],cb[a[i]]))p++;
            fa[i]=p,le[i]=i-p+1;
        }else le[i]=1,fa[i]=i;
    }
    int S=0;
    for(int i=1;i<=n*2;i++)S=max(S,le[i]);
    printf("%d\n",S);
    return 0;
}