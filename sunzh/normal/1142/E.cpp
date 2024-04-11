#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int in[100010];
vector<int>vec[100010],edg[100010];
bool vis[100010],nw[100010];
void dfs(int x){
	nw[x]=vis[x]=1;
	for(int v:vec[x]) if(!nw[v]){
		++in[v];
		edg[x].pb(v);if(!vis[v]) dfs(v);
	}
	nw[x]=0;
}
int query(int u,int v){
	printf("? %d %d\n",u,v);fflush(stdout);return read();
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();vec[u].pb(v);
	}
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i);
	queue<int>Q;
	for(int i=1;i<=n;++i) if(!in[i]){
		Q.push(i);
	}
	while(Q.size()>1){
		int u=Q.front();Q.pop();int v=Q.front();Q.pop();
		if(query(v,u)) swap(u,v);
		for(int x:edg[v]){
			if(--in[x]==0){
				Q.push(x);
			}
		}
		Q.push(u);
	}
	printf("! %d\n",Q.front());return 0;
}