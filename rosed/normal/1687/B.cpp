#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10;
	int n,m;
	int tot,ans;
	bool vis[N];
	int e[N],id[N];
	inline bool cmp(int x,int y)
	{
		return e[x]<e[y];
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=m;++i)
		{
			cout<<"? ";
			for(int j=1;j<=m;++j)
			{
				cout<<(i==j);
			}
			cout<<endl;
			cin>>e[i];
		}
		for(int i=1;i<=m;++i) id[i]=i,vis[i]=0;
		sort(id+1,id+m+1,cmp);
	//for(int i=1;i<=m;++i) cout<<id[i]<<"!!"<<endl;
		int tot=0;
		vis[id[1]]=1,tot=e[id[1]];
		for(int i=2;i<=m;++i)
		{
			int pos=id[i];
			vis[pos]=1;
			cout<<"? ";
			for(int j=1;j<=m;++j)
			{
				cout<<vis[j];
			}
			cout<<endl;
			int tmp;cin>>tmp;
			if(tmp-tot==e[pos])
			{
				tot=tmp;
				continue;
			}
			vis[pos]=0;
		}
		cout<<"! "<<tot<<endl;
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

*/