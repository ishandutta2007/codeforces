#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-12)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,ans;
	string s,t;
	int a[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			cin>>s>>t;ans=0;
			for(int i=0;i<26;++i) a[s[i]-'a']=i;
			n=t.length();
			for(int i=1;i<n;++i)
			{
				ans+=abs(a[t[i]-'a']-a[t[i-1]-'a']);
			}
			printf("%lld\n",ans);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}