#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,leaf[N],dep[N],mn,mx;
vector<int> g[N];
void dfs(int u,int p){

	bool done=0; dep[u]=dep[p]+1;	
	//printf("dfs %d %d\n", u,p);
	if(g[u].size()==1){
		leaf[u]=1; return;
	}
	for(auto v:g[u]){
		if(v==p)continue;
		//printf("%d %d\n", u,v);
		dfs(v,u);
		if(leaf[v]==1){
			if(done==0)mx++,done=1;
		}else{
			mx++;
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int rt;
	for(int i=1;i<=n;i++){
		if(g[i].size()>=2)rt=i;
	}
	//printf("rt=%d\n", rt);
	dfs(rt,rt);
	int f[2]={0};
	for(int i=1;i<=n;i++){
		if(leaf[i]){
			//printf("i=%d, dep=%d\n", i,dep[i]);
			f[dep[i]%2]=1;
		}
	}
	if(f[0]+f[1]==2){
		mn=3;
	}else{
		mn=1;
	}
	printf("%d %d\n", mn,mx);
}