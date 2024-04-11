#include <cstdio>
int n,m;
int a[1<<22|5];
bool vis[1<<22|5];
int fa[1<<22|5];
bool has[1<<22|5];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
void dfs(int root){
	if(vis[root]){
		return;
	}
	vis[root]=1;
	if(has[root]){
		dfs(root^((1<<n)-1));
	}
	for(int i=0;i<n;i++){
		if(root&(1<<i)){
			dfs(root^(1<<i));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<(1<<n);i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		has[a[i]]=1;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(!vis[a[i]]){
			vis[a[i]]=1;
			ans++;
			dfs(a[i]^((1<<n)-1));
		}
	}
	printf("%d\n",ans);
	return 0;
}