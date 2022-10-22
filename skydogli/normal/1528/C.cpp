
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
#define MN 300005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int tt,n,m;
int a[MN],b[MN];
vc e[MN],g[MN];
int id[MN],cnt,tot,fa[MN],siz[MN];
void DFS(int x){
	id[x]=++tot;
	for(auto v:g[x]){
		fa[v]=x;DFS(v);
	}
}
#define itset set<pii >::iterator
int ans;
set<pii>S;
void dfs(int x){
	pii w=mp(id[x],id[x]+siz[x]-1);
	pii fk=mp(0,0);
	itset it=S.lower_bound(w);
	if(it==S.end()||(*it).x>w.y){
		S.insert(w);	
		itset it=S.lower_bound(w);
		if(it!=S.begin()){
			itset ir=it;ir--;
			if((*ir).y>=w.x)fk=*ir,S.erase(ir);
		}
	}
	ans=max(ans,(int)S.size());
	for(auto v:e[x]){
		dfs(v);
	}
	if(S.find(w)!=S.end())S.erase(w);
	if(fk.x)S.insert(fk);
}
signed main(){
	tt=read();
	while(tt--){
		ans=1;
		tot=0;
		n=read();	
		for(int i=2;i<=n;++i){
			a[i]=read();
			e[a[i]].pb(i);
		}
		for(int i=2;i<=n;++i){
			b[i]=read();
			g[b[i]].pb(i);
		}
		for(int i=n;i;--i){
			siz[i]++;siz[b[i]]+=siz[i];
		}
		DFS(1);
		dfs(1);
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)e[i].clear(),g[i].clear(),siz[i]=0;
	}
	return 0;
}