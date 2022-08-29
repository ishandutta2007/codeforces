#include<stdio.h>
#include<algorithm>
#include<map>
#define MAXN 210000
using namespace std;
map<int,int>ls;
int tmp[MAXN*2];
int a[MAXN],b[MAXN];
int c1[MAXN],c2[MAXN];
int n;
void Min(int &x,int y){if(y<x)x=y;if(y<0)x=0;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%d%d",&a[i],&b[i]);
            tmp[2*i-1]=a[i];
            tmp[2*i]=b[i];
            }
    sort(tmp+1,tmp+1+2*n);
    int tot=0;
    for(int i=1;i<=2*n;i++)
    if(tmp[i]!=tmp[i-1]||i==1)ls[tmp[i]]=++tot;
    for(int i=1;i<=n;i++)
    a[i]=ls[a[i]],b[i]=ls[b[i]];
    for(int i=1;i<=n;i++)
    {
            c1[a[i]]++;
            if(a[i]!=b[i])c2[b[i]]++;
            }
    int ans=2100000;
    for(int i=1;i<=tot;i++)
    if(2*(c1[i]+c2[i])>=n)Min(ans,n/2+(n&1)-c1[i]);
    if(ans==2100000)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}