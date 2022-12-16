#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=50;
	int n,m,q;
	string s1[N],s2[N];
	inline void main()
	{
		n=read(),m=read();
		for(int i=0;i<n;++i) cin>>s1[i];
		for(int i=0;i<m;++i) cin>>s2[i];
		q=read();
		for(int x,i=1;i<=q;++i)
		{
			x=read()-1;
			cout<<s1[x%n]<<s2[x%m]<<endl;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}