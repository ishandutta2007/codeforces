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
	int a[N],b[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			int maxn1=0,maxn2=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			cin>>m;
			for(int i=1;i<=m;++i)
			{
				cin>>b[i];
			}
			sort(a+1,a+n+1);
			sort(b+1,b+m+1);
			if(a[n]<b[m])
			{
				cout<<"Bob"<<'\n';
				cout<<"Bob"<<'\n';
			}
			else if(a[n]>b[m])
			{
				cout<<"Alice"<<'\n';
				cout<<"Alice"<<'\n';
			}
			else
			{
				cout<<"Alice"<<'\n';
				cout<<"Bob"<<'\n';
			}
			//cout<<"!!"<<endl;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
212
*/