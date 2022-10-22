#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int n,k,u,v,id[MN],dep[MN],siz[MN];
vector<int>edge[MN];
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i)
		if(edge[x][i]!=fa){
			dep[edge[x][i]]=dep[x]+1;
			dfs(edge[x][i],x);
			siz[x]+=siz[edge[x][i]];
		}
//	cerr<<x<<": "<<siz[x]<<" "<<dep[x]<<endl;
}
bool cmp(int a,int b){
	return dep[a]-siz[a]<dep[b]-siz[b];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)id[i]=i;
	sort(id+1,id+1+n,cmp);
	long long sum=0;
	for(int i=n;i>n-k;--i){
		sum+=dep[id[i]]-siz[id[i]]+1;
	//	cerr<<"? "<<id[i]<<endl;
	}
	printf("%lld",sum);
}