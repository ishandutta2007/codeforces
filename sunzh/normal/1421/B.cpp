#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
char g[210][210];
int G[210][210];
bool vis[210][210];
bool f[2][2];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool bfs(int x){
	memset(vis,0,sizeof(vis));
	queue<PII>Q;
	Q.push(mp(1,1));vis[1][1]=1;
	while(!Q.empty()){
		PII u=Q.front();Q.pop();
		for(int i=0;i<4;++i){
			int vx=u.fi+dx[i];
			int vy=u.se+dy[i];
			if(vx==n&&vy==n) return 1;
			if(vx<1||vy<1||vx>n||vy>n) continue ;
			if(vis[vx][vy]) continue ;
			if(vx==n&&vy==n-1) f[x][0]=1;
			else if(vx==n-1&&vy==n) f[x][1]=1;
			if(G[vx][vy]!=x) continue ;
			vis[vx][vy]=1;Q.push(mp(vx,vy));
		}
	}
	return 0;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) scanf("%s",g[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j) G[i][j]=g[i][j]-'0';
		bool f=0;
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j){
				for(int k=0;k<=1;++k){
					for(int l=0;l<=1;++l){
						if(i+j+k+l<=2){
							if(i) G[1][2]^=1;
							if(j) G[2][1]^=1;
							if(k) G[n-1][n]^=1;
							if(l) G[n][n-1]^=1;
							if(bfs(0)==0&&bfs(1)==0){
								f=1;
								printf("%d\n",i+j+k+l);
								if(i) printf("1 2\n");
								if(j) printf("2 1\n");
								if(k) printf("%d %d\n",n-1,n);
								if(l) printf("%d %d\n",n,n-1);
							}
							if(i) G[1][2]^=1;
							if(j) G[2][1]^=1;
							if(k) G[n-1][n]^=1;
							if(l) G[n][n-1]^=1;
						}
						if(f) break ;
					}
					if(f) break ;
				}
				if(f)break ;
			}
			if(f)break ;
		}
	}
}