#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define MAXN 310000
using namespace std;
typedef long long LL;
LL data[MAXN*4];int size=0;
void up(int x)
{
     while(x>1&&data[x]>data[x/2])
     {
                                  LL tmp=data[x];data[x]=data[x/2];data[x/2]=tmp;
                                  x/=2;
                                  }
}
void down(int x)
{
     int mins=x;
     if(x*2<=size&&data[x*2]>data[mins])mins=x*2;
     if(x*2+1<=size&&data[x*2+1]>data[mins])mins=x*2+1;
     LL tmp=data[mins];data[mins]=data[x];data[x]=tmp;
     if(mins!=x)down(mins);
}
LL pop()
{
     LL v=data[1];
     data[1]=data[size--];
     down(1);
     return v;
}
void push(LL x)
{
     data[++size]=x;up(size);
}
int n;long long ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            LL v;scanf("%I64d",&v);
            push(v);ans+=1ll*v;
            }
    for(int i=1;i<=n-1;i++)
    {
            LL a=pop();
            LL b=pop();
            ans+=1ll*a+1ll*b;
            push(a+b);
            }
    printf("%I64d\n",ans);
    return 0;
}