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
	const int N=1e5+10;
	int n;
	double x,ans;
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) ans+=(1.0/i);
		cout<<ans<<endl;
	}
}
signed main()
{
	red::main(); 
return 0;
}