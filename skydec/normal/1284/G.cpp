#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=45;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
char s[N][N];
int idx[N][N],k;
int res;
pii eg[N*N];int p;
int deg[N*N];
bool in[N*N];
//....
vector<pii> go[N*N];
int q[N*N*N*N];
bool inq[N*N];
int dis[N*N];
int pre[N*N];
int fa[N*N];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void touch(int x){
	if(in[x]){
		deg[eg[x].fi]++;
		res++;
	}
	else deg[eg[x].fi]--,res--;
	in[x]^=1;
}
bool m1(){
	rep(i,1,k)fa[i]=i;
	int blk=k;
	rep(i,1,p)if(!in[i]){
		if(get(eg[i].fi)!=get(eg[i].se))
		fa[get(eg[i].fi)]=get(eg[i].se),blk--;
		if(blk==1)return 1;
	}
	return 0;
}
bool m2(){
	rep(i,1,k)if(deg[i]<0)return 0;
	return 1;
}
int gkd(){
	rep(i,0,p+1)go[i].clear();
	rep(i,1,p)if(!in[i]){
		touch(i);
		
		rep(s,1,k)fa[s]=s;
		int blk=k;
		rep(s,1,p)if(!in[s]){
			if(get(eg[s].fi)!=get(eg[s].se))
			fa[get(eg[s].fi)]=get(eg[s].se),blk--;
		}
		if(blk==1)go[0].pb(pii(i,-1));
		if(deg[eg[i].fi]>=0)go[i].pb(pii(p+1,0));

		rep(j,1,p)if(in[j])if(i!=j){
			touch(j);
			
			if((blk==1)||(blk==2&&(get(eg[j].fi)!=get(eg[j].se))))go[j].pb(pii(i,-1));

			if(deg[eg[j].fi]>=0&&deg[eg[i].fi]>=0)go[i].pb(pii(j,1));
			touch(j);
		}
		touch(i);
	}
	rep(i,0,p+1)dis[i]=1e9,inq[i]=0;
	dis[0]=0;
	q[q[0]=1]=0;inq[0]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(auto w:go[x]){
			int y=w.fi;
			int dd=w.se;
			if(dis[y]>dis[x]+dd){
				dis[y]=dis[x]+dd;
				pre[y]=x;
				if(!inq[y]){
					q[++q[0]]=y;
					inq[y]=1;
				}
			}
		}
		inq[x]=0;
	}
	int T=p+1;
	int S=0;
	if(dis[T]>=0)return 0;
	for(int x=pre[T];x!=S;x=pre[x])touch(x);
	return dis[T];
}
//....
char rp[N][N];
pii re[N*N];
int Main(){
	memset(idx,0,sizeof idx);
	memset(deg,0,sizeof deg);
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	k=0;p=0;
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='O')idx[i][j]=++k,re[k]=pii(i,j);
	else idx[i][j]=0;
	if(k==1)goto gt;
	rep(i,1,n)rep(j,1,m)if(idx[i][j])if((i+j)%2==0){
		rep(s,0,3){
			if(idx[i+dx[s]][j+dy[s]]){
				deg[idx[i][j]]++;
				eg[++p]=pii(idx[i][j],idx[i+dx[s]][j+dy[s]]);
			}
		}
		deg[idx[i][j]]=deg[idx[i][j]]-(1+(!(i==1&&j==1)));
		//if(i==1&&j==1)deg[idx[i][j]]=0;
		if(deg[idx[i][j]]<0){
			return 0;
		}
	}
	//1...p
	memset(in,0,sizeof in);
	if(p==0)goto gt;
	if(!m1())return 0;

	res=0;
	res+=p-(k-1);
	while(res>0){
		int _res=res;
		//printf("_%d\n",res);
		gkd();
		if(_res<=res)return 0;
	}
	gt:;
	puts("YES");
	rep(i,1,2*n)rep(j,1,2*m)rp[i][j]=' ';
	rep(i,1,n)rep(j,1,m)rp[2*i-1][2*j-1]=s[i][j],rp[2*i][2*j]=' ';

	rep(i,1,p){
		pii x=re[eg[i].fi];
		pii y=re[eg[i].se];
		if(x>y)swap(x,y);
		if(y.fi==x.fi+1){
			if(in[i])rp[2*x.fi][2*x.se-1]=' ';
			else rp[2*x.fi][2*x.se-1]='O';
		}
		else{
			if(in[i])rp[2*x.fi-1][2*x.se]=' ';
			else rp[2*x.fi-1][2*x.se]='O';
		}
	}
	rep(i,1,2*n-1){
		rep(j,1,2*m-1)putchar(rp[i][j]);puts("");
	}
	return 1;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)if(!Main())puts("NO");
	return 0;
}