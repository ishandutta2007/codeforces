#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
	const int N=3e5+10,mod=998244353;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			int n;cin>>n;
			if(n%7==0) cout<<n<<'\n';
			else
			{
				for(int i=0;i<=9;++i)
				{
					int x=n/10*10+i;
					if(!x) continue;
					if(x%7==0)
					{
						cout<<x<<'\n';
						break;
					}
				}
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;	
}
/*
5 7
1 2 3 4 5
1 1 5
2 1 5

3 1 2 1
1 1 4
4 1 3 2
1 1 4
2 2 3

*/