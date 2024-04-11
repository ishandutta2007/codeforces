#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define ep emplace_back
#define mp std::make_pair
#define PII std::pair<int,int>
#define fi first
#define se second
#define pb push_back
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m,q;
std::vector<int>vec[300010],nvec[300010];
//Forest but not tree
int dfn[300010],low[300010],belong[300010];
int idx,cnt;
std::vector<int>stcc[300010];
bool vis[300010];
int stk[300010],top;
void tarjan(int x,int fa){
	dfn[x]=low[x]=++idx;
	stk[++top]=x;vis[x]=1;
	sort(vec[x].begin(),vec[x].end());
	for(int i=0;i<vec[x].size();++i){
		int v=vec[x][i];
		if(v==fa) continue ;
		if(!dfn[v]){
			if(i!=vec[x].size()-1&&vec[x][i+1]==vec[x][i]){
				tarjan(v,0);++i;
			}
			else tarjan(v,x);low[x]=std::min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=std::min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		++cnt;
		while(stk[top]!=x){
			vis[stk[top]]=0;
			stcc[cnt].pb(stk[top]);
			belong[stk[top--]]=cnt;
		}
		vis[x]=0;
		stcc[cnt].pb(x);
		belong[stk[top--]]=cnt;
	}
}
std::map<PII,bool >Map;
namespace xu{
	int Dfn[300010],low[300010],Belong[300010];
	std::vector<int>Vec[300010];
	int fa[300010];
	int logt[300010],dep[300010],Fa[300010][20];
	int dfn[300010];
	int idx;
	bool Vis[300010];
	int Stk[300010],Top;
	int Cnt;
	void tarjan(int x,int fa){
//		printf("x:%d,fa:%d\n",x,fa);
		sort(Vec[x].begin(),Vec[x].end());
		Dfn[x]=low[x]=++idx;
		Stk[++Top]=x;
		Vis[x]=1;
		for(int i=0;i<Vec[x].size();++i){
			int v=Vec[x][i];
			if(v==fa) continue ;
			if(!Dfn[v]){
				if(i+1<Vec[x].size()&&Vec[x][i+1]==Vec[x][i]){
					tarjan(v,0);++i;
				}
				else tarjan(v,x);
				low[x]=std::min(low[x],low[v]);
			}
			else if(Vis[v]) low[x]=std::min(low[x],Dfn[v]);
		}
		if(Dfn[x]==low[x]){
			++Cnt;
			while(Stk[Top]!=x){
				Vis[Stk[Top]]=0;
				Belong[Stk[Top--]]=Cnt;
			}
			Vis[x]=0;
			Belong[Stk[Top--]]=Cnt;
		}
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool cmp(int x,int y){
		return dfn[x]<dfn[y];
	}
	int LCA(int x,int y){
//		printf("x:%d,y:%d\n",x,y);
		if(find(x)!=find(y)) return -1;
		if(dep[x]<dep[y]) std::swap(x,y);
		while(dep[x]>dep[y]){
			x=Fa[x][logt[dep[x]-dep[y]]];
		}
//		printf("x:%d,y:%d,%d %d\n",x,y,dep[x],dep[y]);
		for(int i=18;i>=0;--i){
			if(Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
		}
		int p=x==y?x:Fa[x][0];
		if(p==0){
//			printf("X:%d,Y:%d\n",x,y);
			exit(0);
		}
//		printf("lca:%d\n",);
		if(x==y) return x;
		else return Fa[x][0];
	}
	void dfs(int x,int fa){
//		printf("dfs:x:%d,fa:%d\n",x,fa);
		dfn[x]=++idx;;
		dep[x]=dep[fa]+1;
		Fa[x][0]=fa;
		for(int i=1;(1<<i)<=dep[x];++i) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
		for(int v:vec[x]){
			if(v!=fa) dfs(v,x);
		}
	}
	int stk[300010],top;
	void insert(int x){
		Vec[x].clear();Dfn[x]=low[x]=Vis[x]=Belong[x]=0;
//		printf("X:%d\n",x);
		if(!top){stk[++top]=x;return ;}
		
		int p=LCA(x,stk[top]);
		if(p==stk[top]||p==-1){
			stk[++top]=x;return ;
		}
		while(top>1&&find(stk[top-1])==find(p)&&dfn[stk[top-1]]>=dfn[p]){
			Vec[stk[top-1]].pb(stk[top]);
			Vec[stk[top]].pb(stk[top-1]);
			--top;
		}
		if(p!=stk[top]){
//			printf("p:%d\n",p);
			Vec[p].clear();Dfn[p]=low[p]=Vis[p]=Belong[p]=0;
			Vec[stk[top]].pb(p);
			Vec[p].pb(stk[top]);
			stk[top]=p;
		}
		stk[++top]=x;
	}
	void build(std::vector<int>v){
		top=0;
		for(int i:v) insert(i);
//		printf("Stk:");for(int i=1;i<=top;++i) printf("%d ",stk[i]);printf("\n");
		while(top>1){
			if(find(stk[top])==find(stk[top-1]))  Vec[stk[top]].pb(stk[top-1]),Vec[stk[top-1]].pb(stk[top]);
			--top;
		}
	}
	void solve(){
		for(int i=cnt+1;i<=n;++i) vec[i].clear();
		for(int i=1;i<=cnt;++i) fa[i]=i;
		for(int i=2;i<=cnt;++i) logt[i]=logt[i>>1]+1;
		for(int i=1;i<=cnt;++i)
			for(int v:vec[i])
				if(find(i)!=find(v))
					fa[find(i)]=find(v);
		for(int i=1;i<=cnt;++i) if(fa[i]==i)dfs(i,0);
		int R=0;
		for(int i=1;i<=q;++i){
			auto rotate=[&](int x){
				x=(x+R)%n;
				return x==0?n:x;
			};
			int N=read(),M=read();
//			printf("N:%d,M:%d\n",N,M);
			std::vector<int>fav,nod;
			std::vector<PII>edg;
			for(int i=1;i<=N;++i){
				int x=rotate(read());
				fav.pb(belong[x]);nod.pb(belong[x]);
			}
			for(int i=1;i<=M;++i){
				int u=rotate(read()),v=rotate(read());
				int x=belong[u],y=belong[v];
				if(x!=y) edg.ep(x,y);nod.pb(x);nod.pb(y);
			}
//			printf("finishread\n");
			sort(fav.begin(),fav.end());
			auto it=unique(fav.begin(),fav.end());
			while(it!=fav.end()) fav.erase(it);
//			printf("1\n");
			sort(nod.begin(),nod.end());
			it=unique(nod.begin(),nod.end());
			while(it!=nod.end()) nod.pop_back();
//			printf("2\n");
//			printf("%d ",nod.size());
			sort(nod.begin(),nod.end(),cmp);
//			for(int v:fav) printf("v:%d\n",v);
//			for(PII E:edg) printf("e: %d %d\n",E.fi,E.se);
			build(nod);
//			printf("build?\n");
			for(PII E:edg){
				int u=E.fi,v=E.se;
				if(u!=v) Vec[u].pb(v),Vec[v].pb(u);
			} 
			idx=0;
			for(int v:nod) {
				if(!Dfn[v]){
//					printf("v:%d\n",v);
					tarjan(v,0);
				}
			}
			int t=-1;
			bool f=0;
			for(int v:fav){
				if(t==-1) t=Belong[v];
				else if(Belong[v]!=t){
					f=1;break ;
				}
			}
			if(f) printf("NO\n");else printf("YES\n");
			if(!f) (R+=i)%=n;
		}
	}
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i,0);
//	printf("cnt:%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		for(int j:stcc[i]){
			for(int v:vec[j]){
				if(belong[v]!=belong[j]){
					if(!Map.count(mp(belong[v],belong[j]))){
						nvec[belong[j]].pb(belong[v]);
						nvec[belong[v]].pb(belong[j]);
						Map[mp(belong[v],belong[j])]=Map[mp(belong[j],belong[v])]=1;
					}
				}
			}
		}
	}
	memset(dfn,0,sizeof(dfn));
	idx=0;
	for(int i=1;i<=cnt;++i){
		vec[i]=move(nvec[i]);
	}
	xu::solve();
}