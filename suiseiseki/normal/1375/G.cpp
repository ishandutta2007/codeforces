#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn=200000;
vector<int> g[Maxn+5];
int n,cnt[2];
void dfs(int x,int fa,int col){
	cnt[col]++;
	for(int v:g[x]){
		if(v!=fa){
			dfs(v,x,col^1);
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	printf("%d\n",min(cnt[0],cnt[1])-1);
	return 0;
}