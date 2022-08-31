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
const int N=210000;
int n,m,k,q;
bool ans[N];
struct que{
	int l,r,x,y,id;
};
int ma[N*4];
void build(int me,int l,int r,int v){
	ma[me]=v;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(me*2,l,mid,v);
	build(me*2+1,mid+1,r,v);
}
void change(int me,int l,int r,int x,int v){
	if(l==r){
		ma[me]=v;return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(me*2,l,mid,x,v);
	else change(me*2+1,mid+1,r,x,v);
	
	ma[me]=max(ma[me*2],ma[me*2+1]);
}
int Do(int me,int l,int r,int x,int y){
	if(x<=l&&r<=y)return ma[me];
	
	int mid=(l+r)>>1;
	int rp=-1;
	if(x<=mid)rp=max(rp,Do(me*2,l,mid,x,y));
	if(y>mid)rp=max(rp,Do(me*2+1,mid+1,r,x,y));
	return rp;
}
struct WorkSystemX{
	vector<int>mes[N];
	vector<que>ask[N];
	void work(){
		build(1,1,m,n+5);
		per(i,n,1){
			rep(j,0,mes[i].size()-1){
				int x=mes[i][j];
				change(1,1,m,x,i);
			}
			rep(j,0,ask[i].size()-1){
				int u=Do(1,1,m,ask[i][j].l,ask[i][j].r);
				ans[ask[i][j].id]|=(u<=ask[i][j].y);
				
			}
		}
	}		
}gtx;
struct WorkSystemY{
	vector<int>mes[N];
	vector<que>ask[N];
	void work(){
		build(1,1,n,m+5);
		per(i,m,1){
			rep(j,0,mes[i].size()-1){
				int x=mes[i][j];
				change(1,1,n,x,i);
			}
			rep(j,0,ask[i].size()-1){
				int u=Do(1,1,n,ask[i][j].l,ask[i][j].r);
				ans[ask[i][j].id]|=(u<=ask[i][j].y);
				
			}
		}
	}		
}gty;
struct car{
	int x,y;
	void RD(){scanf("%d%d",&x,&y);}
}a[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	rep(i,1,k)a[i].RD();
	rep(i,1,q){
		int x,y,l,r;scanf("%d%d%d%d",&l,&x,&r,&y);
		gtx.ask[l].pb((que){x,y,l,r,i});
		gty.ask[x].pb((que){l,r,x,y,i});
	}
	rep(i,1,k){
		gtx.mes[a[i].x].pb(a[i].y);
		gty.mes[a[i].y].pb(a[i].x);
	}
	gtx.work();
	gty.work();
	rep(i,1,q)if(ans[i])printf("YES\n");else printf("NO\n");
	return 0;
}