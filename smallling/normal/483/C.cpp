#include<cstdio>

using namespace std;

int n,k,a[100010],b[100010];

int main()
{
    scanf("%d%d",&n,&k);
    a[1]=1;
    b[a[1]]=1;
    for(int i=2;i<=n&&k;b[a[i]]=1,i++,k--)
        if(a[i-1]-k>0&&!b[a[i-1]-k])a[i]=a[i-1]-k;
        else a[i]=a[i-1]+k;
    for(int i=1;i<=n;i++)
        if(a[i])printf("%d ",a[i]);
    for(int i=1;i<=n;i++)
        if(!b[i])printf("%d ",i);
}