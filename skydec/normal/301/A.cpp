#include<stdio.h>
#include<algorithm>
#define MAXN 205
using namespace std;
int data[MAXN];
int n;
int abs(int x){if(x<0)return -x;return x;}
int main()
{
    scanf("%d",&n);n=n*2-1;
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    sort(data+1,data+1+n);int ans=0;int num=0;
    for(int i=1;i<=n;i++)if(data[i]<0)num++;
    if(data[1]>=0)
    {
                ans=0;
                for(int i=1;i<=n;i++)if(data[i]<0)ans-=data[i];else ans+=data[i];
                printf("%d\n",ans);
                return 0;
                }      
    //int ans=0;
    if(((n+1)/2)%2==1||num%2==0)
    {
                ans=0;
                for(int i=1;i<=n;i++)if(data[i]<0)ans-=data[i];else ans+=data[i];
                }
    else        
    {
        ans=0;
        for(int i=1;i<=n;i++)if(data[i]<0)ans-=data[i];else ans+=data[i];
        int mins=2100000;
        for(int i=1;i<=n;i++)if(abs(data[i])<abs(mins))mins=abs(data[i]);
        ans-=2*mins;
        }
    printf("%d\n",ans);
    return 0;
}