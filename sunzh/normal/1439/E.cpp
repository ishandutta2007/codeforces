#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#include<random>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int m;
PII pos[1000010];
PII ed[100010];
vector<int>tre[1000010];
map<PII,int>Map;
int cnt;
int solve(int l1,int r1,int l2,int r2,vector<int>ve,int rt1,int rt2){
	if(l1==r1){
		int p=0;
		if(ve.size()) p=ve[0];
		// printf("l1:%d,r1:%d,l2:%d,r2:%d,rt1:%d,rt2:%d,p:%d\n",l1,r1,l2,r2,rt1,rt2,p);
		if(rt1&&rt2){
			if(!p){
				pos[++cnt]=mp(l1,l2);Map[mp(l1,l2)]=cnt;p=cnt;
			}
			// printf("p:%d,%d %d\n",p,rt1,rt2);
			tre[p].pb(rt1);tre[p].pb(rt2);return p;
		}
		else if(rt1){
			if(!p)return rt1;
			// printf("p:%d,%d\n",p,rt1);
			tre[p].pb(rt1);return p;
		}
		else if(rt2){
			if(!p)return rt2;
			// printf("p:%d,%d\n",p,rt2);
			tre[p].pb(rt2);return p;
		}
		else return p;
	}
	int mid1=(l1+r1>>1);
	int mid2=(l2+r2>>1);
	vector<int>ve1,ve2,ve3;
	for(int i:ve){
		if(pos[i].fi>mid1) ve1.pb(i);
		else if(pos[i].se>mid2) ve2.pb(i);
		else ve3.pb(i);
	}
	int nt1=0,nt2=0;
	if(ve1.size()){
		nt1=solve(mid1+1,r1,l2,mid2,ve1,rt1,0);
	}
	else nt1=rt1;
	if(ve2.size()){
		nt2=solve(l1,mid1,mid2+1,r2,ve2,0,rt2);
	}
	else nt2=rt2;
	return solve(l1,mid1,l2,mid2,ve3,nt1,nt2);
}
map<int,int>oper;
int dep[1000010];
int getdep(int l1,int r1,int l2,int r2,int x,int y){
	// printf("%d %d %d %d %d %d\n",l1,r1,l2,r2,x,y);
	if(l1==r1) return 1;
	int mid1=(l1+r1>>1);
	int mid2=(l2+r2>>1);
	if(x>mid1) return getdep(mid1+1,r1,l2,mid2,x,y)+(mid1-l1+1);
	if(y>mid2) return getdep(l1,mid1,mid2+1,r2,x,y)+(mid2-l2+1);
	return getdep(l1,mid1,l2,mid2,x,y);
}
int depth[1000010];
int fa[1000010][20];
void dfs(int x,int f){
	// printf("x:%d,f:%d\n",x,f);
	depth[x]=depth[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=19;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int v:tre[x]) if(v!=f){
		dfs(v,x);
	}
}
int sum[1000010],islca[1000010];
int logt[1000010];
void dfs2(int x,int f){
	for(int v:tre[x]) if(v!=f){
		dfs2(v,x);sum[x]+=sum[v];
	}
	// printf("x:%d,sum:%d,%d\n",x,sum[x],islca[x]);
	int a1=sum[x]-2*islca[x];
	if(a1){
		oper[dep[f]+1]^=1;oper[dep[x]]^=1;
	}
	int a2=sum[x]-islca[x];
	if(a2){
		oper[dep[x]]^=1;oper[dep[x]+1]^=1;
	}
	sum[x]-=2*islca[x];
	// if(sum[x]){
		// printf("x:%d,%d %d,f:%d,%d %d\n",x,pos[x].fi,pos[x].se,f,dep[f],dep[x]);
		// oper[dep[f]+1]^=1;oper[dep[x]+1]^=1;
	// }
}
int main(){
	m=read();
	vector<int>vec;
	for(int i=1;i<=m;++i){
		int x1=read(),y1=read(),x2=read(),y2=read();
		if(!Map.count(mp(x1,y1))) Map[mp(x1,y1)]=++cnt,pos[cnt]=mp(x1,y1);
		if(!Map.count(mp(x2,y2))) Map[mp(x2,y2)]=++cnt,pos[cnt]=mp(x2,y2);
		ed[i]=mp(Map[mp(x1,y1)],Map[mp(x2,y2)]);
	}
	for(int i=1;i<=cnt;++i) vec.pb(i);
	int rt=solve(0,(1<<30)-1,0,(1<<30)-1,vec,0,0);
	// for(int i=1;i<=cnt;++i){
		// printf("i:%d,=%d %d\n",i,pos[i].fi,pos[i].se);
	// }
	// for(int i=1;i<=cnt;++i){
	// 	for(int v:tre[i]) printf("%d %d\n",i,v);
	// }
	for(int i=2;i<=cnt;++i) logt[i]=logt[i>>1]+1;
	for(int i=1;i<=cnt;++i){
		dep[i]=getdep(0,(1<<30)-1,0,(1<<30)-1,pos[i].fi,pos[i].se);
		// printf("%d %d,%d\n",pos[i].fi,pos[i].se,dep[i]);
	}
	dfs(rt,0);
	for(int i=1;i<=m;++i){
		int px=ed[i].fi,py=ed[i].se;
		++sum[px];++sum[py];
		if(depth[px]<depth[py]) swap(px,py);
		while(depth[px]>depth[py]) px=fa[px][logt[depth[px]-depth[py]]];
		for(int j=logt[depth[px]];j>=0;--j) if(fa[px][j]!=fa[py][j]) px=fa[px][j],py=fa[py][j];
		int lca=(px==py?px:fa[px][0]);islca[lca]++;
		// printf("px:%d,py:%d,lca:%d\n",px,py,lca);
	}
	dfs2(rt,0);
	int ans=0;
	int lstpo=0,lstval=0;
	for(auto i:oper){
		// printf("%d %d\n",i.fi,i.se);
		if(i.se){
			if(lstval){
				lstval=0; ++ans;
			}
			else{
				lstval=1;
				if(lstpo!=0) ++ans;
				lstpo=i.fi;
			}
		}
		else continue ;
	}printf("%d\n",ans);
}