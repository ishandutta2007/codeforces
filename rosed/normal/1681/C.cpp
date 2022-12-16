#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	int n,m;
	int num;
	struct node
	{
		int x,y,id;
		inline bool operator < (const node &t) const
		{
			if(x!=t.x) return x<t.x;
			return y<t.y;
		}
	}a[N],s[N];
	int id[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;num=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i].x;
				a[i].id=i;
				id[i]=i;
			}
			for(int i=1;i<=n;++i)
			{
				cin>>a[i].y;
			}
			sort(a+1,a+n+1);
			bool flag=0;
			for(int i=2;i<=n;++i)
			{
				if(a[i].y<a[i-1].y)
				{
					flag=1;break;
				}
			}
			if(flag)
			{
				cout<<"-1\n";
				continue;
			}
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(id[j]==a[i].id)
					{
						if(i!=j)
						{
							s[++num]=(node){i,j};
							swap(id[i],id[j]);
						}
						break;
					}
				}
			}
			cout<<num<<'\n';
			for(int i=1;i<=num;++i) cout<<s[i].x<<' '<<s[i].y<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6
2
1 2
1 2
2
2 1
1 2
4
2 3 1 2
2 3 2 3
2
1 2
1 2
2
2 1
1 2
4
2 3 1 2
2 3 2 3

*/