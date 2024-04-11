#include<stdio.h>
#include<cstring>
using namespace std;
const int MAXN=4005;
char str[MAXN];
int times[110000];
int biubiu[110000];
int n;
int main()
{
    int a;scanf("%d",&a);
    scanf("%s",str+1);n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
            int u=0;
            for(int j=i;j<=n;j++)
            {
                    u+=str[j]-48;
                    if(u){
                    if(a%u==0){
                    if(u*1ll*u<=a)times[u]++;
                    else biubiu[a/u]++;
                    }}
                    else times[0]++;
                    }
                    }
    long long ans=0;
    for(int i=1;i*i<=a;i++)
    if(a%i==0)
    {
              if(i*i==a)
              ans+=times[i]*1ll*times[i];
              else ans+=times[i]*2ll*biubiu[i];
              }
    //int x=(int)sqrt(a);
    //if(x*x==a)
    //ans-=1ll*times[x];
    if(a==0)ans=times[0]*1ll*times[0]+((n*(n+1)/2)-times[0])*2ll*times[0];
    printf("%I64d\n",ans);
    return 0;
}