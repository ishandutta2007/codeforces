#include <cstdio>
#include <vector>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int p[Maxn+5];
ll s[Maxn+5];
vector<int> e[Maxn+5];
int n;
ll a[Maxn+5];
void dfs(int root,int fa,ll sum){
	if(s[root]==-1){
		a[root]=-1;
		s[root]=sum;
	}
	else{
		if(s[root]<sum){
			puts("-1");
			exit(0);
		}
		a[root]=s[root]-sum;
		sum=s[root];
	}
	for(int i=0;i<(int)e[root].size();i++){
		if(fa==e[root][i]){
			continue;
		}
		dfs(e[root][i],root,sum);
	}
}
struct Node{
	int p;
	ll a;
	int id;
	friend bool operator <(Node p,Node q){
		return p.a<q.a;
	}
}node[Maxn+5];
int ys[Maxn+5];
int find(int root){
	if(node[root].id==1){
		return root;
	}
	if(node[ys[node[root].p]].a!=-1){
		return root;
	}
	return find(ys[node[root].p]);
}
void update(int root,ll x){
	if(node[root].a!=-1){
		node[root].a-=x;
		return;
	}
	for(int i=0;i<(int)e[node[root].id].size();i++){
		if(e[node[root].id][i]==node[root].p){
			continue;
		}
		update(ys[e[node[root].id][i]],x);
	}
}
void update_2(int root,int root_2){
	if(root==root_2){
		return;
	}
	if(node[root].a==-1){
		node[root].a=0;
	}
	update_2(ys[node[root].p],root_2);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&p[i]);
		e[p[i]].push_back(i);
	}
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		s[i]=x;
	}
	memset(a,-1,sizeof a);
	dfs(1,0,0);
	for(int i=1;i<=n;i++){
		node[i].a=a[i];
		node[i].id=i;
		node[i].p=p[i];
	}
	sort(node+1,node+1+n);
	for(int i=1;i<=n;i++){
		ys[node[i].id]=i;
	}
	ll now;
	for(int i=1;i<=n;i++){
		if(node[i].a==-1){
			continue;
		}
		x=find(i);
		now=node[i].a;
		update(x,now);
		node[x].a=now;
		update_2(i,x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(node[i].a==-1){
			continue;
		}
		ans+=node[i].a;
	}
	cout<<ans<<endl;
	return 0;
}