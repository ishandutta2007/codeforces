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
	int hc,dc,hm,dm;
	int k,w,a;
	inline bool check(int a,int b,int c,int d)
	{
		int t1=(c-1)/b+1;
		int t2=(a-1)/d+1;
		return t1<=t2;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--)
		{
			cin>>hc>>dc>>hm>>dm;
			cin>>k>>w>>a;
			bool flag=0;
			for(int i=0;i<=k;++i)
			{
				if(check(hc+i*a,dc+(k-i)*w,hm,dm))
				{
					flag=1;break;
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