#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
int data[MAXN];
int n,d;
int main()
{
    scanf("%d%d",&n,&d);
    long long ans=0;
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    for(int i=1;i<=n;i++)
    {
            int l,r,ls;
            l=1;r=i;int rs;
            while(l<r)
            {
                      int mid=(l+r)>>1;
                      if(data[i]-data[mid]<=d)ls=mid,r=mid;
                      else l=mid+1;
                      }
            if(data[i]-data[l]<=d)ls=l;
            l=i;r=n;
            while(l<r)
            {
                      int mid=(l+r)>>1;
                      if(data[mid]-data[i]<=d)rs=mid,l=mid+1;
                      else r=mid;
                      }
            if(data[l]-data[i]<=d)rs=l;
            ans+=((i-ls)*1ll*(i-ls-1))/2;
            ans+=((rs-i)*1ll*(rs-i-1))/2;
            //printf("%d %d\n",ls,rs);
            }
    printf("%I64d\n",ans/2);
    return 0;
}