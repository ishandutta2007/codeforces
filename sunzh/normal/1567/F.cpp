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
char str[510][510];
int getid(int x,int y){
	return (x-1)*m+y;
}
vector<int>vec[250010];
bool vis[250010];
int col[250010];
int ans[510][510];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
void dfs(int x,int c){
	vis[x]=1;col[x]=c;
	for(int v:vec[x]){
		if(!vis[v]) dfs(v,c^1);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) scanf("%s",str[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(str[i][j]=='X'){
				vector<int>v;
				for(int k=0;k<4;++k){
					int vx=i+dx[k],vy=j+dy[k];
					if(str[vx][vy]!='X') v.pb(getid(vx,vy));
				}
				if(v.size()&1){
					printf("NO\n");return 0;
				}
				if(!v.size()) continue ;
				for(int k=0;k<v.size()-1;++k){
					vec[v[k]].pb(v[k+1]);vec[v[k+1]].pb(v[k]);
				}
				vec[v.back()].pb(v.front());vec[v.front()].pb(v.back());
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(str[i][j]!='X'&&!vis[getid(i,j)]){
				dfs(getid(i,j),0);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(str[i][j]!='X'){
				ans[i][j]=(col[getid(i,j)]?4:1);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(str[i][j]=='X'){
				for(int k=0;k<4;++k){
					int vx=i+dx[k],vy=j+dy[k];
					if(str[vx][vy]!='X') ans[i][j]+=ans[vx][vy];
				}
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) printf("%d ",ans[i][j]);
		printf("\n");
	}
}