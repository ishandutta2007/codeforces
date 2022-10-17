#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Maxn 250000
vector<int> edge[Maxn+5];
int fa[Maxn+5];
vector<int> lea;
bool visit[Maxn+5];
int deep[Maxn+5];
void print(int begin,int end){
	while(begin!=end){
		printf("%d ",begin);
		begin=fa[begin];
	}
	printf("%d\n",begin);
}
int n,m,k;
void dfs(int root,int d){
	deep[root]=d;
	if(d*k>=n){
		puts("PATH");
		printf("%d\n",d);
		print(root,1);
		exit(0);
	}
	bool cnt=0;
	for(int i=0;i<(int)edge[root].size();i++){
		if(!visit[edge[root][i]]){
			visit[edge[root][i]]=1;
			fa[edge[root][i]]=root;
			dfs(edge[root][i],d+1);
			cnt=1;
		}
	}
	if(!cnt){
		lea.push_back(root);
	}
}
vector<int> e;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	visit[1]=1;
	fa[1]=1;
	dfs(1,1);
	puts("CYCLES");
	for(int i=0;i<k;i++){
		e.clear();
		for(int j=0;j<(int)edge[lea[i]].size();j++){
			if(edge[lea[i]][j]==fa[lea[i]]){
				continue;
			}
			if((deep[lea[i]]-deep[edge[lea[i]][j]]+1)%3!=0){
				printf("%d\n",deep[lea[i]]-deep[edge[lea[i]][j]]+1);
				print(lea[i],edge[lea[i]][j]);
				break;
			}
			e.push_back(edge[lea[i]][j]);
		}
		if((int)e.size()==2){
			if(deep[e[0]]<deep[e[1]]){
				swap(e[0],e[1]);
			}
			printf("%d\n",deep[e[0]]-deep[e[1]]+2);
			printf("%d ",lea[i]);
			print(e[0],e[1]);
		}
	}
	return 0;
}