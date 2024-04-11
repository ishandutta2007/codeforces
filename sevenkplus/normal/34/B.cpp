#include<cstdio>
#include<algorithm>
using namespace std;
#define N 110
int n,m,a[N],S;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<m;i++)if(a[i]<0)S-=a[i];
    printf("%d\n",S);
    return 0;
}