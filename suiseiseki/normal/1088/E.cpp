#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
ll maxn[Maxn+5];
int a[Maxn+5];
vector<int> gra[Maxn+5];
ll mx(ll a,ll b){
	return a>b?a:b;
}
ll ans=(-1ll<<62),num;
void dfs_1(int root,int fa){
	maxn[root]=a[root];
	int v;
	for(int i=0;i<(int)gra[root].size();i++){
		v=gra[root][i];
		if(v==fa){
			continue;
		}
		dfs_1(v,root);
		maxn[root]=mx(maxn[root],maxn[v]+maxn[root]);
	}
	ans=mx(ans,maxn[root]);
}
void dfs_2(int root,int fa){
	maxn[root]=a[root];
	int v;
	for(int i=0;i<(int)gra[root].size();i++){
		v=gra[root][i];
		if(v==fa){
			continue;
		}
		dfs_2(v,root);
		maxn[root]=mx(maxn[root],maxn[v]+maxn[root]);
	}
	if(maxn[root]==ans){
		num++;
		maxn[root]=0;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		gra[u].push_back(v);
		gra[v].push_back(u);
	}
	dfs_1(1,0);
	dfs_2(1,0);
	cout<<ans*num<<' '<<num<<endl;
	return 0;
}