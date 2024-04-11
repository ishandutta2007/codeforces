#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int a[100005];
inline int min(int a,int b)
{
	return a<b?a:b;
}
int dolve(int n,int q,int aa,int r,int m)
{
	int L=0,H=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<q)L+=q-a[i];
		else H+=a[i]-q;
	}
	int p1=L*aa+H*r,p2=min(L,H)*m;
	if(L>H)p2+=aa*(L-H);
	else p2+=r*(H-L);
	return p1>p2?p2:p1;
}
signed main()
{
	int n=read(),aa=read(),r=read(),m=read();
	for(int i=0;i<n;i++)a[i]=read();
	int L=0,R=1000000005;
	while(R-L>=5)
	{
		//printf("%lld %lld\n",L,R);
		int M=R+L>>1;
		if(dolve(n,M,aa,r,m)<dolve(n,M+1,aa,r,m))R=M;
		else L=M;
	}
	int ans=0x3f3f3f3f3f3f3f3fll;
	for(int i=L;i<=R;i++)ans=min(ans,dolve(n,i,aa,r,m));
	printf("%lld\n",ans);
}