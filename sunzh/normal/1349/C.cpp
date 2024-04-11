#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define mp make_pair
#define fi first
#define se second
#define PII pair<int,int>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline long long llread(){
	long long x=0;int f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1ll)+(x<<3ll)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m,T;
int d[1010][1010];
char g[1010][1010];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
PII q[2000010];
int head=1,tail;
bool vis[1010][1010];
signed main(){
	memset(d,-1,sizeof(d));
	n=read(),m=read(),T=read();
	for(int i=1;i<=n;++i) scanf("%s",g[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=0;k<4;++k){
				int vx=i+dx[k],vy=j+dy[k];
				if(vx<1||vx>n||vy<1||vy>m) continue ;
				if(g[vx][vy]==g[i][j]){
					d[i][j]=0;vis[i][j]=1;q[++tail]=mp(i,j);break ;
				}
			}
		}
	}
	while(head<=tail){
		PII u=q[head];++head;
		for(int i=0;i<4;++i){
			int vx=u.fi+dx[i];int vy=u.se+dy[i];
			if(vx<1||vx>n||vy<1||vy>m) continue ;
			if(vis[vx][vy]) continue ;
			vis[vx][vy]=1;d[vx][vy]=d[u.fi][u.se]+1;q[++tail]=mp(vx,vy);
		}
	}
	while(T--){
		int x=read(),y=read();
		long long p=llread();
		if(d[x][y]==-1) print(g[x][y]-'0');
		else print((g[x][y]-'0')^(max(0ll,p-d[x][y])&1ll));putchar('\n');
	}
}