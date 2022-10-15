#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
    int n,k,i,a[100001],f,t;
    scanf("%d %d",&n,&k);
    memset(a,0,sizeof(a));
    a[1]=1;
    f=1;
    i=2;
    t=k;
    while(t>0)
    {
        if(f) a[i]=a[i-1]+t; else a[i]=a[i-1]-t;
        i++;
        t--;
        f=!f;
    }
    for(i=k+2;i<=n;i++)
      a[i]=i;
    for(i=1;i<=n;i++)
      printf("%d ",a[i]);
    return 0;     
}