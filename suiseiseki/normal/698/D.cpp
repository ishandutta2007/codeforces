#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=1000;
const int Maxk=7;
struct Node{
	int x,y;
	friend bool operator ==(Node a,Node b){
		return a.x==b.x&&a.y==b.y;
	}
}a[Maxk+5],b[Maxn+5];
int K,n,q[Maxk+5];
std::vector<int> g[Maxk+5][Maxn+5],qu;
bool vis[Maxn+5];
bool check(Node a,Node b,Node c){
	if(b==c){
		return 0;
	}
	if(c.x<std::min(a.x,b.x)||c.x>std::max(a.x,b.x)){
		return 0;
	}
	if(c.y<std::min(a.y,b.y)||c.y>std::max(a.y,b.y)){
		return 0;
	}
	return 1ll*(b.y-a.y)*(c.x-a.x)==1ll*(c.y-a.y)*(b.x-a.x);
}
int t;
bool work_dfs(int u){
	if(t>K){
		return 0;
	}
	int tmp=q[t];
	for(int i=0;i<(int)g[tmp][u].size();i++){
		int v=g[tmp][u][i];
		if(!vis[v]){
			t++;
			if(!work_dfs(v)){
				return 0;
			}
		}
	}
	qu.push_back(u);
	vis[u]=1;
	return 1;
}
int main(){
	scanf("%d%d",&K,&n);
	for(int i=1;i<=K;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	for(int i=1;i<=K;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(check(a[i],b[j],b[k])){
					g[i][j].push_back(k);
					if((int)g[i][j].size()==K){
						break;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=K;j++){
			q[j]=j;
		}
		do{
			while(!qu.empty()){
				vis[qu.back()]=0;
				qu.pop_back();
			}
			t=1;
			if(work_dfs(i)){
				ans++;
				break;
			}
		}while(std::next_permutation(q+1,q+1+K));
	}
	printf("%d\n",ans);
	return 0;
}