#include <cstdio>
#include <cstring>
#define Maxn 50
int f[Maxn+5][Maxn+5][Maxn+5][Maxn+5];
int n;
char mp[Maxn+5][Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int dfs(int x_1,int y_1,int x_2,int y_2){
	if(f[x_1][y_1][x_2][y_2]!=-1){
		return f[x_1][y_1][x_2][y_2];
	}
	if(x_1==x_2&&y_1==y_2){
		if(mp[x_1][y_1]=='.'){
			return f[x_1][y_1][x_2][y_2]=0;
		}
		return f[x_1][y_1][x_2][y_2]=1;
	}
	int &ans=f[x_1][y_1][x_2][y_2];
	ans=mx(x_2-x_1+1,y_2-y_1+1);
	for(int i=x_1;i<x_2;i++){
		ans=mn(ans,dfs(x_1,y_1,i,y_2)+dfs(i+1,y_1,x_2,y_2));
	}
	for(int i=y_1;i<y_2;i++){
		ans=mn(ans,dfs(x_1,y_1,x_2,i)+dfs(x_1,i+1,x_2,y_2));
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	memset(f,-1,sizeof f);
	printf("%d\n",dfs(1,1,n,n));
	return 0;
}