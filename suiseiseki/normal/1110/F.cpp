#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 500000
#define ll long long
#define Inf (1ll<<60)
int n,q;
vector<int> edge[Maxn+5];
vector<int> val[Maxn+5];
int maxn[Maxn+5];
ll dep[Maxn+5];
ll t[Maxn<<2|5],tag[Maxn<<2|5];
ll ans[Maxn+5];
template<typename Elem_1,typename Elem_2>
Elem_1 mx(Elem_1 a,Elem_2 b){
	return a>b?a:b;
}
template<typename Elem_1,typename Elem_2>
Elem_1 mn(Elem_1 a,Elem_2 b){
	return a<b?a:b;
}
void dfs(int root){
	maxn[root]=root;
	for(int i=0;i<(int)edge[root].size();i++){
		dep[edge[root][i]]=dep[root]+val[root][i];
		dfs(edge[root][i]);
		maxn[root]=mx(maxn[root],maxn[edge[root][i]]);
	}
}
void put(int root,ll x){
	t[root]+=x;
	tag[root]+=x;
}
void push_down(int root){
	if(tag[root]){
		put(root<<1,tag[root]);
		put(root<<1|1,tag[root]);
		tag[root]=0;
	}
}
ll query(int root,int left,int right,int l,int r){
	if(l<=left&&r>=right){
		return t[root];
	}
	push_down(root);
	int mid=(left+right)>>1;
	if(l<=mid&&r>mid){
		return mn(query(root<<1,left,mid,l,r),query(root<<1|1,mid+1,right,l,r));
	}
	if(l<=mid){
		return query(root<<1,left,mid,l,r);
	}
	if(r>mid){
		return query(root<<1|1,mid+1,right,l,r);
	}
	return Inf;
}
void add(int root,int left,int right,int l,int r,ll x){
	if(l<=left&&r>=right){
		put(root,x);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	if(l<=mid){
		add(root<<1,left,mid,l,r,x);
	}
	if(r>mid){
		add(root<<1|1,mid+1,right,l,r,x);
	}
	t[root]=mn(t[root<<1],t[root<<1|1]);
}
void build(int root,int left,int right){
	tag[root]=0;
	if(left==right){
		if(edge[left].empty()){
			t[root]=dep[left];
		}
		else{
			t[root]=Inf;
		}
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	t[root]=mn(t[root<<1],t[root<<1|1]);
}
vector<int> q_l[Maxn+5],q_r[Maxn+5];
vector<int> id[Maxn+5];
void work(int root){
	for(int i=0;i<(int)id[root].size();i++){
		ans[id[root][i]]=query(1,1,n,q_l[root][i],q_r[root][i]);
	}
	for(int i=0;i<(int)edge[root].size();i++){
		add(1,1,n,1,n,val[root][i]);
		add(1,1,n,edge[root][i],maxn[edge[root][i]],-2ll*val[root][i]);
		work(edge[root][i]);
		add(1,1,n,edge[root][i],maxn[edge[root][i]],2ll*val[root][i]);
		add(1,1,n,1,n,-val[root][i]);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	int u,v,x;
	for(int i=2;i<=n;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(i);
		val[u].push_back(v);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&x,&u,&v);
		q_l[x].push_back(u);
		q_r[x].push_back(v);
		id[x].push_back(i);
	}
	dfs(1);
	build(1,1,n);
	work(1);
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}