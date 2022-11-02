#include<cstdio>
#include<algorithm>

#define mo 10000000000ll

using namespace std;

int t,x1,y1,x2,y2;

long long Mul(long long x,long long m)
{
    long long nowans=0;
    while(m)
    {
        if(m&1)
        {
            nowans=nowans+x;
            if(nowans>=mo)nowans-=mo;
        }
        x=x+x;
        if(x>=mo)x-=mo;
        m>>=1;
    }
    return nowans;
}

long long getn2(long long x)
{
    int flag2=0,flag3=0;
    long long X=x;
    if(X%2==0)X/=2,flag2=1;
    if(X%3==0)X/=3,flag3=1;
    long long nowans=X;
    X=x+1;
    if(!flag2&&X%2==0)flag2=1,X/=2;
    if(!flag3&&X%3==0)flag3=1,X/=3;
    nowans=Mul(nowans,X);
    X=2*x+1;
    if(!flag2)X/=2;
    if(!flag3)X/=3;
    nowans=Mul(nowans,X);
    return nowans;
}

long long calc(long long x,long long y)
{
    if(!x||!y)return 0;
    long long X=min(x,y),nowans,nowsum;
    if(X*X%2==0)nowans=X*X/2,nowans%=mo,nowans=Mul(nowans,(1+X*X)%mo);
    else nowans=(1+X*X)/2,nowans%=mo,nowans=Mul(nowans,X*X%mo);
    if(x>X)
    {
        nowsum=getn2(x)-getn2(X);
        if(nowsum<0)nowsum+=mo;
        nowans+=Mul(nowsum,y);
        if(nowans>=mo)nowans-=mo;
        if(y%2==0)nowsum=y/2,nowsum=Mul(nowsum,y-1);
        else nowsum=(y-1)/2,nowsum=Mul(nowsum,y);
        nowans-=Mul(nowsum,(x-X));
        if(nowans<0)nowans+=mo;
    }
    if(y>X)
    {
        nowsum=getn2(y-1)-getn2(X-1)+(y-X);
        if(nowsum<0)nowsum+=mo;
        if(nowsum>=mo)nowsum-=mo;
        nowans+=Mul(X,nowsum);
        if(nowans>=mo)nowans-=mo;
        if(x%2==0)nowsum=x/2,nowsum=Mul(nowsum,x-1);
        else nowsum=(x-1)/2,nowsum=Mul(nowsum,x);       
        nowans+=Mul((y-X),nowsum);
        if(nowans>=mo)nowans-=mo;
    }
    return nowans;
}

long double getn2(long double x)
{
    return (2*x*x*x+3*x*x+x)/6;
}

long double calc_(long double x,long double y)
{
    long double X=min(x,y),nowans=(1+X*X)*X*X/2,nowsum;
    if(x>X)
    {
        nowsum=getn2(x)-getn2(X);
        nowans+=nowsum*y;
        nowsum=(1+y-1)*(y-1)/2;
        nowans-=nowsum*(x-X);
    }
    if(y>X)
    {
        nowsum=getn2(y-1)-getn2(X-1)+(y-X);
        nowans+=X*nowsum;
        nowsum=(1+x-1)*(x-1)/2;
        nowans+=(y-X)*nowsum;
    }
    return nowans;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        long long nowans=(calc(x2,y2)-calc(x1-1,y2)+mo-calc(x2,y1-1)+mo+calc(x1-1,y1-1))%mo;
        if((calc_(x2,y2)-calc_(x1-1,y2)-calc_(x2,y1-1)+calc_(x1-1,y1-1))>=1e10)printf("...%.10I64d\n",nowans);
        else printf("%I64d\n",nowans);
    }
}