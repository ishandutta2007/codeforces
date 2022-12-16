#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=1e5+10;
	int T,n,m,ans;
	int a[N];
	inline void main()
	{
		n=read();
		for(int x,i=1;i<=n;++i)
		{
			x=read();
			if(i%2==0) x=-x;
			a[i]=x;
			if(i%2==0) ans+=min(a[i-1],-a[i]);
		}
	//	cout<<ans<<"!!!"<<endl;
		for(int s,f1,s1,l=1;l<=n;l+=2)
		{
			s=f1=s1=0;
			for(int x,r=l;r<=n;++r)
			{
				if(r&1)
				{
					x=a[r];
					if(x)
					continue; 
				}
				x+=a[r];
				if(s&&x<0)
				{
					int t=min(s,-x);
					s-=t,x+=t;
				}
				if(s1>=0&&x<=0&&r-l>2)
				{
					int t=min(s1,-x);
					s1-=t,x+=t;
					ans+=t;
				}
				if(s1>=0&&x+s<=0&&r-l>2) ++ans;
				if(!f1) s1+=x,f1=1;
				else s+=x;
				if(s1+s+x<0) break;
				
			}
		//	cout<<ans<<"!"<<endl;
		}
		printf("%lld\n",ans);
	}
}
signed main()
{
//	freopen("data.in","r",stdin);
//	freopen("red.out","w",stdout);
	red::main();
	return 0;
}
/*
6
3 2 2 2 1 2

6
2 2 1 1 3 4


*/