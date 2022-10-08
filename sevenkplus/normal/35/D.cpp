#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[110],b[110],S;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i),b[i]=i;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[b[i]]*(n-b[i])>a[b[j]]*(n-b[j]))swap(b[i],b[j]);
    for(int i=0;i<n;i++)
        if(a[b[i]]*(n-b[i])<=m)m-=a[b[i]]*(n-b[i]),S++;
    printf("%d\n",S);
    return 0;
}