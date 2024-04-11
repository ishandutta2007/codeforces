#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=200000;
const int Maxk=9;
vector<pair<int,int> > edge[Maxn+5];
int n,m,k;
set<pair<int,int> > lis[Maxn+5];
bool np[Maxk+5][Maxk+5][Maxk+5][Maxk+5];
int a[Maxk+5];
int ans;
bool check(){
	for(int i=1;i<=k;i++){
		for(int j=i;j<=k;j++){
			if(np[i][a[i]][j][a[j]]){
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int x){
	if(x==k+1){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=x;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(make_pair(w,v));
	}
	for(int i=1;i<=n;i++){
		sort(edge[i].begin(),edge[i].end());
		for(int j=0;j<(int)edge[i].size();j++){
			if(lis[edge[i][j].second].count(make_pair(edge[i].size(),j+1))>0){
				np[edge[i].size()][j+1][edge[i].size()][j+1]=1;
			}
			else{
				lis[edge[i][j].second].insert(make_pair(edge[i].size(),j+1));
			}
		}
	}
	for(int i=1;i<=n;i++){
		set<pair<int,int> >::iterator it_1,it_2;
		it_1=lis[i].begin();
		while(it_1!=lis[i].end()){
			it_2=it_1;
			it_2++;
			while(it_2!=lis[i].end()){
				np[it_1->first][it_1->second][it_2->first][it_2->second]=1;
				np[it_2->first][it_2->second][it_1->first][it_1->second]=1;
				it_2++;
			}
			it_1++;
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}