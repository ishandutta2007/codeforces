#include<bits/stdc++.h>
using namespace std;
template<class T>
struct segtree
{
	struct node
	{
		int l,r;
		T info;
		node *lson,*rson;
		void upd()
		{
			info=lson->info+rson->info;
		}
	}*root,pool[1111111];
	int top=0;
	node *build(int l,int r,const vector<int> &pos)
	{
		node *ret=&pool[top++];
		ret->l=l;ret->r=r;
		if(l!=r)
		{
			int mid=(l+r)/2;
			ret->lson=build(l,mid,pos);
			ret->rson=build(mid+1,r,pos);
			ret->upd();
		}
		else
		{
			ret->info={pos[l],pos[l],pos[l]};
		}
		return ret;
	}
	void change(node *cur,int pos,int x)
	{
		if(cur->l==cur->r)
		{
			cur->info={x,x,x};
			return;
		}
		if(cur->lson->r>=pos)change(cur->lson,pos,x);
		else change(cur->rson,pos,x);
		cur->upd();
	}
	int query(node *cur,T pre)
	{
//		cerr<<"query "<<cur->l<<' '<<cur->r<<endl;
		if(cur->l==cur->r)return cur->l;
		auto tmp=pre+cur->lson->info;
		if(tmp.l!=-1)return query(cur->rson,tmp);
		else return query(cur->lson,pre);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> a(n+5),pos(n+5),pa(n+5),dep(n+5);
	static vector<int> st(n+5),ed(n+5);
	vector<vector<int>> jmp(20,vector<int>(n+5));
	vector<vector<int>> G(n+5);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	pos[n]=-1;
	for(int i=2;i<=n;i++)
	{
		cin>>pa[i];
		G[pa[i]].emplace_back(i);
		jmp[0][i]=pa[i];
	}
	int idx=0;
	function<void(int)> dfs=[&](int u)
	{
		st[u]=++idx;
		for(auto v:G[u])
		{
			dep[v]=dep[u]+1;
			dfs(v);
		}
		ed[u]=idx;
	};
	dep[1]=1;
	dfs(1);//pa dep
	for(int d=1;d<=17;d++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[d][i]=jmp[d-1][jmp[d-1][i]];
		}
	}
	static function<int(int,int)> getlca=[&](int u,int v)
	{
		if(dep[u]>dep[v])swap(u,v);
		for(int d=17;d>=0;d--)
		{
			if(dep[jmp[d][v]]>=dep[u])
				v=jmp[d][v];
		}
		if(u==v)return u;
		for(int d=17;d>=0;d--)
		{
			if(jmp[d][v]!=jmp[d][u])
				u=jmp[d][u],v=jmp[d][v];
		}
		while(u!=v)u=pa[u],v=pa[v];
		return u;
	};
	struct info
	{
		int l,r,u;
		info operator+(const info &x)const
		{
//			cerr<<"merge "<<l<<' '<<r<<' '<<x.l<<' '<<x.r<<endl;
			if(l==0)return x;
			if(l==-1 or x.l==-1)return {-1,-1,-1};
			int lca=getlca(u,x.u);
			auto chk=[&](int a,int b){return st[a]<=st[b] and ed[b]<=ed[a];};
//			cerr<<"lca "<<lca<<endl;
			int L=lca,R=lca;
			if(chk(L,l))L=l;
			else if(chk(R,L) and chk(R,l) and not chk(l,L))R=l;
			else if(not chk(R,L) and chk(R,l))R=l;
			else if(not chk(lca,l))return {-1,-1,-1};
			else if(not chk(l,L) and not chk(l,R))return {-1,-1,-1};
//			cerr<<"step 1 "<<l<<' '<<L<<' '<<R<<endl;
			if(chk(L,r))L=r;
			else if(chk(R,L) and chk(R,r) and not chk(r,L))R=r;
			else if(not chk(R,L) and chk(R,r))R=r;
			else if(not chk(lca,r))return {-1,-1,-1};
			else if(not chk(r,L) and not chk(r,R))return {-1,-1,-1};
//			cerr<<"step 2 "<<r<<' '<<L<<' '<<R<<endl;
			if(chk(L,x.l))L=x.l;
			else if(chk(R,L) and chk(R,x.l) and not chk(x.l,L))R=x.l;
			else if(not chk(R,L) and chk(R,x.l))R=x.l;
			else if(not chk(lca,x.l))return {-1,-1,-1};
			else if(not chk(x.l,L) and not chk(x.l,R))return {-1,-1,-1};
//			cerr<<"step 3 "<<x.l<<' '<<L<<' '<<R<<endl;
			if(chk(L,x.r))L=x.r;
			else if(chk(R,L) and chk(R,x.r) and not chk(x.r,L))R=x.r;
			else if(not chk(R,L) and chk(R,x.r))R=x.r;
			else if(not chk(lca,x.r))return {-1,-1,-1};
			else if(not chk(x.r,L) and not chk(x.r,R))return {-1,-1,-1};
//			cerr<<"step 4 "<<x.r<<' '<<L<<' '<<R<<endl;
//			cerr<<"res "<<L<<' '<<R<<endl;
			if(getlca(L,R)!=lca)return {-1,-1,-1};
			return {L,R,lca};
		}
	};
	segtree<info> seg;
	seg.root=seg.build(0,n,pos);
	int q;
	cin>>q;
	while(q--)
	{
		int ty;
		cin>>ty;
		if(ty==1)
		{
			int x,y;
			cin>>x>>y;
			seg.change(seg.root,a[y],x);
			seg.change(seg.root,a[x],y);
			swap(a[x],a[y]);
			swap(pos[a[x]],pos[a[y]]);
		}
		else
		{
			int ans=seg.query(seg.root,{0,0,0});
			cout<<ans<<"\n";
		}
	}
	return 0;
}