#include<stdio.h>
#define MAXN 1000001
using namespace std;
bool prime[MAXN]={false};
int sum[MAXN];
void init()
{
     prime[1]=true;
     for(int i=2;i<=1000000;i++)
     if(!prime[i])
     {
                  for(long j=i*2;j<=1000000;j+=i)
                  prime[j]=true;
                  }
     for(int i=1;i<=1000000;i++)sum[i]=sum[i-1]+(1-prime[i]);
}
int ask(int a,int b)
{
    return sum[b]-sum[a-1];
}
int main()
{
    int a,b,k;scanf("%ld%ld%ld",&a,&b,&k);
    init();
    int l,r,ans;
    l=0;r=b-a+1;ans=-1;
    while(l<r)
    {
              int mid=(l+r)/2;
              bool flag=true;
              for(int i=a;i<=b-mid+1;i++)
              if(ask(i,i+mid-1)<k)flag=false;
              if(flag)
              {
                      ans=mid;r=mid;
                      }
              else l=mid+1;
              }
    bool flag=true;
              for(int i=a;i<=b-l+1;i++)
              if(ask(i,i+l-1)<k)flag=false;
              if(flag)
              {
                      ans=l;r=l;
                      }
    printf("%d\n",ans);
    return 0;
}