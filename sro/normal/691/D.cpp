#include <bits/stdc++.h>
using namespace std;

struct bingxg{
	int fa[1000005];
	void init(){
		for(int i=0;i<1000005;i++){
			fa[i]=i;
		}
	}
	int root(int x){
		return fa[x]==x?x:(fa[x]=root(fa[x]));
	}
	void conn(int a,int b){
		a=root(a);
		b=root(b);
		if(a==b){
			return;
		}
		fa[a]=b;
	}
}dsu;

int n,m;
int p[1000005];
vector<int> vs[1000005];
int it[1000005];

int main(){
	scanf("%d%d",&n,&m);
	dsu.init();
	for(int i=1;i<=n;i++){
		scanf("%d",p+i);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		dsu.conn(a,b);
	}
	for(int i=1;i<=n;i++){
		vs[dsu.root(i)].push_back(p[i]);
	}
	for(int i=1;i<=n;i++){
		if(dsu.root(i)==i){
			sort(vs[i].begin(),vs[i].end());
		}
	}
	for(int i=1;i<=n;i++){
		int id=dsu.root(i);
		printf("%d ",vs[id].back());
		vs[id].pop_back();
	}
	return 0;
}