#include<stdio.h>
#include<algorithm>
#define MAXN 1010000
using namespace std;
int n;int k;
int data[310000];
int tmp[MAXN];
void read(int &x)
{
     x=0;char p=getchar();
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
int main()
{
    //freopen("c.in","r",stdin);
    scanf("%d",&n);scanf("%d",&k);
    int mins=0;
    for(int i=1;i<=n;i++)
    {
            read(data[i]);
            if(data[i]>mins)mins=data[i];
            }
    sort(data+1,data+1+n);
    for(int i=mins;i>=1;i--)
    {
            int tt=0;
            for(int j=i;j<=mins;j+=i)tmp[++tt]=j;
            int u=0;bool f=1;
            for(int j=1;j<=n;j++)
            {
                    while(u!=tt&&tmp[u+1]<=data[j])u++;
                    if(!u){f=0;break;}
                    if(data[j]-tmp[u]>k){f=0;break;}
                    int l,r;
                    r=n;l=j;
                    while(l<r)
                    {
                              int mid=(l+r)>>1;
                              if(data[mid]-tmp[u]>k)r=mid;
                              else j=mid,l=mid+1;
                              }
                    if(data[l]-tmp[u]<=k)j=l;
                    }
            if(f)
            {
                 printf("%d\n",i);
                 //for(;;);
                 return 0;        
                 }
                 }
    //for(;;);
    return 0;
}