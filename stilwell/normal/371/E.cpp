#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long sum[400005];
int n,m,i,j,k,ans;
long long ansdist,tmp;
int ou[400005];

struct node
{
    long long x;
    int id;
}t[400005];

inline bool cmp(const node &a,const node &b){return a.x<b.x;}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%I64d\n",&t[i].x),t[i].id=i;
    sort(t+1,t+n+1,cmp);
    scanf("%d",&k);
    for(i=1;i<=n;++i)sum[i]=sum[i-1]+t[i].x;
    for(i=0;i<k;++i)
    {
        tmp+=t[i].x*i;
        tmp-=t[i].x*(k-i-1);
    }
    for(i=1;i<=n-k+1;++i)
    {
        tmp+=t[i-1].x*(k-1);
        tmp-=sum[i+k-2]-sum[i-1];
        tmp+=t[i+k-1].x*(k-1);
        tmp-=sum[i+k-2]-sum[i-1];
        if(i==1||tmp<ansdist)
        {
            ans=i;
            ansdist=tmp;
        }
    }
    ou[1]=t[ans].id;
    for(i=ans+1;i<=ans+k-1;++i)ou[i-ans+1]=t[i].id;
    printf("%d",ou[1]);
    for(i=2;i<=k;++i)printf(" %d",ou[i]);
    printf("\n");
}