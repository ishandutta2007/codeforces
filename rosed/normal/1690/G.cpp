#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=1e9+7;
	int n,m;
	int a[N];
	int sum;
	typedef pair<int,int> pr;
	set<pr> q;
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			int pre=inf;sum=0;
			q.clear();
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				if(a[i]<pre)
				{
					++sum;
					q.insert(pr(i,a[i]));
				}
				pre=min(pre,a[i]);
			}
			for(int i=1;i<=m;++i)
			{
				int pos,d;
				cin>>pos>>d;
				a[pos]-=d;
				auto it=q.lower_bound(pr(pos,0));
				if(it!=q.begin())
				{
					--it;
					if(((*it).second)<=a[pos])
					{
						cout<<sum<<' ';
						continue;
					}
					++it;
				}
				while(it!=q.end())
				{
					auto it2=it;++it2;
					if((*it).second>=a[pos])
					{
						q.erase(it);
						--sum;
					}
					else break;
					it=it2;
				}
				++sum;
				q.insert(pr(pos,a[pos]));
				cout<<sum<<' ';
			}
			cout<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}

/*
1
5 4
10 13 5 2 6
2 4
5 2
1 5
3 2

*/