#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=255;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m,limit,S;
LL ans[N][N];
char a[N][N];
int vis[N][N];
int cho;
int wei[N][N];
pii q[N*N];int t;
void go(pii xx,int w){
	++cho;
	q[t=1]=xx;
	wei[xx.fi][xx.se]=w;
	ans[xx.fi][xx.se]+=w;
	vis[xx.fi][xx.se]=cho;
	rep(i,1,t){
		int x=q[i].fi;
		int y=q[i].se;
		int ww=wei[x][y]>>1;
		if(!ww)continue;
		rep(k,0,3){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if((nx==0)||(nx>n)||(ny==0)||(ny>m))continue;
			if(a[nx][ny]=='*')continue;
			if(vis[nx][ny]==cho)continue;

			vis[nx][ny]=cho;
			wei[nx][ny]=ww;
			ans[nx][ny]+=ww;
			q[++t]=pii(nx,ny);
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&limit);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,1,n)rep(j,1,m)if(a[i][j]<='Z'&&a[i][j]>='A'){
		go(pii(i,j),S*(a[i][j]-'A'+1));
	}
	int res=0;
	rep(i,1,n)rep(j,1,m)if(ans[i][j]>limit)++res;
	printf("%d\n",res);
	return 0;
}