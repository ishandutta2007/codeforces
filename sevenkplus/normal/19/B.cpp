#include<cstdio>
#include<algorithm>
long long a[2222];int n;
int main()
{
    scanf("%d",&n);for(int i=1;i<=n;i++)a[i]=1000000000000000000LL;a[0]=0;
    for(int i=0,t,c,j;i<n;i++)
        for(scanf("%d%d",&t,&c),t++,j=n-1;j>=0;j--)a[std::min(n,j+t)]=std::min(a[std::min(n,j+t)],a[j]+c);
    printf("%I64d\n",a[n]);
    return 0;
}