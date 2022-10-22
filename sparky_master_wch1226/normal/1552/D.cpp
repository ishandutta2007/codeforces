#include<cstdio>
int n,t,a[15];
bool dfs(int k,int sum,int c){return k>=n?(c>0&&sum==0):dfs(k+1,sum,c)||dfs(k+1,sum+a[k],c+1)||dfs(k+1,sum-a[k],c+1);}
int main(){
	scanf("%d",&t);
	while(t--){scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",a+i);printf(dfs(0,0,0)?"YES\n":"NO\n");}
}