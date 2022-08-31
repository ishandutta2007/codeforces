#include<stdio.h>
#include<cstring>
#define MAXN 1100000
using namespace std;
typedef long long LL;
int data[MAXN];
int t[MAXN];
int a[MAXN];
int n;
LL change[2][22];
int flag[22];
LL dans[22];
void read(int &x)
{
     x=0;char p=getchar();
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
void merge(int l,int r,int dep)
{
     if(l==r)return;
     int mid=(l+r)>>1;
     LL q=0;
     merge(l,mid,dep+1);
     merge(mid+1,r,dep+1);
     int l1=l;
     int r1=mid+1;
     for(int i=l;i<=r;i++)
     if(l1>mid)t[i]=data[r1++],q+=mid-l1+1;
     else if(r1>r)t[i]=data[l1++];
     else if(data[l1]<=data[r1])t[i]=data[l1++];
     else t[i]=data[r1++],q+=mid-l1+1;
     dans[dep]+=q;
     for(int i=l;i<=r;i++)data[i]=t[i];
}    
int main()
{
    read(n);int diu=n;n=(1<<n);for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=n;i++)data[i]=a[i];merge(1,n,1);
    for(int i=1;i<=21;i++)change[0][i]=dans[i];
    memset(dans,0,sizeof dans);
    for(int i=1;i<=n;i++)data[n-i+1]=a[i];merge(1,n,1);
    for(int i=1;i<=21;i++)change[1][i]=dans[i];
    LL ans=0;for(int i=0;i<=21;i++)ans+=change[0][i];
    int q;scanf("%d",&q);
    while(q--)
    {
              int b;read(b);b=diu-b+1;
              for(int x=b;x<=diu+1;x++)
              {
               ans-=change[flag[x]][x];
               flag[x]=!flag[x];
               ans+=change[flag[x]][x];
               }
              printf("%I64d\n",ans);
              }
    return 0;
}