#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int T,n,m,deg[MN],col[MN];
vector<int>edge[MN],fa[MN];
int Q[MN],l,r;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)edge[i].clear(),fa[i].clear();
		for(int i=1;i<=m;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			fa[y].push_back(x);
			deg[y]++;
		}
		l=1,r=0;
		for(int i=1;i<=n;++i)if(!deg[i])Q[++r]=i;
		while(l<=r){
			int x=Q[l++];
			col[x]=1;
			bool flag=0;
			for(int i=0;i<fa[x].size();++i){
				int v=fa[x][i];
				if(col[v]==2){col[x]=3;break;}	
				flag|=(col[v]==1);
			}
			if(flag&&col[x]==1)col[x]=2;
		//	cerr<<x<<": "<<col[x]<<endl;
			for(int i=0;i<edge[x].size();++i){
				int v=edge[x][i];
				deg[v]--;
				if(!deg[v])Q[++r]=v;
			}
		}
		vector<int>ans;
		for(int i=1;i<=n;++i)if(col[i]==3)ans.push_back(i);
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}