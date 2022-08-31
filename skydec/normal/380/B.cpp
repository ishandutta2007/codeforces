#include<stdio.h>
#include<cmath>
#include<algorithm>
#define MAXN 7005
using namespace std;
long n,m;
long head[MAXN],l[MAXN],r[MAXN],add[MAXN],next[MAXN];
long ss[1010000];
long tot=0;long reu=0;
long jiao(long x1,long y1,long x2,long y2)
{
     if(y1<x2||x1>y2)return 0;
     if((x1>=x2)&&(y1<=y2))
     return y1-x1+1;
     else if(x1<=x2&&y2<=y1)return y2-x2+1;
     else return abs(y2-x1)+1;
}
void line(long t,long x,long y,long v)
{
     tot++;add[tot]=v;l[tot]=x;r[tot]=y;next[tot]=head[t];head[t]=tot;
}
long turnright(long x)
{
     if(x==0)return 0;
     return x+1+(long)log2(x);
}
long turnleft(long x)
{
     return turnright(x-1)+1;
}
long chuo=0;
void insert(long x)
{
     if(ss[x]==chuo)return;
     reu++;ss[x]=chuo;
}
int main()
{
    scanf("%ld%ld",&n,&m);
    for(long opt=1;opt<=m;opt++)
    {
             long type;scanf("%ld",&type);
             if(type==1)
             {
                        long t,x,y,v;scanf("%ld%ld%ld%ld",&t,&x,&y,&v);
                        line(t,x,y,v);
                        }
             else
             {
                        long t,x;scanf("%ld%ld",&t,&x);
                        long left=x,right=x;reu=0;chuo++;
                        for(long i=t;i<=n;i++)
                        {
                                 //printf("%ld %ld\n",left,right);
                                 //printf("%ld\n",reu);
                                 for(long u=head[i];u;u=next[u])
                                 {
                                          if(jiao(left,right,l[u],r[u])>0)
                                          insert(add[u]);
                                          
                                 //reu+=(long)jiao(left,right,l[u],r[u])*(long)add[u];
                                 //printf("%ld %ld %ld %ld %ld\n",left,right,l[u],r[u],jiao(left,right,l[u],r[u]));
                                 }
                                 left=turnleft(left);
                                 right=turnright(right);
                                 }
                        printf("%ld\n",reu);
                        }
                        }
    return 0;
}