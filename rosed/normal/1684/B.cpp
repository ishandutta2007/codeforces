#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			int a,b,c,x,y,z;
			x=y=z=0;
			cin>>a>>b>>c;
			
			x=a+c*b;
			y=b;
			z=c;

			cout<<x<<' '<<y<<' '<<z<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
x-y=a
y-z=b
z-x=c
x-z=a+b
z-y=a+c
y-x=b+c
x-y=2*a+b+c


x=yz+a
y=xz+b
z=xy+c


*/