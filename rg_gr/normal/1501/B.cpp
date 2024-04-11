#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[200005];
int sum[200005];
int n;
inline int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int v)
{
    while(x<=n)sum[x]+=v,x+=lowbit(x);
}
int query(int x)
{
    int u=0;
    while(x)u+=sum[x],x-=lowbit(x);
    return u;
}
signed main()
{
    int T=read();
    while(T--)
    {
        n=read();
        memset(sum,0,sizeof(int)*(n+2));
        for(int i=1;i<=n;i++)
        {
            int x=read();
            if(x==0)continue;
            int l=i-x+1,r=i;
            if(l<1)l=1;
            if(r==n)
            {
                add(l,1);
            }
            else
            {
                add(l,1);
                add(r+1,-1);
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int x=query(i);
            //printf("%lld ",x);
            if(x)printf("1 ");
            else printf("0 ");
        }
        puts("");
    }
}