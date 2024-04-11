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
	int a,b,c;
	int x,y,g;
	inline void exgcd(int &x,int &y,int &g,int a,int b)
	{
		if(!b)
		{
			x=1,y=0,g=a;
			return;
		}
		exgcd(y,x,g,b,a%b);
		y-=a/b*x;
	}
	inline void main()
	{
		a=read(),b=read(),c=read();
		exgcd(x,y,g,a,b);
		if(-c%g)
		{
			puts("-1");
			return;
		}
		x*=-c/g,y*=-c/g;
		cout<<x<<' '<<y<<endl;
	}
}
signed main()
{
	red::main();
	return 0;
}