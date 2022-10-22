#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 200005
int n,m,x[MN],y[MN];
int dep[MN],fa[MN];
vector<int>edge[MN],ans;
pii tag[MN];
void dfs(int x){
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(dep[v])continue;
		fa[v]=x;dep[v]=dep[x]+1;
		dfs(v);
	}
}
void out(){
	printf("%d ",(int)ans.size());
	for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	puts("");ans.clear();
}
void get(int x,int y){
	vector<int>a;a.clear();
	int op=0;
	if(dep[x]<dep[y])swap(x,y),op=1;
	while(x!=y){
		a.push_back(x);x=fa[x];
	}
	a.push_back(x);
	if(op)reverse(a.begin(),a.end());
	for(int i=0;i<a.size();++i)ans.push_back(a[i]);
}
void solve(int x,int a,int b){
	puts("YES");
	int c=tag[x].x,d=tag[x].y;
	if(dep[b]<dep[d])swap(b,d),swap(a,c);
	get(x,b);out();
	get(x,a);ans.push_back(b);out();
	get(x,c);get(d,b);out();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x[i],&y[i]);
		edge[x[i]].push_back(y[i]);
		edge[y[i]].push_back(x[i]);
	}
	for(int i=1;i<=n;++i)
		if(!dep[i]){
			dep[i]=1;
			dfs(i);
		}
	for(int i=1;i<=m;++i){
		if(dep[x[i]]<dep[y[i]])swap(x[i],y[i]);
		int u=x[i],v=y[i];
		if(fa[u]!=v){
			while(u!=v){
				if(tag[u].x){solve(u,x[i],y[i]);return 0;}
				tag[u]=mp(x[i],y[i]);
				u=fa[u];
			}
		}
	}
	puts("NO");
	return 0;
}