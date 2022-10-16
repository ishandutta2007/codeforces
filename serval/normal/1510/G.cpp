#include<bits/stdc++.h>
using namespace std;
#define N 110
vector<int>G[N];
int n,K,dep[N],Mxdep,rec,fa[N],A[N],Tid[N],id[N],dfs_cnt,B[N];
void dfs(int x,int d){
	Tid[x]=++dfs_cnt;
	id[dfs_cnt]=x;
	dep[x]=d;
	if (d>Mxdep){
		Mxdep=d;
		rec=x;
	}
	int i;
	for (i=0;i<(int)G[x].size();i++){
		int to=G[x][i];
		dfs(to,d+1);
	}
}
void dfs1(int x){
	printf("%d ",x);
	int i,r=-1;
	for (i=0;i<(int)G[x].size();i++){
		int to=G[x][i];
		if (B[to]==2){
			dfs1(to);	
			printf("%d ",x);
		}else if (B[to]==1){
			r=to;
		}
	}
	if (r!=-1){
		dfs1(r);
	}
}
int main(){
	int Case,i;
	scanf("%d",&Case);
	while (Case--){
		memset(B,0,sizeof(B));
		rec=1;
		Mxdep=dfs_cnt=0;
		scanf("%d%d",&n,&K);
		for (i=1;i<=n;i++){
			G[i].clear();
		}
		fa[1]=1;
		for (i=2;i<=n;i++){
			int x;
			scanf("%d",&x);
			G[x].push_back(i);
			fa[i]=x;
		}
		dfs(1,0);
//		cerr<<"***"<<Mxdep<<" "<<rec<<endl;
//		return 0;
		if (Mxdep+1>K){
			int x=rec,h=0;
			while (x>1){
				A[++h]=x;
				x=fa[x];
			}
			A[++h]=x;
			printf("%d\n",K-1);
			for (i=h;h-i+1<=K;i--){
				printf("%d ",A[i]);
			}
			printf("\n");
			continue;
		}
		int t=K-(Mxdep+1);
		int x=rec;
		while (x>1){
			B[x]=1;
			x=fa[x];
		}
		B[x]=1;
		
		for (i=1;i<=n && t>0;i++){
			if (B[id[i]]==0){
				B[id[i]]=2;
				t--;
			}
		}
		printf("%d\n",2*(K-1)-Mxdep);
		dfs1(1);
		printf("\n");
	}
	return 0;
}