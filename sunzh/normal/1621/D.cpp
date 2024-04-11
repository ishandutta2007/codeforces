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
int T;
int n;
int c[510][510];
struct node{
	PII pos;long long dis;
	bool operator <(const node &x)const{
		return dis>x.dis;
	}
};
bool vis[510][510];
long long dis[510][510];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=2*n;++i){
			for(int j=1;j<=2*n;++j){
				c[i][j]=read();dis[i][j]=1e18;vis[i][j]=0;
			}
		}
		long long ans=0;
		for(int i=n+1;i<=2*n;++i){
			for(int j=n+1;j<=2*n;++j){
				ans+=c[i][j];c[i][j]=1e18;
			}
		}
		c[n+1][n+1]=c[2*n][n+1]=c[2*n][2*n]=c[n+1][2*n]=0;
		dis[n+1][n+1]=dis[2*n][n+1]=dis[2*n][2*n]=dis[n+1][2*n]=0;
		node s;s.pos=mp(2*n,2*n);s.dis=0;
		priority_queue<node>Q;Q.push(s);
		s.pos=mp(n+1,n+1);Q.push(s);
		s.pos=mp(n+1,2*n);Q.push(s);
		s.pos=mp(2*n,n+1);Q.push(s);
		while(!Q.empty()){
			node nw=Q.top();Q.pop();
			if(vis[nw.pos.fi][nw.pos.se]) continue ;
			vis[nw.pos.fi][nw.pos.se]=1;
			for(int i=0;i<4;++i){
				PII v=mp(nw.pos.fi+dx[i],nw.pos.se+dy[i]);
				if(v.fi==0) v.fi=2*n;if(v.fi==2*n+1) v.fi=1;
				if(v.se==0) v.se=2*n;if(v.se==2*n+1) v.se=1;
				if(dis[v.fi][v.se]>nw.dis+c[v.fi][v.se]){
					dis[v.fi][v.se]=nw.dis+c[v.fi][v.se];
					node t;t.pos=v;t.dis=dis[v.fi][v.se];
					Q.push(t);
				}
			}
		}
		printf("%lld\n",dis[1][1]+ans);
	}
}