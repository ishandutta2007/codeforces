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
const int MAXN=1650;
#define x1 xxxxx1
#define y1 yyyyy1
int x1,y1;
int n,m;bool a[MAXN][MAXN];
bool f[MAXN][MAXN],tf[MAXN][MAXN];
pii h[MAXN*MAXN],q[MAXN*MAXN];int qq,qh;int dep[MAXN][MAXN];
vector<int>ans;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
inline bool trans(int x,int y,int k){
	x1=x+dx[k];y1=y+dy[k];
	if(x1<1||x1>n)return 0;
	if(y1<1||y1>m)return 0;
	return 1;
}
inline void BFS(int x2,int y2){
	q[qq=1]=pii(x2,y2);f[x2][y2]=1;
	rep(i,1,qq){
		int x=q[i].fi;int y=q[i].se;
		rep(k,1,4)if(trans(x,y,k)){
			if(f[x1][y1])continue;
			if(!a[x1][y1])continue;
			f[x1][y1]=1;
			q[++qq]=pii(x1,y1);
		}
	}
}
inline int work(int x2,int y2){
	h[qh=1]=pii(x2,y2);tf[x2][y2]=1;dep[x2][y2]=0;
	rep(i,1,qh){
		int x=h[i].fi;int y=h[i].se;
		if(dep[x][y]==dep[h[qh].fi][h[qh].se]&&i<qh-5)break;
		rep(k,1,4)if(trans(x,y,k)){
			if(tf[x1][y1])continue;
			if(!a[x1][y1])continue;
			tf[x1][y1]=1;
			h[++qh]=pii(x1,y1);
			dep[x1][y1]=dep[x][y]+1;
		}
	}
	int D=dep[h[qh].fi][h[qh].se];
	if(D<=10){
		rep(i,1,qh)tf[h[i].fi][h[i].se]=0;
	}
	return D>10;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
	rep(i,1,n)rep(j,1,m)if(a[i][j]&&!f[i][j]){
		BFS(i,j);
		int s=work(i,j);
		per(k,qq,2)if(!tf[q[k].fi][q[k].se])s+=work(q[k].fi,q[k].se);
		ans.pb(s);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	rep(i,0,ans.size()-1)printf("%d ",ans[i]);
	return 0;
}