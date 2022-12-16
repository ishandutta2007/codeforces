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
	int n,m,sum;
	int a[N],t[N];
	int col,tim;
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=1;i<=m;++i)
		{
			int opt,x,y;
			cin>>opt;
			if(opt==1)
			{
				cin>>x>>y;
				if(tim>t[x]) sum+=y-col;
				else sum+=y-a[x];
				a[x]=y,t[x]=i;
			}
			else
			{
				cin>>x;
				sum=n*x;
				col=x;tim=i;
			}
			cout<<sum<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}