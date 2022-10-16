#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%lld\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}

#define maxn 1000005
namespace dq
{
    int vis[maxn],prime[maxn],cnt=0;
    int d[maxn],f[maxn];
     
    void D(int n)
    {
        for(int i=2;i<=n;i++)
        {
            if(!vis[i])
            {
                prime[++cnt]=i;
                f[i]=1;
                d[i]=2;
            }
            for(int j=1;j<=cnt&&i*prime[j]<=n;j++)
            {
                vis[i*prime[j]]=1;
                if(i%prime[j]==0) {
                    f[i*prime[j]]=f[i]+1;
                    d[i*prime[j]]=d[i]/(f[i]+1)*(f[i]+2);
                    break;
                }
                f[i*prime[j]]=1;
                d[i*prime[j]]=d[i]*d[prime[j]];
            }
        }
    }
};
using dq::d;
int m[2000005],s[2000005];
void E(int o,int l,int r,int L,int R)
{
	if(m[o]==2||m[o]==1)return;
	if(l==r)
	{
		s[o]=m[o]=d[s[o]];
		return;
	}
	int mm=l+r>>1;
	if(L<=mm)E(o<<1,l,mm,L,R);
	if(mm<R)E(o<<1|1,mm+1,r,L,R);
	m[o]=max(m[o<<1],m[o<<1|1]);
	s[o]=s[o<<1]+s[o<<1|1];
}
void S(int o,int l,int r,int p,int v)
{
//	if(m[o]==2||m[o]==1)return;
	if(l==r)
	{
		s[o]=m[o]=v;
		return;
	}
	int mm=l+r>>1;
	if(p<=mm)S(o<<1,l,mm,p,v);
	else S(o<<1|1,mm+1,r,p,v);
	m[o]=max(m[o<<1],m[o<<1|1]);
	s[o]=s[o<<1]+s[o<<1|1];
}
int T(int o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return s[o];
	int m=l+r>>1,q=0;
	if(L<=m)q+=T(o<<1,l,m,L,R);
	if(m<R)q+=T(o<<1|1,m+1,r,L,R);
	return q;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)S(1,1,n,i,read());
	dq::D(1000000);
	while(m--)
	{
		int op=read(),l=read(),r=read();
		if(op==2)odl(T(1,1,n,l,r));
		else E(1,1,n,l,r);
	}
	return 0;
}