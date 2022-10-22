#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 400005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int n,m;
string ch[MN];
int F[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
int id(int x,int y){
	return (x-1)*m+y;
}
int dfn[MN],belong[MN],deg[MN],low[MN],Ti;
int st[MN],ins[MN],top,rp,loc[MN];
vector<int>e[MN],E[MN];
vector<pii >seq[MN];
void dfs(int x){
	dfn[x]=low[x]=++Ti;
	st[++top]=x;
	ins[x]=1;
	for(auto v:e[x]){
		if(!dfn[v]){dfs(v);low[x]=min(low[x],low[v]);}
		else if(ins[v]){low[x]=min(low[x],dfn[v]);}
	}
	if(dfn[x]==low[x]){
		++rp;
		while(st[top+1]!=x){
			ins[st[top]]=0;
			belong[st[top]]=rp;
			top--;
		}
	}
}
bool vis[MN];
int L[MN],R[MN];
bool cmp(pii a,pii b){if(a.y==b.y)return a.x>b.x;return a.y>b.y;}
void work(int x){
	if(vis[x])return;
	vis[x]=1;
//	cerr<<"fk "<<x<<": "<<L[x]<<" "<<R[x]<<endl;
	for(int i=0;i<E[x].size();++i){
		int v=E[x][i];
		work(v);
//		seq[x].pb(mp(L[v],R[v]));
//		L[x]=min(L[x],L[v]);
//		R[x]=max(R[x],R[v]);
	}
//	sort(seq[x].begin(),seq[x].end());
//	for(auto i:seq[x])
//		if(max(i.x,L[x])<=min(i.y,R[x])+1)R[x]=max(R[x],i.y);
//	sort(seq[x].begin(),seq[x].end(),cmp);
//	for(auto i:seq[x])
//		if(max(i.x,L[x])<=min(i.y,R[x])+1)L[x]=min(L[x],i.x);
//	cerr<<"done "<<x<<": "<<L[x]<<" "<<R[x]<<endl;
}
int val[MN],a[MN],ok[MN];
pii b[MN];
int f[MN],mn[MN];
bool fk[MN],app[MN];
void DFS(int x){
	for(auto v:E[x]){
		if(!app[v]){
			app[v]=1;
			DFS(v);
		}
	}
}
signed main(){
	srand(233);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>ch[i];
		ch[i]=" "+ch[i];
	}
	for(int i=1;i<=m;++i){
		int tot=0;for(int j=1;j<=n;++j)if(ch[j][i]=='#')tot++;
	//	a[i]=tot;
		a[i]=read();
	}
	for(int i=1;i<=n*m;++i)F[i]=i;
	for(int j=1;j<=m;++j){
		int lst=0,tot=0;
		for(int i=1;i<=n;++i){
			if(ch[i][j]=='#'){
				if(lst) e[lst].pb(id(i,j));
				lst=id(i,j);
				if(i>1&&ch[i-1][j]=='#')e[lst].pb(id(i-1,j));
			}
			if(j>1&&ch[i][j-1]=='#'&&lst)e[lst].pb(id(i,j-1));
			if(j<m&&ch[i][j+1]=='#'&&lst)e[lst].pb(id(i,j+1));
		}
		for(int i=n;i;--i){
			if(ch[i][j]=='#'){	
				tot++;
				if(tot==a[j])val[id(i,j)]=j;
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='#'&&!belong[id(i,j)])dfs(id(i,j));
	for(int i=1;i<=n*m;++i)
		for(auto j:e[i])
			if(belong[i]!=belong[j]){
				E[belong[i]].pb(belong[j]);
				deg[belong[j]]++;
			}
	int ans=0;
	for(int i=1;i<=rp;++i)L[i]=m+1,R[i]=0;
	for(int i=1;i<=n*m;++i)
		if(val[i]){
			fk[belong[i]]=1;
		}
	int tot=0;
	for(int i=1;i<=rp;++i)
		if(fk[i])DFS(i);
//	for(int i=1;i<=rp;++i)cerr<<"LR "<<i<<": "<<L[i]<<" "<<R[i]<<endl;
	for(int i=1;i<=n*m;++i)
		if(val[i]&&!app[belong[i]]){	
			tot++;
			L[belong[i]]=min(L[belong[i]],(i-1)%m+1);
			R[belong[i]]=max(R[belong[i]],(i-1)%m+1);
			ok[(i-1)%m+1]=1;
//			cerr<<"ok: "<<i<<" "<<belong[i]<<" "<<L[belong[i]]<<" "<<R[belong[i]]<<endl;
		}
//	cerr<<"tot: "<<tot<<endl;
//	for(int i=1;i<=rp;++i)work(i);
	for(int i=1;i<=m;++i)mn[i]=i;
	for(int i=1;i<=rp;++i){
		mn[R[i]]=min(mn[R[i]],L[i]);
//		cerr<<i<<": "<<L[i]<<" "<<R[i]<<endl;
	}
	st[top=1]=0;
	memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=1;i<=m;++i){
		if(!ok[i])f[i]=f[i-1];
		else{
			int l=0,r=top;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(st[mid]>=mn[i]-1)r=mid;
				else l=mid;
			}
			f[i]=f[st[r]]+1;
		}
		while(top&&f[i]<=f[st[top]])top--;
		st[++top]=i;
	}
	cout<<f[m]<<endl;
	return 0;
}