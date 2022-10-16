#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

set<int>::iterator it;
int n,S,T;
int p[maxn];
int dis[maxn];
queue<int>q;
struct segment
{
	set<int>S[maxn<<2];
	void init(const int x,const int l,const int r)
	{
		set<int>_; S[x].swap(_);
		if(l==r) return;
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		init(lc,l,mid);
		init(rc,mid+1,r);
	}
	int lx,rx,c;
	void upd(const int x,const int l,const int r)
	{
		if(rx<l||r<lx) return;
		if(lx<=l&&r<=rx)
		{
			S[x].insert(c);
			return;
		}
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		upd(lc,l,mid);
		upd(rc,mid+1,r);
	}
	int loc;
	void query(const int x,const int l,const int r)
	{
		it=S[x].lower_bound(loc-p[loc]);
		while(it!=S[x].end())
		{
			int k=*it;
			if(k>loc+p[loc]) break; 
			if(dis[k]==INT_MAX)
				dis[k]=dis[loc]+1,q.push(k);
			it=S[x].erase(it);
		}
		if(l==r) return;
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		if(loc<=mid) query(lc,l,mid);
		else query(rc,mid+1,r);
	}
}seg;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int Tcase; cin>>Tcase;
	while(Tcase--)
	{
		cin>>n>>S>>T;
		seg.init(1,1,n);
		for(int i=1;i<=n;i++) cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			seg.lx=max(1,i-p[i]), seg.rx=min(n,i+p[i]);
			seg.c=i;
			seg.upd(1,1,n);
		}
		
		for(int i=1;i<=n;i++) dis[i]=INT_MAX;
		dis[S]=0; q.push(S);
		while(!q.empty())
		{
			const int x=q.front(); q.pop();
			seg.loc=x; seg.query(1,1,n);
		}
		cout<<dis[T]<<'\n';
	}
	
	return 0;
}