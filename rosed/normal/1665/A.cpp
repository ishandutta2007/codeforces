#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n;
	int a,b,c,d;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;
			int op=n;
			if(n%4==0)
			{
				a=b=c=d=n/4;
			}
			if(n%4==1)
			{
				d=1;
				--n;
				a=c=n/4;
				b=2*a;
			}
			if(n%4==2)
			{
				c=d=1;
				n-=2;
				a=n/2-1;
				b=n/2+1;
			}
			if(n%4==3)
			{
				d=1;
				a=c=2;
				b=n-5;
				//n*4+2
			}
			cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
10
4
5
6
7
8
9
10
11
12
13

*/