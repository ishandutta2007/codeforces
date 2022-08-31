#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 1100000
int root[MAXN];int tot;int sum[MAXN*20],cl[MAXN*20],cr[MAXN*20];
int pos[MAXN];int n,m;int p[MAXN],q[MAXN];
void add(int &x,int y,int l,int r,int v){
	if(!x)x=++tot;
	if(l==r){
		sum[x]=sum[y]+1;
		return;
	}
	int mid=(l+r)>>1;
	if(v<=mid){
		cr[x]=cr[y];
		add(cl[x],cl[y],l,mid,v);
	}
	else
	{
		cl[x]=cl[y];
		add(cr[x],cr[y],mid+1,r,v);
	}
	sum[x]=sum[cl[x]]+sum[cr[x]];
}
int ask(int now,int l,int r,int x,int y){
	if(!now)return 0;
	if(x<=l&&r<=y)return sum[now];
	int mid=(l+r)>>1;int res=0;
	if(x<=mid)res+=ask(cl[now],l,mid,x,y);
	if(y>mid)res+=ask(cr[now],mid+1,r,x,y);
	return res;
}
int pre;
inline int f(int z){return (z-1+pre)%n+1;}
inline void Change(int &l1,int &r1,int &l2,int &r2){
	int a,b,c,d;	a=l1;b=r1;c=l2;d=r2;
	l1=min(f(a),f(b));
	r1=max(f(a),f(b));
	l2=min(f(c),f(d));
	r2=max(f(c),f(d));
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)scanf("%d",&q[i]);
	rep(i,1,n)pos[q[i]]=i;
	rep(i,1,n)add(root[i],root[i-1],1,n,pos[p[i]]);
	pre=-1;scanf("%d",&m);
	while(m--){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);pre++;
		Change(a,b,c,d);
		pre=ask(root[b],1,n,c,d);
		pre-=ask(root[a-1],1,n,c,d);
		//printf("%d %d %d %d-->%d\n",a,b,c,d,pre);
		printf("%d\n",pre);
	}
	return 0;
}