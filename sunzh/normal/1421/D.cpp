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
#define int long long
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
int x,y;
int c[20];
int dis[20][20];
int dx[20]={0,1,0,-1,-1,0,1};
int dy[20]={0,1,1,0,-1,-1,0};
void spfa(){
	memset(dis,0x3f,sizeof(dis));
	dis[5][5]=0;
	int det=5;
	queue<PII>Q;
	Q.push(mp(0,0));
	while(!Q.empty()){
		PII u=Q.front();Q.pop();
		for(int i=1;i<=6;++i){
			int vx=u.fi+dx[i];
			int vy=u.se+dy[i];
			if(vx>4||vx<-4||vy>4||vy<-4) continue ;
			if(dis[u.fi+det][u.se+det]+c[i]<dis[vx+det][vy+det]){
				dis[vx+det][vy+det]=dis[u.fi+det][u.se+det]+c[i];
				Q.push(mp(vx,vy));
			}
		}
	}
	for(int i=1;i<=6;++i) c[i]=dis[dx[i]+det][dy[i]+det];
}
signed main(){
	T=read();
	while(T--){
		x=read(),y=read();
		for(int i=1;i<=6;++i) c[i]=read();
		spfa();
		long long ans=4e18;
		if(y<0){
			if(x<y){
				ans=1ll*llabs(y)*c[4]+1ll*llabs(y-x)*c[3];
			}
			else if(x>=y&&x<0){
				ans=1ll*llabs(x)*c[4]+1ll*llabs(x-y)*c[5];
			}
			else if(x>=0){
				ans=1ll*llabs(x)*c[6]+1ll*llabs(y)*c[5];
			}
		}
		else{
			if(x>y){
				ans=1ll*y*c[1]+1ll*llabs(x-y)*c[6];
			}
			else if(x<=y&&x>=0){
				ans=1ll*x*c[1]+1ll*llabs(y-x)*c[2];
			}
			else ans=1ll*y*c[2]+1ll*llabs(x)*c[3];
		}
		printf("%lld\n",ans);
	}
}