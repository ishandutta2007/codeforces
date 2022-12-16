#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n;
	int a[N];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			int tmp=0;int g=0;
			cout<<"? 1 3"<<endl;
			cin>>g;
			if(g&1) tmp=0;
			else tmp=1;
			for(int k=1;k<30;++k)
			{
				int a=(1ll<<k),b=3*a;
				a-=tmp,b-=tmp;
				cout<<"? "<<a<<' '<<b<<endl;
				cin>>g;
				if(lowbit(g)!=(1ll<<k)) tmp|=(1ll<<k);
			}
			cout<<"! "<<tmp<<endl;
			//         	  11
			//            11
			// 	101011011101
			//  101011001101
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

*/