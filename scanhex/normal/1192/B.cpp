#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
//#define int long long


const nagai oo=0x3f3f3f3f3f3f3f3f;
const int LG=17;
const int N=1<<LG;
struct it{
	pair<nagai,int> t[2*N];
	nagai psh[2*N];
	it(){
		for(int i=2*N-1;i>0;--i)
			if(i>=N)t[i].second=i-N;
			else
				t[i].second=t[2*i].second;
	}
	void app(int x,nagai y){
		 t[x].first+=y;
		 psh[x]+=y;
	}
	void push1(int u){
		 app(2*u,psh[u]);
		 app(2*u+1,psh[u]);
		 psh[u]=0;
	}
	void push(int u){
		 for(int i=LG;i;--i)
			 push1(u>>i);
	}
	void upd(int x){
		 while(x>1)
			 t[x>>1]=max(t[x],t[x^1]),x>>=1;
	}
	void add(int l,int r,nagai v){
		if(l>=r)return;
		l+=N;
		r+=N;
		int l1=l,r1=r;
		while(l<r){
			 if(l&1)app(l++,v);
			 if(r&1)app(--r,v);
			 l/=2,r/=2;
		}
		push(l1);
		push(r1-1);
		upd(l1);
		upd(r1-1);
	}
	pair<nagai,int> getmax(int l,int r){
		if(l>=r)return {-oo,-1};
		l+=N;
		r+=N;
		push(l);
		push(r-1);
		pair<nagai,int>ans={-oo,-1};
		while(l<r){
			 if(l&1)ans=max(ans,t[l++]);
			 if(r&1)ans=max(ans,t[--r]);
			 l/=2,r/=2;
		}
		return ans;
	}
} depit,hldit;
int n,q;
vector<tuple<int,nagai,int>>g[N];
nagai w[N];
int id[N];
int invid[N];
nagai dew[N];
int de[N];
int par[N];
int ups[LG][N];
int tin[N],tout[N];
int sz[N];
int top[N];
vector<int>ch[N];

void d(int u,int p=-1){
	sz[u]=1;
	for(auto&[v,w,i]:g[u]){
		if(v==p)continue;
		::w[v]=w;
		id[v]=i;
		ups[0][v]=u;
		invid[i]=v;
		dew[v]=dew[u]+w;
		par[v]=u;
		de[v]=de[u]+1;
		d(v,u);
		sz[u]+=sz[v];
		ch[u].push_back(v);
		if(sz[v]>sz[ch[u][0]])
			swap(ch[u][0],ch[u].back());
	}
}
int tot=0;
vector<int>ord;
void d1(int u){
	tin[u]=tot++;
	ord.push_back(u);
	for(int v:ch[u]){
		if(v==ch[u][0])
			top[v]=top[u];
		else
			top[v]=v;
		d1(v);
	}
	tout[u]=tot;
}
void cups(){
	for(int i=0;i+1<LG;++i)
		for(int j=0;j<n;++j)
			ups[i+1][j]=ups[i][ups[i][j]];
}
int goup(int x,int y){
	for(int i=0;i<LG;++i)
		if(y>>i&1)x=ups[i][x];
	return x;
}
nagai W;
nagai getone(){
	auto p=depit.getmax(0,n);
	int v=ord[p.second];
	int xd=goup(v,de[v]-1);
	auto q=depit.getmax(0,tin[xd]);
	auto t=depit.getmax(tout[xd],n);
	return p.first+max(0LL,max(q.first,t.first));
}
void recalc(int u){
	nagai de=depit.getmax(tin[u],tin[u]+1).first;
	nagai old=hldit.getmax(tin[u],tin[u]+1).first;
	nagai mx=0;
	if(ch[u].size()>1)
		mx=depit.getmax(tin[ch[u][1]],tout[u]).first;
	nagai nw=mx-2*de;
	hldit.add(tin[u],tin[u]+1,nw-old);
}
void inc_edge(int v,nagai w){
	depit.add(tin[v],tout[v],w);
	::w[v]+=w;
	hldit.add(tin[v],tout[v],-w);
//	cerr<<hldit.getmax(tin[v],tin[v]+1).first<<'\n';
//	cerr<<"INC "<<v<<'\n';
	while(top[v]!=0){
		v=top[v];
		v=par[v];
		recalc(v);
//		cerr<<v<<'\n';
	}
}
nagai get_most_remote(int x){
	nagai de=depit.getmax(tin[x],tin[x]+1).first;
	nagai ans=0;
	while(true){
		int t=top[x];
		/*
		for(int i=tin[t];i<tin[x];++i){
			int old=hldit.getmax(i,i+1).first;
			recalc(ord[i]);
			int nw=hldit.getmax(i,i+1).first;
//			if(old!=nw)cerr<<ord[i]<<' '<<old<<' '<<nw<<'\n';
		}
		*/
		ans=max(ans,hldit.getmax(tin[t],tin[x]).first+de);
		if(t==0)break;
		x=par[t];
		nagai mx=max(depit.getmax(tin[x],tin[t]),depit.getmax(tout[t],tout[x])).first;
		ans=max(ans,mx+de-2*depit.getmax(tin[x],tin[x]+1).first);
	}
	return ans;
}
nagai getfull(){
	auto p=depit.getmax(0,n);
	return get_most_remote(ord[p.second]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q>>W;
	for(int i=0;i<n-1;++i){
		 int a,b;
		 nagai c;
		 cin>>a>>b>>c;
		 --a,--b;
		 g[a].emplace_back(b,c,i);
		 g[b].emplace_back(a,c,i);
	}
	d(0);
	d1(0);
	cups();
	for(int i=0;i<n;++i)
		depit.add(i,i+1,dew[ord[i]]);
	for(int i=0;i<n;++i)
		recalc(i);
	nagai last=0;
	while(q--){
		int d;
		nagai e;
		cin>>d>>e;
		d=(d+last)%(n-1);
		e=(e+last)%W;
		int v=invid[d];
		e-=w[v];
		inc_edge(v,e);
		last=getfull();
		cout<<last<<'\n';
	}
	return 0;
}