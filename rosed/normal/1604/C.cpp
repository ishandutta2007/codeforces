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
	const int N=3e5+10,mod=998244353;
	int T,n,lcm;
	bool flag;
	int a[N];
	inline int gcd(int a,int b)
	{
		return b?gcd(b,a%b):a; 
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();lcm=2;flag=0;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int i=1;i<=n;++i)
			{
				lcm=lcm*(i+1)/gcd(lcm,i+1);
			//	if(i==2) cout<<lcm<<"!??????????"<<endl;
				if(lcm>1e9) break;
			//	cout<<a[i]<<' '<<lcm<<"!!!"<<endl;
				if(a[i]%lcm==0){flag=1;break;}
			}
			puts(flag?"NO":"YES");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
5
6
1 5 4 6 3 9

1 5 4

*/