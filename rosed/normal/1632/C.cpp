#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	const int N=1e5+10,mod=998244353;
	int n,m;
	int T;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>T;
		while(T--)
		{
			int a,b;
			cin>>a>>b;
			int up=0;
			int ans=b-a;
			while((1<<up)<=b) ++up;
			for(int s=b;s<(1<<up);++s)
			{
				int sum=s-b,sa=a;
				int tmp=0;
				for(int k=0;k<up;++k)
				{
					int b1=(sa>>k)&1,b2=(s>>k)&1;
					if(b1&&!b2)
					{
						
						int val=(1<<k)-tmp;tmp=0;
					//	cout<<k<<' '<<sa<<' '<<tmp<<' '<<val<<"!!"<<endl;
						sa+=val;
						sum+=val;
						continue;
					}
					tmp|=(b1<<k);
				}
				if(sa!=b) ++sum;
				ans=min(ans,sum);
			}
			cout<<ans<<'\n';
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
1 3
5 8
2 5
3 19
56678 164422
1 3
5 8
2 5
3 19
56678 164422

*/