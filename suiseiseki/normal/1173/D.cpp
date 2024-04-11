#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define memF(a,b,n) for(int i=0;i <= n;a[i++]=b);
#define Maxn 200000
#define Mod 998244353
int n;
int num;
int head[Maxn+5];
struct Edge{
	int to,next;
}G[Maxn<<1|5];
void addEdge(int u,int v){
	G[num]=Edge{v,head[u]};
	head[u]=num++;
}
ll fact[Maxn+5];
ll dp[Maxn+5];
vector<int> son[Maxn+5];
void DFS(int u,int f){
	for(int i=head[u];~i;i=G[i].next) {
		int v=G[i].to;
		if(v == f){
			continue;
		}
		son[u].push_back(v);
		DFS(v,u);
	}
	int k=son[u].size()+(u!=1?1:0);
	dp[u]=fact[k];
	for(int i=0;i<son[u].size();i++){
		dp[u]=dp[u]*dp[son[u][i]]%Mod;
	}
}
ll Solve() {
	for(int i=0; i <= n; ++i){
		son[i].clear();
	}
	DFS(1,1);
	return dp[1]*n%Mod;
}
void Init() {
	num=0;
	memF(head,-1,n);
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=(i*fact[i-1])%Mod;
	}
}
int main() {
	scanf("%d",&n);
	Init();
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	cout<<Solve()<<endl;
	return 0;
}