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
	const int N=100+10,inf=2e9;
	int n,m;
	char s[N][N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				cin>>(s[i]+1);
			}
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
				{
					if(s[i][j]=='E') continue;
					bool tmp=0;
					for(int x=1;x<=n;++x)
					{
						for(int y=1;y<=m;++y)
						{
							if(s[x][y]=='E') continue;
							if(x<i||y<j) tmp=1;
						}
					}
					if(!tmp) flag=1;
				}
			}
			if(flag) cout<<"YES\n";
			else cout<<"NO\n";
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