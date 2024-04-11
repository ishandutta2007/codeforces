#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
inline int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int len[MN],dep[MN],DEP[MN],w[MN],fa[MN],ans[MN];
int n,m,st[MN];
char ch[MN];
vector<int>edge[MN];
void dfs(int x){
	DEP[x]=dep[x];
	for(int i=0;i<edge[x].size();++i)
	if(fa[x]!=edge[x][i]){
		fa[edge[x][i]]=x;
		dep[edge[x][i]]=dep[x]+1;
		dfs(edge[x][i]);
		DEP[x]=max(DEP[x],DEP[edge[x][i]]);
		if(DEP[w[x]]<DEP[edge[x][i]])w[x]=edge[x][i];
	}
	len[x]=len[w[x]]+1;
}
int TMP[MN],*f[MN],*p=TMP;
void work(int x){
//	cerr<<"? "<<x<<" "<<len[x]<<" "<<f[x][0]<<endl;
	if(w[x]){f[w[x]]=f[x]+1;work(w[x]);ans[x]=ans[w[x]]+1;}
	for(int i=0;i<edge[x].size();++i){
		if(edge[x][i]==fa[x]||edge[x][i]==w[x])continue;
		int v=edge[x][i];
		f[v]=p;p+=len[v];work(v);
//		cerr<<"? "<<x<<" "<<v<<endl;
		for(int j=1;j<=len[v];++j){
			f[x][j]+=f[v][j-1];
			if(f[x][ans[x]]<f[x][j]||(f[x][ans[x]]==f[x][j]&&ans[x]>j)) ans[x]=j;
		}
	}
//	cerr<<"OK"<<x<<" "<<len[x]<<" "<<ans[x]<<" "<<p<<endl;
	f[x][0]=1;
//	cerr<<"OK"<<x<<" "<<len[x]<<" "<<ans[x]<<endl;
	if(f[x][ans[x]]<=1) ans[x]=0;

}
vector<int>F1,F2;
int main(){
	n=read();
	for(int i=2;i<=n;++i){
		int x=read(),y=read();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dep[1]=1;
	dfs(1);
	f[1]=p;p+=len[1];
	work(1);
//	return 0;
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}