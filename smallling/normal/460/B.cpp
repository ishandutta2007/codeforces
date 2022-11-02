#include<cstdio>

using namespace std;

int a,b,c,now1,o;
long long now,last,ans[101];

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=81;i++)
    {
        now=1;
        for(int j=1;j<=a;j++)
            now=now*1ll*i;
        now=now*1ll*b;
        now=now+1ll*c;
        last=now;
        now1=0;
        while(now)
        {
            now1+=now%10;
            now/=10ll;
        }
        if(now1==i&&last<=1000000000)ans[++o]=last;
    }
    printf("%d\n",o);
    for(int i=1;i<=o;i++)
        printf("%I64d ",ans[i]);
}