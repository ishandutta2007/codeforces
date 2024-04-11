#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int head[300005],arrive[600005],nxt[600005],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
vector<pair<int,int> > qu[300005];
int father[300005];
long long value[300005];
int dep[300005];
int n,m;
int mn(int a,int b){
	return a<b?a:b;
}
long long f[300005];
void dfs(int root){
	dep[root]=dep[father[root]]+1;
	value[root]=value[father[root]]+f[dep[root]];
	for(int i=0;i<(int)qu[root].size();i++){
		value[root]+=qu[root][i].first;
		f[mn(n+1,dep[root]+qu[root][i].second+1)]-=qu[root][i].first;
	}
	for(int i=head[root];i;i=nxt[i]){
		if(arrive[i]==father[root]){
			continue;
		}
		father[arrive[i]]=root;
		dfs(arrive[i]);
	}
	for(int i=0;i<(int)qu[root].size();i++){
		f[mn(n+1,dep[root]+qu[root][i].second+1)]+=qu[root][i].first;
	}
}
int main(){
	scanf("%d",&n);
	int v,d,x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&v,&d,&x);
		qu[v].push_back(make_pair(x,d));
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<value[i]<<" ";
	}
	puts("");
	return 0;
}