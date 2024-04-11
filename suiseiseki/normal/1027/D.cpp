#include <cstdio>
int c[200005];
int a[200005];
int father[200005];
bool x[200005];
int find(int x){
	if(x==father[x]){
		return x;
	}
	return father[x]=find(father[x]);
}
int mn(int a,int b){
	return a<b?a:b;
}
int dfs(int x,int y){
	if(x==y){
		return c[x];
	}
	return mn(dfs(a[x],y),c[x]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		father[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(find(a[i])==find(i)){
			x[i]=1;
		}
		else{
			father[find(a[i])]=find(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(x[i]){
			ans+=dfs(a[i],i);
		}
	}
	printf("%d\n",ans);
	return 0;
}