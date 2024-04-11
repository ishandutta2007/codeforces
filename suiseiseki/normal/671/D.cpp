#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=300000;
int n,m;
int root[Maxn+5];
int d[Maxn+5],tot;
ll f[Maxn+5],ans;
vector<int> edge[Maxn+5];
vector<pair<int,int> > p[Maxn+5];
struct Node{
	pair<ll,int> x;
	ll z;
	int l,r,f,d;
}t[Maxn+5];
void add(int x,ll k){
	if(x){
		t[x].x.first+=k;
		t[x].z+=k;
	}
}
void spd(int x){
	if(t[x].z){
		add(t[x].l,t[x].z);
		add(t[x].r,t[x].z);
		t[x].z=0;
	}
}
int merge(int x,int y){
	if(x==0||y==0){
		return x|y;
	}
	if(t[x].x>t[y].x){
		swap(x,y);
	}
	spd(x);
	t[t[x].r=merge(t[x].r,y)].f=x;
	if(t[t[x].r].d>t[t[x].l].d){
		swap(t[x].l,t[x].r);
	}
	t[x].d=t[t[x].r].d+1;
	return x;
}
void dfs(int x,int fa){
	d[x]=d[fa]+1;
	for(pair<int,int> v:p[x]){
		t[++tot].x=v;
		t[tot].d=1;
		root[x]=merge(root[x],tot);
	}
	ll s=0;
	for(int y:edge[x]){
		if(y!=fa){
			dfs(y,x);
			s+=f[y];
			add(root[y],-f[y]);
			root[x]=merge(root[x],root[y]);
		}
	}
	add(root[x],s);
	while(root[x]&&d[t[root[x]].x.second]>=d[x]){
		spd(root[x]);
		root[x]=merge(t[root[x]].l,t[root[x]].r);
	}
	if(root[x]==0){
		puts("-1");
		exit(0);
	}
	f[x]=t[root[x]].x.first;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		p[x].push_back(make_pair(z,y));
	}
	d[1]=1;
	for(int x:edge[1]){
		dfs(x,1);
		ans+=f[x];
	}
	printf("%lld\n",ans);
	return 0;
}