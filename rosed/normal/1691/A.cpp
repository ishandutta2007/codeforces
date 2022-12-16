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
	int a[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			int s1=0,s2=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				if(a[i]&1) ++s1;
				else ++s2;
			}
			cout<<min(s1,s2)<<'\n';
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