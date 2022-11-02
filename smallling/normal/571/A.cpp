#include<cstdio> 
#include<algorithm>

using namespace std;

int a,b,c,l,x;
long long ans;

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&l);
    ans=1ll*(l+1)*(l+2)*(l+3)/6;
    for(int la=0;la<=l;la++)
    {
        x=min(a-b-c+la,l-la);
        if(x<0)continue;
        ans-=1ll*(x+1)*(x+2)/2;
    }
    for(int lb=0;lb<=l;lb++)
    {
        x=min(b-a-c+lb,l-lb);
        if(x<0)continue;
        ans-=1ll*(x+1)*(x+2)/2;
    }
    for(int lc=0;lc<=l;lc++)
    {
        x=min(c-a-b+lc,l-lc);
        if(x<0)continue;
        ans-=1ll*(x+1)*(x+2)/2;
    }
    printf("%I64d",ans);
}