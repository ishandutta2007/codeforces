#include <cstdio>

int main()
{
    int n,a1,b1,c1,d1,e1;
    long long a2=0,b2=0,c2=0,d2=0,e2=0,now=0;
    scanf("%d\n",&n);
    int a[n+1];
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d %d %d %d %d",&a1,&b1,&c1,&d1,&e1);
    for (int i=1;i<=n;i++)
    {
        now+=a[i];
        e2+=now/e1;now%=e1;
        d2+=now/d1;now%=d1;
        c2+=now/c1;now%=c1;
        b2+=now/b1;now%=b1;
        a2+=now/a1;now%=a1;
    }
    printf("%I64d %I64d %I64d %I64d %I64d\n%I64d\n",a2,b2,c2,d2,e2,now);
}