#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
int col[210];
int dis[210];
int cnt[210];
bool inq[210];
vector<PII>vec[210];
void fail(){
	printf("No\n");exit(0);
}
void bfs(){
	memset(col,-1,sizeof(col));
	queue<int>Q;
	Q.push(1);
	col[1]=0;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(auto i:vec[u]){
			int v=i.fi;
			if(col[v]==-1){
				col[v]=col[u]^1;Q.push(v);
			}
			else if(col[v]!=(col[u]^1)) fail();
		}
	}
}
void spfa(int s){
	memset(cnt,0,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
	queue<int>Q;
	Q.push(s);dis[s]=0;
	cnt[s]=1;
	inq[s]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();inq[u]=0;
		for(auto i:vec[u]){
			int v=i.fi;
			int d=dis[u]+i.se;
			if(dis[v]>d){
				dis[v]=d;++cnt[v];
				if(cnt[v]>=n) fail();
				if(!inq[v]){
					Q.push(v);inq[v]=1;
				}
			}
		}
	}
}
int f[210][210];
int main(){
	n=read(),m=read();
	memset(f,0x15,sizeof(f));
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),b=read();
		if(b) vec[u].ep(v,-1),f[u][v]=-1;
		else vec[u].ep(v,1),f[u][v]=1;
		vec[v].ep(u,1),f[v][u]=1;
	}
	bfs();
	spfa(1);
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j||i==k||j==k) continue ;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int mxn=0;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i==j) continue ;else mxn=max(mxn,abs(f[i][j]));
	printf("YES\n");
	printf("%d\n",mxn);bool flag=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(f[i][j]==mxn){flag=1;
				spfa(i);break ;
			}
		}if(flag) break ;
	}
	for(int i=1;i<=n;++i) printf("%d ",-dis[i]+1000);
	return 0;
}