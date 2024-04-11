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
	const int N=1e5+10,mod=998244353;
	int T;
	char s[N];
	int n;
	inline void main()
	{
		T=read(); 
		while(T--)
		{
			cin>>(s+1);
			n=strlen(s+1);
			int t1=1,t2=n;
			while(t1<t2)
			{
				if(s[t1]!=s[t2]) s[t2]=s[t1];
				while(s[t1+1]==s[t1]&&t1<=n) ++t1;
				++t1;
				while(s[t2-1]==s[t2]&&t1>=1) --t2;
				--t2;
			}
			cout<<(s+1)<<endl; 
		}
	}
}
signed main()
{
	red::main();
	return 0;
}