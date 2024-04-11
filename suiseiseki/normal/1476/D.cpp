#include <cstdio>
#include <cstring>
const int Maxn=300000;
int n;
char s[Maxn+5];
int f[Maxn+5][2][2];
int work_dfs(int u,int d,int x){
	if(f[u][d][x]!=-1){
		return f[u][d][x];
	}
	if(d==0){
		if(u==0){
			return f[u][d][x]=1;
		}
		int ans=1;
		if((s[u]=='L'&&x==0)||(s[u]=='R'&&x==1)){
			ans+=work_dfs(u-1,d,x^1);
		}
		return f[u][d][x]=ans;
	}
	else{
		if(u==n){
			return f[u][d][x]=1;
		}
		int ans=1;
		if((s[u+1]=='R'&&x==0)||(s[u+1]=='L'&&x==1)){
			ans+=work_dfs(u+1,d,x^1);
		}
		return f[u][d][x]=ans;
	}
}
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=0;i<=n;i++){
		f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=-1;
	}
	for(int i=0;i<=n;i++){
		printf("%d ",work_dfs(i,0,0)+work_dfs(i,1,0)-1);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}