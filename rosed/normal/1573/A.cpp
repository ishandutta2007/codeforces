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
	int T,n,ans; 
	string s;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			cin>>s;
			ans=(s[n-1]-'0');
			for(int i=0;i<n-1;++i) if(s[i]!='0')
				ans+=(s[i]-'0'+1);
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}