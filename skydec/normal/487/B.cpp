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
const int N=110000;
int ma[N*4],mi[N*4],tag[N*4];
int val[N*4];
inline void Tag(int x,int v){
	tag[x]+=v;
	ma[x]+=v;
	mi[x]+=v;
}
inline void down(int x){
	if(tag[x]==0)return;
	Tag(x*2,tag[x]);Tag(x*2+1,tag[x]);
	tag[x]=0;
}
inline void up(int x){
	ma[x]=max(ma[x*2],ma[x*2+1]);
	mi[x]=min(mi[x*2],mi[x*2+1]);
	val[x]=min(val[x*2],val[x*2+1]);
}
void add(int me,int l,int r,int x,int y,int v){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		Tag(me,v);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	up(me);
}
void modify(int me,int l,int r,int x,int y,int v){
	if(l^r)down(me);
	if(l==r){
		val[me]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(me*2,l,mid,x,y,v);
	else modify(me*2+1,mid+1,r,x,y,v);
	up(me);
}
int get(int me,int l,int r,int x,int y,int most){
	if(l^r)down(me);
	if(mi[me]>most)return 1e9;
	if(ma[me]<=most&&x<=l&&r<=y)return val[me];
	int mid=(l+r)>>1;
	int ans=1e9;
	if(x<=mid)ans=min(ans,get(me*2,l,mid,x,y,most));
	if(y>mid)ans=min(ans,get(me*2+1,mid+1,r,x,y,most));
	return ans;
}

int n,s,l;
int f[N];
struct seg{
	int l,r,v;
}_mi[N],_ma[N];
int ti,ta;
int main(){
	scanf("%d%d%d",&n,&s,&l);
	rep(i,1,n){
		int x;scanf("%d",&x);
		
		while(ti&&_mi[ti].v>=x){
			add(1,1,n,_mi[ti].l,_mi[ti].r,_mi[ti].v);
			ti--;
		}
		_mi[ti+1]=(seg){_mi[ti].r+1,i,x};ti++;
		add(1,1,n,_mi[ti].l,_mi[ti].r,-x);
		
		while(ta&&_ma[ta].v<=x){
			add(1,1,n,_ma[ta].l,_ma[ta].r,-_ma[ta].v);
			ta--;
		}
		_ma[ta+1]=(seg){_ma[ta].r+1,i,x};ta++;
		add(1,1,n,_ma[ta].l,_ma[ta].r,x);
		
		if(i<l)f[i]=1e9;else f[i]=get(1,1,n,1,i-l+1,s)+1;
		if(i^n)modify(1,1,n,i+1,i+1,f[i]);
	}
	if(f[n]>n)f[n]=-1;
	printf("%d\n",f[n]);
	return 0;
}
//