#include<cstdio>
#include<algorithm>
using namespace std;
#define N 110
int a[N],n,S=1e8,Sx,Sy;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    a[n+1]=a[1];
    for(int i=1;i<=n;i++)
        if(abs(a[i]-a[i+1])<S)S=abs(a[i]-a[i+1]),Sx=i,Sy=i+1;
    if(Sy==n+1)Sy=1;
    printf("%d %d\n",Sx,Sy);
    return 0;
}