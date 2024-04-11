#include<cstdio>

#define mo 1000000007

using namespace std;

int k,t,f[100010],sum[100010],a,b;

int main()
{
    scanf("%d%d",&t,&k);
    f[0]=1;
    for(int i=1;i<=100000;i++)
    {
        if(i<k)f[i]=1;
        f[i]=(f[i-1]+f[i-k])%mo;
        sum[i]=(sum[i-1]+f[i])%mo;
    }
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",(sum[b]-sum[a-1]+mo)%mo);
    } 
}