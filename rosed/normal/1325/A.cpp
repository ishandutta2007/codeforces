#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=4e5+10;
	int haku;
	int n,m,ans;
	int a,b,c;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			cout<<1<<' '<<n-1<<endl;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}