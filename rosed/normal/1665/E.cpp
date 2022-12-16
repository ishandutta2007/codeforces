#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=1e5+10,mod=1e9+7,inf=INT_MAX;
	int n,m,num;
	int a[N],c[N];
	int rt[N];
	int st[N],top;
	struct hjt_tree
	{
		int ans[N*31],tot;
		int son[N*31][2];
		inline void update(int x,int l,int r,int pre,int &p)
		{
			p=++tot;
			ans[p]=ans[pre]+1;
			if(l==r) return;
			son[p][0]=son[pre][0],son[p][1]=son[pre][1];
			if(x<=mid) update(x,l,mid,son[pre][0],son[p][0]);
			else update(x,mid+1,r,son[pre][1],son[p][1]);
		}
		inline int query(int l,int r,int pre,int p,int k)
		{
			//cout<<l<<' '<<r<<' '<<k<<"!!"<<endl;
			//cout<<son[p][0]<<' '<<son[pre][0]<<"!!!!!!!!!!!!!!!!!!!!"<<endl;
			//cout<<ans[son[p][0]]-ans[son[pre][0]]<<"!!!"<<endl;
			if(l==r) return l;
			if(ans[son[p][0]]-ans[son[pre][0]]>=k) return query(l,mid,son[pre][0],son[p][0],k);
			return query(mid+1,r,son[pre][1],son[p][1],k-(ans[son[p][0]]-ans[son[pre][0]]));
		}
	}T;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int TT;cin>>TT;
		while(TT--)
		{
			cin>>n;T.tot=0;num=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				c[++num]=a[i];
			}
			sort(c+1,c+num+1);
			num=unique(c+1,c+num+1)-c-1;
			for(int i=1;i<=n;++i)
			{
				a[i]=lower_bound(c+1,c+num+1,a[i])-c;
				T.update(a[i],1,num,rt[i-1],rt[i]);
			}
			cin>>m;
			for(int i=1;i<=m;++i)
			{
				int l,r;cin>>l>>r;
				int maxn=min(31,r-l+1);
				for(int j=1;j<=maxn;++j)
				{
					st[j]=T.query(1,num,rt[l-1],rt[r],j);
					st[j]=c[st[j]];
					//cout<<st[j]<<"!!!!"<<endl;
				}
				int ans=inf;
				for(int j=1;j<=maxn;++j)
				{
					for(int k=j+1;k<=maxn;++k) ans=min(ans,st[j]|st[k]);
				}
				cout<<ans<<'\n';	
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
1
5
6 1 3 2 1
1
1 2

*/