#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

#define rpt(i,l,r) for(int i=(l),R=(r);i<=R;++i)

const int max_N=1e5,BASE=600;

int n,q,vis[max_N+21],a[max_N+21];

int block[max_N+21],block_cnt,st[max_N+21],top;

int dfn[max_N+21],dfn_cnt,dep[max_N+21],p[max_N+21][17];

bool sex[max_N+21];

std::vector<int>vec[max_N+21];

std::unordered_map<int,int>cnt[2];

void dfs(int x){
	dfn[x]=++dfn_cnt;
	rpt(i,1,16)p[x][i]=p[p[x][i-1]][i-1];
	int bottom=top;
	for(auto&y:vec[x])if(y!=*p[x]){
		*p[y]=x;
		dep[y]=dep[x]+1;
		dfs(y);
		if(top-bottom>=BASE){
			++block_cnt;
			while(top>bottom)block[st[top--]]=block_cnt;
		}
	}
	st[++top]=x;
}

inline int lca(int x,int y){
	if(dep[x]>dep[y])std::swap(x,y);
	for(int i=0,k=dep[y]-dep[x];k;++i,k>>=1)if(k&1)y=p[y][i];
	if(x==y)return x;
	for(int i=16;~i;--i)if(p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
	return *p[x];	
}

std::pair<int,int>query[max_N+21];

int queue[max_N+21];

inline bool cmp(int x,int y){
	int Bx=block[query[x].first],By=block[query[y].first];
	if(Bx!=By)return Bx<By;
//	return block[query[x].second]<block[query[y].second];
	if(Bx&1)return dfn[query[x].second]<dfn[query[y].second];
	return dfn[query[x].second]>dfn[query[y].second];
}

long long res,ans[max_N+21];

inline void Xor(int x){
	vis[x]*=-1;
	res+=cnt[sex[x]^1][a[x]]*vis[x];
	cnt[sex[x]][a[x]]+=vis[x];
}

inline void Xor(int u,int v){
	if(dep[u]>dep[v])std::swap(u,v);
	while(dep[v]>dep[u])Xor(v),v=*p[v];
	while(u!=v)Xor(u),Xor(v),u=*p[u],v=*p[v];
}

inline void init(){
	int index=queue[1];
	int u=query[index].first,v=query[index].second;
	int w=lca(u,v);
	Xor(u,v);
	Xor(w),ans[index]=res,Xor(w);
}

int main(){
	read(n);
	rpt(i,1,n)vis[i]=-1,read(sex[i]);
	rpt(i,1,n)read(a[i]);
	rpt(i,2,n){
		int u,v;
		read(u),read(v);
		vec[u].push_back(v);
		vec[v].push_back(u);	
	}
	dfs(1);
	while(top)block[st[top--]]=block_cnt;
	read(q);
	rpt(i,1,q){
		read(query[i].first);
		read(query[i].second);
		if(block[query[i].first]>block[query[i].second]){
			std::swap(query[i].first,query[i].second);
		}
		queue[i]=i;
	}
	std::sort(queue+1,queue+1+q,cmp);
	init();
	rpt(i,2,q){
		int index=queue[i];
		int u=query[index].first,v=query[index].second;
		int w=lca(u,v);
		Xor(u,query[queue[i-1]].first);
		Xor(v,query[queue[i-1]].second);
		Xor(w),ans[index]=res,Xor(w);
	}
	rpt(i,1,q)printf("%I64d\n",ans[i]);
	return 0;
}