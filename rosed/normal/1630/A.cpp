#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int q[N];
	typedef pair<int,int> p;
	p st[N];
	int top;
	int c[N],num;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			int n,k;
			cin>>n>>k;
			int x=n,len=0;top=0;num=0;
			for(int i=0;i<=n;++i) q[i]=0;
			while(x>1) x/=2,++len;
			if(k!=n-1)
			{
				for(int s=0;s<n/2;++s)
				{
					st[++top]=p(s,(n-1)^s);
				}
				if(k>=n/2) {k=(n-1)^k;swap(st[1].first,st[k+1].second);}
				else swap(st[1].first,st[k+1].first);
				for(int i=1;i<=top;++i)
				{
					cout<<st[i].first<<' '<<st[i].second<<'\n';
				}
			}
			else
			{
				if(n==4) cout<<"-1\n";
				else
				{
					for(int i=0;i<len;++i)
					{
						if(i==0)
						{
							st[++top]=p(1,n-1);
							q[1]=q[n-1]=1;
						}
						else
						{
							st[++top]=p(1<<i,(n-1)^(1<<(i-1)));
							q[1<<i]=q[(n-1)^(1<<(i-1))]=1;
						}
					}
					for(int s=n-1;s>=0;--s)
					{
						if(!q[s]&&!q[(n-1)^s])
						{
							q[s]=q[(n-1)^s]=1;
							st[++top]=p(s,(n-1)^s);
						}
					}
					for(int s=n-1;s;--s)
					{
						if(!q[s])
						{
							st[++top]=p(0,s);
							break;
						}
					}
					for(int i=1;i<=top;++i)
					{
						cout<<st[i].first<<' '<<st[i].second<<'\n';
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
16 15
1111
0001 1111 1 15
0010 1110 2 14
0100 1101 4 13
1000 1011 8 11
0 3 5 6 7 9 10 12
0000 0011 0101 0110 0111 1001 1010 1100
0101-1010 5-10
0110-1001 6-9
0011-1100 3-12
0
*/