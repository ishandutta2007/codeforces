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
	const int N=3e5+10;
	int n;
	int a[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			int n;cin>>n;
			int t1=n/4;
			if((n%4!=2&&n%4!=0)||n<4)
			{
				cout<<"-1\n";
				continue;
			}
			cout<<(n-1)/6+1<<' '<<n/4<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}