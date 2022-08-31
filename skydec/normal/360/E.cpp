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
#define pll pair<LL,int>
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=10005;
int S1,S2,T;
struct heap{
	pll res[MAXN*40];
	int size;
	inline void up(int x){
		while(x!=1&&res[x]<res[x/2]){
			swap(res[x],res[x/2]);
			x/=2;
		}
	}
	inline void down(int x){
		while(1){
			int rp=x;
			rep(u,0,1)if(x*2+u<=size)if(res[x*2+u]<res[rp])rp=x*2+u;
			swap(res[rp],res[x]);
			if(x==rp)break;
			x=rp;
		}
	}
	inline void push(pll a){
		res[++size]=a;
		up(size);
	}
	inline pll pop(){
		pll re=res[1];
		res[1]=res[size--];
		down(1);
		return re;
	}
}b;
int n,m,k;
struct adj{
	int to,l,r,id;
	inline adj(int a=0,int b=0,int c=0,int d=0){
		to=a;l=b;r=c;id=d;
	}
};
vector<adj>p[MAXN];
LL dis[MAXN];bool vis[MAXN];int wl[MAXN];
// 1:win
// 2:lose
// 3:draw
inline void work(int type){
	rep(i,1,n){dis[i]=(LL)1e16;vis[i]=0;wl[i]=0;}
	wl[S1]|=1;wl[S2]|=2;dis[S1]=dis[S2]=0;
	b.push(pll(0,S1));b.push(pll(0,S2));
	while(b.size){
		pll rpc=b.pop();
		if(vis[rpc.se])continue;
		vis[rpc.se]=1;
		int x=rpc.se;
		rep(i,0,p[x].size()-1){
			adj ww=p[x][i];
			int y=ww.to;int w;
			if(!ww.id)w=ww.l;
			else{
				if(type==1){
					if(wl[x]==1)w=ww.l;
					else w=ww.r;
				}
				else{
					if(wl[x]==2)w=ww.r;
					else w=ww.l;
				}
			}
			if(dis[y]==dis[x]+w)wl[y]|=wl[x];
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				wl[y]=wl[x];
				b.push(pll(dis[y],y));
			}
		}
	}
}
int rp[MAXN];
void out(){
	if(wl[T]==1)printf("WIN\n");
	else if(wl[T]==2)printf("LOSE\n");
	else printf("DRAW\n");
	if(wl[T]&1){
		rep(x,1,n)rep(j,0,p[x].size()-1)if(p[x][j].id){
			int y=p[x][j].to;int l=p[x][j].l;int r=p[x][j].r;
			if(dis[x]<=dis[y]){
				if(wl[x]&2)rp[p[x][j].id]=r;
				else rp[p[x][j].id]=l;
			}
			else rp[p[x][j].id]=r;
		}
		rep(i,1,k)printf("%d ",rp[i]);
	}
	exit(0);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d",&S1,&S2,&T);
	rep(i,1,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[x].pb(adj(y,z,0,0));
	}
	rep(i,1,k){
		int x,y,l,r;
		scanf("%d%d%d%d",&x,&y,&l,&r);
		p[x].pb(adj(y,l,r,i));
	}
	work(1);
	if(wl[T]&1)out();
	work(2);
	out();
	return 0;
}