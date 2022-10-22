#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 100005
int n,q,rt;
vector<pii >edge[MN];
int val[MN];
bool cmp(int a,int b){
	return val[a]>val[b];
}
struct tree{
	int fa[MN],dep[MN],w[MN],D[MN],top[MN];
	int ret[MN],ti[MN];
	int anc[19][MN];
	vector<int>lef;
	void dfs(int x,int f,int d){
		fa[x]=f;dep[x]=d;w[x]=D[x]=0;
//		cerr<<"Dfs: "<<x<<" "<<f<<" "<<dep[x]<<endl;
		for(int i=0;i<edge[x].size();++i){
			int v=edge[x][i].x,z=edge[x][i].y;
			if(v==f)continue;
			dfs(v,x,d+z);
			if(D[x]<D[v]+z)w[x]=v,D[x]=D[v]+z;
		}
		if(dep[rt]<dep[x])rt=x;
	}
	void DFS(int x,int t){
		top[x]=t;
		if(w[x])DFS(w[x],t);
		else lef.push_back(x);
		for(int i=0;i<edge[x].size();++i){
			int v=edge[x][i].x,z=edge[x][i].y;
			if(fa[x]==v||w[x]==v)continue;
			DFS(v,v);
		}
	}
	void init(){
		for(int i=1;i<=n;++i){
			val[i]=dep[i]-dep[fa[top[i]]];
//			if(!val[i])cerr<<"rt: "<<i<<endl;
		}
		sort(lef.begin(),lef.end(),cmp);
		for(int i=0;i<lef.size();++i){
			int x=lef[i];
			ret[i+1]=ret[i]+dep[x]-dep[fa[top[x]]];
//			cerr<<" init "<<i+1<<": "<<x<<" "<<dep[x]-dep[fa[top[x]]]<<endl;
			while(x!=top[x]){
				assert(!ti[x]);
				ti[x]=i+1;
				x=fa[x];
			}
			assert(!ti[x]);
			ti[x]=i+1;
		}
		for(int i=1;i<=n;++i)anc[0][i]=fa[i];
		for(int i=1;i<=17;++i)
			for(int j=1;j<=n;++j)
				anc[i][j]=anc[i-1][anc[i-1][j]];
	}
	int qry(int x,int y){
		int t=2*y-1,ans=0;
//		cerr<<"WUHU"<<endl;
		if(ti[x]<=t)return ret[t];
//		cerr<<"fly"<<endl;
		int tmp=x;
		for(int i=17;i>=0;--i)
			if(anc[i][x]&&ti[anc[i][x]]>t)x=anc[i][x];
		ans=ret[t]-D[fa[x]]+(D[tmp]+dep[tmp]-dep[fa[x]]);//
		x=tmp;
		for(int i=17;i>=0;--i)
			if(anc[i][x]&&ti[anc[i][x]]>t-1)x=anc[i][x];
		ans=max(ans,ret[t-1]+D[tmp]+dep[tmp]-dep[fa[x]]);//
		return ans;
	}
}T[2];
int main(){
	n=read();q=read();
	int all=0;
	for(int i=1;i<n;++i){
		int x=read(),y=read(),z=read();
		edge[x].push_back(mp(y,z));
		edge[y].push_back(mp(x,z));
		all+=z;
	}
	T[0].dfs(1,0,0);
	int A=rt,B;
//	cerr<<"--"<<endl;
	T[0].dfs(A,0,0);B=rt;
//	cerr<<"--"<<endl;
	T[1].dfs(B,0,0);

	T[0].DFS(A,A);T[1].DFS(B,B);
	T[0].init();T[1].init();
//	cerr<<"done: "<<A<<" "<<B<<endl;
	int ans=0;
	for(int i=1;i<=q;++i){
		int x=(read()+ans-1)%n+1,y=(read()+ans-1)%n+1;
//		cerr<<"ask: "<<x<<" "<<y<<endl;
		if(T[0].lef.size()<=2*y-1)printf("%d\n",ans=all);
		else{
			printf("%d\n",ans=max(T[0].qry(x,y),T[1].qry(x,y)));
		}
	}
	return 0;
}