#include <cstdio>
#include <cstring>
const int Maxn=100;
const int Mod=1000000007;
int n,x;
int c[Maxn+5],b[Maxn+5];
int f[Maxn+5][Maxn*Maxn+5];
int sum_b[Maxn+5];
int work_dfs(int u,int s){
	if(f[u][s]!=-1){
		return f[u][s];
	}
	if(u>n){
		return 1;
	}
	int ans=0;
	for(int i=0;i<=c[u];i++){
		if(s+i-sum_b[u-1]>=u*x){
			ans=(ans+work_dfs(u+1,s+i))%Mod;
		}
	}
	return f[u][s]=ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d",&b[i]);
		sum_b[i]=sum_b[i-1]+b[i];
	}
	for(int i=1;i<n;i++){
		sum_b[i]+=sum_b[i-1];
	}
	memset(f,-1,sizeof f);
	scanf("%*d");
	scanf("%d",&x);
	printf("%d\n",work_dfs(1,0));
	return 0;
}