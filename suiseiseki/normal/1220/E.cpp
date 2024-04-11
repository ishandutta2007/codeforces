// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define maxn 200001
 
vector<int> adj[maxn];
ll w[maxn],s[maxn];
int mark[maxn],p[maxn],vis[maxn];
 
void dfs(int v){
	vis[v]=1;
	for(int u:adj[v]){
		if(vis[u]){
			if(u!=p[v]){
				mark[v]=1;
			}
		}
		else{
			p[u]=v;
			dfs(u);
			if(mark[u]) mark[v]=1;
			else s[v]=max(s[u],s[v]);
		}
	}
	if(!mark[v]) s[v]+=w[v];
	return;
}
 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		mark[i]=p[i]=s[i]=vis[i]=0;
	}
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin>>u;
	dfs(u);
	ll res=0,maxx=0;
	for(int i=1;i<=n;i++){
		if(mark[i]) res+=w[i];
		maxx=max(s[i],maxx);
	}
	res+=maxx;
	cout<<res<<"\n";
	return 0;
}