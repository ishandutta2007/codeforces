#include<cstdio>

using namespace std;

int n,m,h,sum,a[1010];
long double ans;

long double C(int n,int m)
{
    long double nowans=1;
    if(n<m)return 0;
    if(n<0)return 0;
    if(m<0)return 0;
    for(int i=n-m+1;i<=n;i++)
        nowans=nowans*i;
    for(int i=1;i<=m;i++)
        nowans/=i;
    return nowans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&h);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]),sum+=a[i];
    if(sum<n)return puts("-1"),0;
    printf("%.10lf",(double)(1-C(sum-a[h],n-1)/C(sum-1,n-1)));
}