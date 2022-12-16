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
	const int N=1e6+10,inf=2e9;
	int n,m;
	int a[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			int l1,l2,r1,r2;
			cin>>l1>>r1>>l2>>r2;
			int l=max(l1,l2),r=min(r1,r2);
			if(l<=r) cout<<l<<'\n';
			else cout<<l1+l2<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}

/*
aacaccac

*/