#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<assert.h>
#include<map>
#include<set>
#include<string>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int jsb=1000000007;
const int N=105;
int g[2][2][N][N][N];//g[st][ed][i][j]ijst,ed
int f[N][N][2];//f[len][i][v] :ilenv
int n,m;int ans[N];
vector<int>xu[N*N];
int st[N*N],ed[N*N];
int go[N][N];
inline void add(int &x,int y){
	x+=y;if(x>=jsb)x-=jsb;
}
pii GOGOGO(VI &tp,int x,bool fan){
	int now=0;
	while(now+1<=tp.size()){
		int y=tp[now];int bian=go[x][y];
		if(!bian||tp.size()>2*n||(bian>m)!=fan)return pii(10086,-1);
		rep(j,0,xu[bian].size()-1)tp.pb(xu[bian][j]);x=y;now++;
	}
	return pii(tp.size(),x);
}
void Read(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int x,y,k;scanf("%d%d%d",&x,&y,&k);
		go[x][y]=i;
		st[i]=x;ed[i]=y;
		rep(j,1,k){
			int v;scanf("%d",&v);xu[i].pb(v);
		}
		go[y][x]=i+m;
		st[i+m]=y;ed[i+m]=x;
		per(j,k-1,0)xu[i+m].pb(xu[i][j]);
		if(k==0)g[0][0][x][y][1]++;
	}
}
int man[N][N][N];// 
int wei[N][N][N];// 
void work(bool fan){
	memset(man,0,sizeof man);
	memset(wei,0,sizeof wei);
	rep(i,1,2*m)if((i<=m)^fan){
		rep(j,0,xu[i].size()-1)if(xu[i][j]==st[i]){
			VI t1,t2;
			per(k,j-1,0)t1.pb(xu[i][k]);
			pii result=GOGOGO(t1,st[i],fan^1);
			if(result.fi>2*n)continue;
			if(j+1==xu[i].size())wei[result.se][ed[i]][result.fi+1]++;
			else{
				if(xu[i][j+1]!=ed[i])continue;rep(k,j+2,xu[i].size()-1)t2.pb(xu[i][k]);
				pii res2=GOGOGO(t2,ed[i],fan);if(res2.fi+1+result.fi<=2*n)man[result.se][res2.se][res2.fi+1+result.fi]++;
			}
		}
	}
}				
void GetG(){
	work(0);rep(i,1,n)rep(j,1,n)rep(k,1,2*n){g[1][1][i][j][k]=man[i][j][k];g[1][0][i][j][k]=wei[i][j][k];}
	work(1);rep(i,1,n)rep(j,1,n)rep(k,1,2*n)g[0][1][j][i][k]=wei[i][j][k];
}
void Solve(){
	rep(i,1,n)rep(j,1,n)rep(k,1,2*n)rep(v,0,1)add(f[k][j][v],g[1][v][i][j][k]);int rp;
	rep(k,1,n*2){
		rp=0;
		rep(i,1,n){
			add(rp,f[k][i][1]);
			rep(mid,0,1)if(f[k][i][mid]){
				rep(ed,0,1)rep(zd,1,n)rep(len,1,2*n-k)
				add(f[k+len][zd][ed],f[k][i][mid]*1ll*g[mid^1][ed][i][zd][len]%jsb);
			}
		}
		printf("%d\n",rp);
	}
}
int main(){
	Read();
	GetG();
	Solve();
	return 0;
}