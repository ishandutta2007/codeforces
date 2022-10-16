#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Maxn 100000
int f[Maxn+5],num[Maxn+5];
int now[Maxn+5];
vector<int> db;
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	f[fa_x]=fa_y;
	num[fa_y]+=num[fa_x];
}
int n,m;
vector<int> edge[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		f[i]=i;
		num[i]=1;
	}
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		sort(edge[i].begin(),edge[i].end());
		for(int j=0;j<(int)edge[i].size()&&edge[i][j]<i;j++){
			now[find(edge[i][j])]++;
		}
		for(int j=0;j<(int)db.size();j++){
			if(now[find(db[j])]<num[find(db[j])]){
				merge(i,db[j]);
			}
		}
		if(find(i)==i){
			db.push_back(i);
		}
		for(int j=0;j<(int)edge[i].size()&&edge[i][j]<i;j++){
			now[find(edge[i][j])]=0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			ans++;
		}
	}
	printf("%d\n",ans-1);
	return 0;
}