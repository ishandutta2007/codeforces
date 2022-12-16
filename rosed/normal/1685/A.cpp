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
	int b[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			sort(a+1,a+n+1);
			int d=n/2+1;
			bool flag=1;
			if(n&1) flag=0;
			if(a[1]>=a[n]) flag=0;
			int t1=1,t2=d;
			for(int i=1;i<=n;++i)
			{
				//cout<<t1-1<<' '<<t2-n/2<<"!!"<<endl;
				if(t1-1<=t2-d&&t1<d) b[i]=a[t1++];
				else b[i]=a[t2++];
				//cout<<b[i]<<"!!"<<endl;
			}
			for(int i=1;i<=n;++i)
			{
				int pre=i-1;
				if(pre<=0) pre=n;
				int nxt=i+1;
				if(nxt>n) nxt=1;
				//cout<<b[i]<<"!!"<<endl;
				if((b[i]<b[pre]&&b[i]<b[nxt])||(b[i]>b[pre]&&b[i]>b[nxt]));
				else
				{
					flag=0;
					//cout<<i<<"????"<<endl;
				}
			}
			if(flag)
			{
				cout<<"YES\n";
				for(int i=1;i<=n;++i) cout<<b[i]<<" \n"[i==n];
			}
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
4
4
3
1 1 2
4
1 9 8 4
4
2 0 2 2
6
1 1 1 11 111 1111


1
5
1 1 2 4 5


1 4 1 5 2
*/