#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,n,sum;
	int a[N],c[N],b[N],q[N];
	bool flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();flag=0;sum=0;
			for(int i=1;i<=n;++i) c[i]=b[i]=0;
			for(int x,j=1;j<=n;++j)
			{
				x=read();
				int len=(x-1)/2;
				len=min(len,n); 
		//		++c[len];
				if(x<=n)
				{
					++b[x];
					q[x]=len;
				}
				else
				{
					++c[len];
				}
			}
			int tot=0;
			for(int i=n;i;--i)
			{
			//	cout<<c[i]<<"!!"<<endl;
				tot+=c[i];
			//	if(i==2) cout<<b[i]<<' '<<tot<<"!!!"<<endl;
				if(b[i]<=0&&tot<=0) {flag=1;break;}
				if(b[i]) --b[i];
				else
				{
					--tot;
					++sum;
				}
				c[q[i]]+=b[i];
			}
			if(flag) puts("-1");
			else printf("%lld\n",sum);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
3
1 5 4
*/