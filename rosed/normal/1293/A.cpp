#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1010;
	int haku;
	int n,now,pos,m,ret;
	int a[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),now=read(),m=read();
			for(int i=1;i<=m;++i) a[i]=read();
			a[0]=a[m+1]=1e18;
			sort(a+1,a+m+1);
			pos=0;
			for(int i=1;i<=m;++i)
			{
				if(a[i]==now)
				{
					pos=i;
					break;
				}
			}
			if(!pos)
			{
				puts("0");
				continue;
			}
			ret=1e18;
			int t=1;
			while(a[pos+t]==a[pos]+t) ++t;
			if((pos+t<=m)||a[m]!=n) ret=min(ret,t);
			t=1;
			while(a[pos-t]==a[pos]-t) ++t;
			if((pos-t)||a[1]!=1) ret=min(ret,t);
			cout<<ret<<endl;
		}
	}
}
signed main()
{
	red::main(); 
return 0;
}