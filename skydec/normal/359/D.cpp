#include<stdio.h>
#include<cstring>
#define MAXN 310000
using namespace std;
int l[MAXN],r[MAXN];
int n;int data[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&data[i]);
            l[i]=r[i]=i;
            }
    for(int i=2;i<=n;i++)
    {
            int j=i-1;
            while((data[j]%data[i]==0)&&j)j=l[j]-1;
            l[i]=j+1;
            }
    for(int i=n-1;i>=1;i--)
    {
            int j=i+1;
            while((data[j]%data[i]==0)&&(j!=n+1))j=r[j]+1;
            r[i]=j-1;
            }
    int max=-1;
    memset(ans,-1,sizeof ans);
    for(int i=1;i<=n;i++)
    {
            if(r[i]-l[i]>=max)
            {
                             max=r[i]-l[i];
                             ans[l[i]]=max;
                             }
                             }
    int anss=0;
    for(int i=1;i<=n;i++)if(ans[i]==max)anss++;
    printf("%d %d\n",anss,max);
    for(int i=1;i<=n;i++)if(ans[i]==max)printf("%d ",i);
    return 0;
}