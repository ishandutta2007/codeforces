#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int x[4],y[4],n,a,b,c,x0=1,y0=1;ll t,w[4];string s;
ll gg(ll a,ll b){return a<=b?b*(b+1)/2-a*(a+1)/2:a*(a-1)/2-b*(b-1)/2;}
ll ff(ll x0,ll y0,ll x1,ll y1)
{
    if(x0>=x1&&y0>=y1)return gg(abs(x0-x1)+abs(y0-y1),abs(n-x1)+abs(n-y1));
    if(x0<x1)return gg(abs(x0-x1)+abs(y0-y1),abs(y1-y0))+ff(x1,y0,x1,y1);
    if(y0<y1)return gg(abs(x0-x1)+abs(y0-y1),abs(x1-x0))+ff(x0,y1,x1,y1);
}
int main()
{
    scanf("%d%I64d%d%d%d",&n,&t,&a,&b,&c);
    x[0]=a,y[0]=b,
    x[1]=a,y[1]=b+c-1,
    x[2]=a+c-1,y[2]=b,
    x[3]=a+c-1,y[3]=b+c-1;
    while(x0!=n||y0!=n)
    {
        if(x0==n)s+="U",y0++;else
        if(y0==n)s+="R",x0++;else
        {
            bool F=1;
            for(int i=0;i<4;i++)
                if(w[i]+abs(x0+1-x[i])+abs(y0-y[i])+ff(x0+1,y0,x[i],y[i])>t){F=0;break;}
            if(F)s+="R",x0++;else s+="U",y0++;
        }
        for(int i=0;i<4;i++)w[i]+=abs(x0-x[i])+abs(y0-y[i]);
    }
    for(int i=0;i<4;i++)if(w[i]>t){puts("Impossible");return 0;}
    puts(s.c_str());
    return 0;
}