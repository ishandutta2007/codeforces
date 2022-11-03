#include<bits/stdc++.h>
using namespace std;

int f[22],n,m,mn=100,ans[25],a[25],cnt;
inline bool check(){
	for(int i=0;i<n;i++)if(f[i]!=(1<<n)-1)return 0;
	return 1;
}
void dfs(int s,int x){
	int g[22];memcpy(g,f,sizeof(g));
	if(check()&&cnt<mn){
		mn=cnt;
		for(int i=0;i<cnt;i++)ans[i]=a[i];
	}
	for(int i=x;i<n;i++){
		a[cnt++]=i;
		for(int j=0;j<n;j++)if(f[j]>>i&1)f[j]|=f[i];
		dfs(s|1<<i,i+1);
		memcpy(f,g,sizeof(f));
		cnt--;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)f[i]=1<<i;
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d",&x,&y);x--,y--;
		f[x]|=1<<y;
		f[y]|=1<<x;
	}
	dfs(0,0);
	printf("%d\n",mn);
	for(int i=0;i<mn;i++)printf("%d ",ans[i]+1);printf("\n");
	return 0;
}