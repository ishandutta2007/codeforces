#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> V[200100];
int L,R,mid;
int a[200101];
int sz[200101];
int hdp[200101];
int fdp[200101][2][2];
int dp[200101];
int fa[200101];
bool flag=false;
void dfs(int x){
	dp[x]=0;
	sz[x]=1;
	fdp[x][0][0]=0,fdp[x][0][1]=-1;
	fdp[x][1][0]=0,fdp[x][1][1]=-1;
	hdp[x]=0;
	for(int i=0;i<int(V[x].size());++i){
		int y=V[x][i];
		if(y!=fa[x]){
			fa[y]=x;
			dfs(y);
			sz[x]+=sz[y];
			if(sz[y]!=dp[y]){
				if(dp[y]>fdp[x][1][0]){
					fdp[x][1][0]=dp[y];
					fdp[x][1][1]=y;
				}
				if(fdp[x][0][0]<fdp[x][1][0]){
					swap(fdp[x][0][0],fdp[x][1][0]);
					swap(fdp[x][0][1],fdp[x][1][1]);
				}
			}
			else hdp[x]+=sz[y];
		}
	}
	if(a[x]>=mid) dp[x]=1+fdp[x][0][0]+hdp[x];
	else dp[x]=0;
	if(dp[x]>=m){
		flag=true;
	}
}
void dfs2(int x){
	if(sz[x]==dp[x]) return;
	if(a[fa[x]]>=mid){
		int gg=hdp[fa[x]]+1+fdp[fa[x]][fdp[fa[x]][0][1]==x][0];
		if(gg==n-sz[x]){
			hdp[x]+=gg;
		}
		else{
			if(gg>fdp[x][1][0]){
				fdp[x][1][0]=gg;
				fdp[x][1][1]=fa[x];
			}
			if(fdp[x][0][0]<fdp[x][1][0]){
				swap(fdp[x][0][0],fdp[x][1][0]);
				swap(fdp[x][0][1],fdp[x][1][1]);
			}
		}
	}
	if(a[x]>=mid){
		if(1+fdp[x][0][0]+hdp[x]>=m){
			flag=true;
		}
	}
	for(int i=0;i<int(V[x].size());++i){
		int y=V[x][i];
		if(y!=fa[x]){
			dfs2(y);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		V[x].push_back(y);
		V[y].push_back(x);
	}
	L=1,R=1001000;
	while(L+1!=R){
		flag=false;
		mid=(L+R)>>1;
		dfs(1);
		dfs2(1);
		if(flag) L=mid;
		else R=mid;
	}
	printf("%d\n",L);
	return 0;
}