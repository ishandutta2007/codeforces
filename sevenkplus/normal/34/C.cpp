#include<cstdio>
#include<algorithm>
using namespace std;
#define N 110
int n,a[N];
int main()
{
    for(int x;scanf("%d",&x)!=EOF;getchar())a[n++]=x;
    sort(a,a+n),n=unique(a,a+n)-a;
    for(int i=0,j;i<n;i=j)
    {
        for(j=i+1;j<n&&a[j]-a[j-1]==1;j++);
        if(j==i+1)printf("%d",a[j-1]);else printf("%d-%d",a[i],a[j-1]);
        if(j==n)puts("");else printf(",");
    }
    return 0;
}