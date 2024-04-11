#include<bits/stdc++.h>
using namespace std;
#define itset set<int>::iterator
#define MN 100005
int n,m,a,b,vis[MN],ans;
vector<int>edge[MN];
set<int>S1,S2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i=0;i<edge[1].size();++i)
		S1.insert(edge[1][i]),vis[edge[1][i]]=1;
	for(int i=2;i<=n;++i)
		if(!vis[i])S2.insert(i);
	for(int i=2;i<=n;++i){
		if(S2.empty()){
			int x=*S1.begin();
			vis[x]=0;
			S2.insert(x);
			S1.erase(x);
			ans++;
		}
		itset it=S2.begin();
		for(int j=0;j<edge[*it].size();++j)
			if(vis[edge[*it][j]])S1.erase(edge[*it][j]);
		for(itset j=S1.begin();j!=S1.end();++j){
			vis[*j]=0;
			S2.insert(*j);
		}
		S1.clear();
		for(int j=0;j<edge[*it].size();++j)
			if(vis[edge[*it][j]]) S1.insert(edge[*it][j]);
		S2.erase(*it);
	}
	printf("%d",ans);
	return 0;	
}