#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define For(i,j,k) for(int i=j;i<k;i++)
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
int cov[MAXN*8],sum[MAXN*8],len[MAXN*8];
int n,m;
inline int up(int x){
	if(cov[x])sum[x]=len[x];
	else if(len[x]==1)sum[x]=0;
	else sum[x]=sum[x*2]+sum[x*2+1];
}
void cover(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		cov[now]++;
		up(now);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(now*2,l,mid,x,y);
	if(y>mid)cover(now*2+1,mid+1,r,x,y);
	up(now);
}
void recover(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		cov[now]--;
		up(now);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)recover(now*2,l,mid,x,y);
	if(y>mid)recover(now*2+1,mid+1,r,x,y);
	up(now);
}
int ask(int now,int l,int r,int x,int y){
	if(cov[now])return min(r,y)-max(l,x)+1;
	if(x<=l&&r<=y)return sum[now];
	int res=0;
	int mid=(l+r)>>1;
	if(x<=mid)res+=ask(now*2,l,mid,x,y);
	if(y>mid)res+=ask(now*2+1,mid+1,r,x,y);
	return res;
}
struct jdb{
	int l,r,co;
};
vector<jdb>jsb[MAXN];
vector<int>son[MAXN];
int st[MAXN],ed[MAXN];int tot=0;
int dt[MAXN];
void dfs(int x){
	st[x]=++tot;dt[tot]=x;
	For(i,0,son[x].size())if(!st[son[x][i]])dfs(son[x][i]);
	ed[x]=tot;
}
inline void mk(int l,int r,int x,int y){
	jdb p,q;
	p.co=1;q.co=0;
	p.l=x;p.r=y;jsb[l].pb(p);
	q.l=x;q.r=y;jsb[r+1].pb(q);
}
void build(int now,int l,int r){
	len[now]=r-l+1;
	if(l==r)return;
	int mid=(l+r)/2;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
}
int ans[MAXN];
int main(){
	scanf("%d%d",&n,&m);build(1,1,n);
	For(i,1,n){
		int a,b;scanf("%d%d",&a,&b);
		son[a].pb(b);son[b].pb(a);
	}
	dfs(1);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		mk(st[a],ed[a],st[a],ed[a]);
		mk(st[a],ed[a],st[b],ed[b]);
		mk(st[b],ed[b],st[b],ed[b]);
		mk(st[b],ed[b],st[a],ed[a]);
	}
	rep(i,1,tot){
		For(j,0,jsb[i].size()){
			if(jsb[i][j].co)cover(1,1,n,jsb[i][j].l,jsb[i][j].r);
			else recover(1,1,n,jsb[i][j].l,jsb[i][j].r);
		}
		ans[dt[i]]=sum[1]-ask(1,1,n,i,i);
	}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}