#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
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
const int N=2005;
int n,m,k;int res[N];
int _x[N],_y[N];
char str[N][N];
int right[N][N];
struct segtree{
	int mi[N*4],ma[N*4];
	void modify(int me,int l,int r,int x,int v){
		if(l==r){
			mi[me]=ma[me]=v;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)modify(me*2,l,mid,x,v);
		else modify(me*2+1,mid+1,r,x,v);
		mi[me]=mi[me*2];if(mi[me*2+1]<mi[me])mi[me]=mi[me*2+1];
		ma[me]=ma[me*2];if(ma[me*2+1]>ma[me])ma[me]=ma[me*2+1];
	}
	int ret;
	void work(int me,int l,int r,int x,int y,int v){
		if(mi[me]>v)return;
		if(ret)return;
		if(l==r){
			ret=l;
			return;
		}
		int mid=(l+r)>>1;
		if(y>mid)work(me*2+1,mid+1,r,x,y,v);
		if(x<=mid)work(me*2,l,mid,x,y,v);
	}
	inline int getr(int l,int r,int v){
		//[l..r]v 
		ret=0;
		work(1,1,n,l,r,v);
		if(!ret)ret=l-1;
		return ret;
	}
	void gao(int me,int l,int r,int x,int y,int v){
		if(mi[me]>v)return;
		if(ret)return;
		if(l==r){
			ret=l;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)gao(me*2,l,mid,x,y,v);
		if(y>mid)gao(me*2+1,mid+1,r,x,y,v);
	}
	inline int getl(int l,int r,int v){
		ret=0;
		gao(1,1,n,l,r,v);
		if(!ret)ret=r+1;
		return ret;
	}
	void build(int me,int l,int r){
		mi[me]=233333333;
		ma[me]=-1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(me*2,l,mid);
		build(me*2+1,mid+1,r);
	}
}seg[2005];
inline bool ok(int x,int y,int bc){
	if(right[x][y]<bc)return 0;
	int l=seg[y].getr(1,x,bc-1)+1;
	int r=seg[y].getl(x,n,bc-1)-1;
	return r-l+1>=bc;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)scanf("%s",str[i]+1);
	rep(i,1,k){
		scanf("%d%d",&_x[i],&_y[i]);
		str[_x[i]][_y[i]]='X';
	}
	rep(j,1,m)seg[j].build(1,1,n);
	rep(i,1,n)per(j,m,1){
		if(str[i][j]=='X')right[i][j]=0;
		else right[i][j]=right[i][j+1]+1;
	}
	
	int ans=0;
	
	rep(i,1,n)rep(j,1,m)seg[j].modify(1,1,n,i,right[i][j]);
	
	rep(i,1,n)rep(j,1,m){
		while(ok(i,j,ans+1))ans++;
	}
	per(i,k,1){
		res[i]=ans;
		
		str[_x[i]][_y[i]]='.';
		per(j,_y[i],1){
			if(str[_x[i]][j]=='X')right[_x[i]][j]=0;
			else right[_x[i]][j]=right[_x[i]][j+1]+1;
			
			seg[j].modify(1,1,n,_x[i],right[_x[i]][j]);
			while(ok(_x[i],j,ans+1))ans++;
		}
	}
	
	rep(i,1,k)printf("%d\n",res[i]);
	return 0;
}