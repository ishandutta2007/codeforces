#include<cstdio>
#include<algorithm>
using namespace std;
int a[5010],b[5010],n;
long long F[2][5010],M,*f=F[0],*g=F[1];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;scanf("%d",a+i),b[i]=a[i],i++);
    sort(b,b+n);
    for(int i=0;i<=n;i++)
    {
        M=f[0];
        for(int j=0;j<n;M=min(M,f[j]),g[j]=M+abs(b[j]-a[i]),j++);
        swap(f,g);
    }
    printf("%I64d\n",M);
    return 0;
}