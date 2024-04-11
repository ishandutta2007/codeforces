#include <bits/stdc++.h>
using namespace std;
const int N=300000+10;
int n,par[N],sz[N],a[N],vis[N];
set<int> st;
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x), y=find(y);
	if(x!=y){
		par[y]=x;
		sz[x]+=sz[y];
	}
}
int main(){
	for(int i=0;i<N;i++)par[i]=i,sz[i]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("1 ");
	vis[n+1]=1; st.insert(n+1);
	for(int i=1;i<=n;i++){
		st.insert(a[i]);
		vis[a[i]]=1;
		if(vis[a[i]+1]) unite(a[i],a[i]+1);
		if(vis[a[i]-1]) unite(a[i],a[i]-1); 
		printf("%d ", i-sz[find(n+1)]+2);
	}
}