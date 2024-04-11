#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int T,n;
	int t1,t2;
	int s1,s2;
	bool flag;
	int a[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i) a[i]=read();
			t1=1,t2=n;
			while(t1<t2)
			{
				if(a[t1]!=a[t2]){s1=a[t1],s2=a[t2];break;}
				++t1,--t2;
			}
			if(t1>=t2){puts("YES");continue;}
			t1=1,t2=n;
			while(t1<t2)
			{
				while(t1<t2&&a[t1]==s1) ++t1;
				while(t1<t2&&a[t2]==s1) --t2;
				if(a[t1]!=a[t2]) break;
				++t1,--t2;
			}
			if(t1>=t2){puts("YES");continue;}
			t1=1,t2=n;
			while(t1<t2)
			{
				while(t1<t2&&a[t1]==s2) ++t1;
				while(t1<t2&&a[t2]==s2) --t2;
				if(a[t1]!=a[t2]) break;
				++t1,--t2;
			}
			if(t1>=t2){puts("YES");continue;}
			puts("NO");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}