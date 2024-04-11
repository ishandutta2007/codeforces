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
	const int N=3e5+10,mod=998244353;
	int T,n;
	int a[4];
	inline void main()
	{
		T=read();
		while(T--)
		{
			a[1]=read(),a[2]=read(),a[3]=read();
			sort(a+1,a+3+1);
			if(a[3]==a[1]+a[2]) puts("YES");
			else if((a[1]==a[2]&&a[3]%2==0)||(a[2]==a[3]&&a[1]%2==0)) puts("YES");
			else puts("NO");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}