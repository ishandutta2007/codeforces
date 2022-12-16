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
	int a[N],p[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			for(int i=1;i<=n;++i)
			{
				int j=i;
				while(j<n&&a[j+1]==a[j]) ++j;
				if(i==j)
				{
					flag=1;break;
				}
				for(int k=i;k<j;++k)
				{
					p[k]=k+1;
				}
				p[j]=i;
				i=j;
			}
			if(flag) cout<<"-1\n";
			else
			 for(int i=1;i<=n;++i) cout<<p[i]<<" \n"[i==n];
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
3
5
4 1 2 3 5
3 1 2 3
2 1 2
1 1
1 4
4
3 1 2 3
3 2 3 4
0
4 1 2 3 4
2
3 1 3 5
3 2 3 4

*/