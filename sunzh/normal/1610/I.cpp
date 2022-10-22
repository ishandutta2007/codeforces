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
int n;
vector<int>vec[300010];
int sg[300010],f[300010];
bool vis[300010];
void dfs(int x,int fa){
	f[x]=fa;
	for(int v:vec[x]) if(v!=fa){
		dfs(v,x);sg[x]^=sg[v]+1;
	}
}
int nwans,e;
void put(){
	printf((nwans^(e&1))?"1":"2");
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs(1,0);
	nwans=sg[1];
	e=0;vis[1]=1;
	put();
	for(int i=2;i<=n;++i){
		int pos=i,ls=0;
		while(!vis[pos]){
			nwans^=sg[pos]+1;
			for(int v:vec[pos]) if(v!=ls&&v!=f[pos]){
				nwans^=sg[v]+1;
			}
			++e;vis[pos]=1;pos=f[pos];
		}
		put();
	}
}