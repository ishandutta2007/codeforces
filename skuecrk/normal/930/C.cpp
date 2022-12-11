#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define N 131072
int a[MN+5],t[N*2+5],f[MN+5];
int query(int l,int r)
{
	int res=0;
	for(l+=N,r+=N+2;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=max(res,t[l+1]);
		if( r&1)res=max(res,t[r-1]);
	}
	return res;
}
void rw(int k,int x){for(k+=N+1;k;k>>=1)t[k]=max(t[k],x);}
int main()
{
	int n,m,i,x,ans=0;
	n=read();m=read();
	while(n--)++a[read()],--a[read()+1];
	for(i=1;i<=m;++i)a[i]+=a[i-1],rw(a[i],f[i]=query(0,a[i])+1);
	memset(t,0,sizeof(t));
	for(i=m;i;--i)ans=max(ans,f[i]+(x=query(0,a[i]))),rw(a[i],x+1);
	printf("%d",ans);
}