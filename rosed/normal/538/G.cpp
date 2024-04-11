#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10,M=2e6+10,inf=0x3f3f3f3f3f3f3f3f;
	int n,m;
	int sum,dk,db,dt,flag1,flag2,flagsum,maxsum,minsum;
	int ans[2][M<<1];
	struct node
	{
		int k,t,x,y,b;
		inline bool operator < (const node &other) const
		{
			return t<other.t;
		}
	}a[N];
	inline int getflag(int x)
	{
		x%=2;
		return x==-1?1:x;
	}
	inline void fail()
	{
		puts("NO");exit(0);
	}
	inline void main()
	{
		n=read(),m=read();
		for(int t,x,y,i=1;i<=n;++i)
		{
			t=read(),x=read(),y=read();
			a[i]=(node){0,t,x+y,y-x};
		}
		for(int i=1;i<=n;++i) a[i].k-=a[i].t/m,a[i].t%=m;
		a[++n]=(node){0,0,0,0},a[++n]=(node){1,m,0,0};
		sort(a+1,a+n+1);
		for(int cho=0;cho<2;++cho)
		{
			flagsum=-1,minsum=-m-1,maxsum=m+1;
			for(int i=1;i<=n;++i) a[i].b=cho?a[i].y:a[i].x;
			for(int i=1;i<n;++i)
			{
				dk=a[i+1].k-a[i].k;
				db=a[i+1].b-a[i].b;
				dt=a[i+1].t-a[i].t;
				flag1=getflag(dt-db);
				flag2=getflag(dk);
				if(flag1&&flag2)
				{
					if(!flagsum) fail();
					flagsum=1;
				}
				else if(!flag1&&flag2)
				{
					if(flagsum==1) fail();
					flagsum=0;
				}
				else if(flag1&&!flag2) fail();
				if(dk>0)
				{
					maxsum=min(maxsum,(int)floor((dt-db)/(long double)dk));
					minsum=max(minsum,(int)ceil((-dt-db)/(long double)dk));
				}
				else if(dk<0)
				{
					maxsum=min(maxsum,(int)floor((dt+db)/(long double)-dk));
					minsum=max(minsum,(int)ceil((-dt+db)/(long double)-dk));
				}
				else if(!(-dt<=db&&db<=dt)) fail();
				if(minsum>maxsum) fail();
			}
			sum=minsum;if(~flagsum&&getflag(sum)!=flagsum) ++sum;
			if(sum>maxsum) fail();
			for(int i=1;i<=n;++i) a[i].b=a[i].b+a[i].k*sum;
			for(int i=1;i<n;++i)
			{
				db=a[i+1].b-a[i].b;
				dt=a[i+1].t-a[i].t;
				if(db<0)
				{
					for(int j=a[i].t;j<a[i].t-db;++j)
						ans[cho][j]=-1;
				}
				else if(db>0)
				{
					for(int j=a[i].t;j<a[i].t+db;++j)
						ans[cho][j]=1;
				}
				for(int j=a[i].t+abs(db);j<a[i+1].t;++j)
					ans[cho][j]=j&1?1:-1;
			}
		}
		for(int i=0;i<m;++i)
		{
			if(ans[0][i]== 1&&ans[1][i]== 1) putchar('U');
			if(ans[0][i]==-1&&ans[1][i]==-1) putchar('D');
			if(ans[0][i]== 1&&ans[1][i]==-1) putchar('R');
			if(ans[0][i]==-1&&ans[1][i]== 1) putchar('L');
		}
		puts("");
	}
}
signed main()
{
	red::main();
	return 0;
}