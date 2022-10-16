#include <cstdio>
#include <cstring>
const int Maxn=500;
int n,m;
int a[Maxn+5][Maxn+5];
int g[Maxn+5][Maxn+5];
bool vis[Maxn+5];
int match[Maxn+5];
char s[Maxn+5][Maxn+5];
bool match_dfs(int u){
	for(int i=1;i<m;i++){
		if(!vis[i]&&g[u][i]){
			vis[i]=1;
			if(match[i]==0||match_dfs(match[i])){
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			a[i][j]=(s[i][j]=='B');
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]^=a[i+1][j]^a[i][j+1]^a[i+1][j+1];
			ans+=a[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			g[i][j]=a[i][j]&a[i][m]&a[n][j];
		}
	}
	int sum=0;
	for(int i=1;i<n;i++){
		memset(vis,0,sizeof vis);
		sum+=match_dfs(i);
	}
	if(sum&1){
		if(a[n][m]){
			ans--;
		}
		else{
			ans++;
		}
	}
	printf("%d\n",ans-sum);
	return 0;
}