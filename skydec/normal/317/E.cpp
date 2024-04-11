#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int gt=500;
const int oo=500;
int tx,ty,sx,sy,m;
bool mp[1005][1005];
int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};
pii q[1010000];int top;int vis[1005][1005],pre[1005][1005];int cho=0;
inline bool cango(int x,int y,int k){
	x+=dx[k];y+=dy[k];
	if(x<0||y<0||x>2*oo||y>oo*2)return 0;
	if(mp[x][y])return 0;
	return 1;
}
inline void Go(int x,int ta){
	for(;ta;ta--){
		if(x==1)printf("U");
		else if(x==2)printf("D");
		else if(x==3)printf("L");
		else printf("R");
	}
}
inline bool wei(int x,int y){
	if(x>=oo-250&&x<=oo+250&&y>=oo-250&&y<=oo+250)return 0;
	return 1;
}
int sta[1010000];
inline void Bfs(){
	cho++;
	q[top=1]=(pii){sx,sy};vis[sx][sy]=cho;pre[sx][sy]=0;
	rep(i,1,top){
		int x=q[i].fi;
		int y=q[i].se;
		if(x==tx&&y==ty){
			while(pre[x][y]){
				sta[++sta[0]]=pre[x][y];
				int k=pre[x][y];
				x-=dx[k];y-=dy[k];
			}
			return;
		}
		rep(k,1,4)if(cango(x,y,k)){
			int x1=x+dx[k];
			int y1=y+dy[k];
			if(vis[x1][y1]==cho)continue;
			vis[x1][y1]=cho;
			pre[x1][y1]=k;
			q[++top]=(pii){x1,y1};
		}
	}
}
inline void CAOGo(){
	per(i,sta[0],1){
		int x1=tx+dx[sta[i]];
		int y1=ty+dy[sta[i]];
		if(mp[x1][y1])continue;
		tx=x1;ty=y1;
	}
}
inline void go_leftdown(){
	while(sx>-oo||sy>-oo){
		//printf("\n%d %d %d %d\n",sx,sy,tx,ty);
		//system("pause");
		if((ty<oo-120||ty>oo+120)&&(sy<oo-120||sy>oo+120)){
			tx--;sx--;
			Go(3,1);
		}
		if((tx<oo-120||tx>oo+120)&&(sx<oo-120||sx>oo+120)){
			sy--;ty--;
			Go(2,1);
		}
	}
	//printf("%d %d %d %d\n",sx,sy,tx,ty);
}
inline void MAIN(){
	go_leftdown();
	if(sx<tx){
		rep(x,0,1000)rep(y,0,1000)if(mp[x][y]){
			Go(1,y-ty);Go(4,x-1-sx);
			Go(3,x-1-sx);Go(2,y-ty);
			tx=sx;goto pyc;
		}
		pyc:;
	}
	if(sx>tx){
		per(x,1000,0)rep(y,0,1000)if(mp[x][y]){
			Go(4,x+1-tx);Go(1,y-ty);Go(3,sx-tx);
			Go(4,sx-tx);Go(2,y-ty);Go(3,x+1-tx);
			tx=sx;goto dyc;
		}
		dyc:;
	}
	if(sy>ty){
		per(y,1000,0)rep(x,0,1000)if(mp[x][y]){
			Go(1,y+1-ty);Go(4,x-tx);Go(2,sy-ty);
			Go(1,sy-ty);Go(3,x-tx);Go(2,y+1-ty);
			ty=sy;goto byc;
		}
		byc:;
	}
	if(sy<ty){
		rep(y,0,1000)rep(x,0,1000)if(mp[x][y]){
			Go(4,x-tx);Go(1,y-1-sy);
			Go(2,y-1-sy);Go(3,x-tx);
			ty=sy;goto qyc;
		}
		qyc:;
	}
}	
inline void LetsGo(){
	while(1){
		Bfs();
		if(!sta[0]){
			printf("-1");
			exit(0);
		}
		sx=tx;sy=ty;
		//printf("%d %d\n",sx,sy);
		CAOGo();
		while(sta[0]){
			Go(sta[sta[0]--],1);
		}
		if(tx==sx&&ty==sy){
			exit(0);
		}
		if(wei(tx,ty)&&wei(sx,sy)){
			MAIN();
			return;
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&sx,&sy,&tx,&ty,&m);
	if(!m){
		printf("-1\n");
		return 0;
	}
	tx+=gt;ty+=gt;sx+=gt;sy+=gt;
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		x+=gt;y+=gt;
		mp[x][y]=1;
	}
	LetsGo();
	return 0;
}