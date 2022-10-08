#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10000],k;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    while(a[k]==0){k++;if(k>n)k=1;}
    printf("%d\n",k);
    return 0;
}