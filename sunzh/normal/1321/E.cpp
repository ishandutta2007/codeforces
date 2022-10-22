#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n,m,p;
int fy[200010];
int tag[800040],s[800040];
struct node{
	int val,x,y;
}wp[200010],am[200010],mo[200010];
bool cmp(node a,node b){
	return a.x<b.x;
}
void pushup(int p){
	s[p]=max(s[p<<1],s[p<<1|1]);
}
void pushdown(int p){
	if(!tag[p]) return;
	s[p<<1]+=tag[p];s[p<<1|1]+=tag[p];
	tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];
	tag[p]=0;
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		s[p]+=k;
		tag[p]+=k;
		return;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(mid>=L) update(p<<1,l,mid,L,R,k);
	if(mid<R) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
signed main(){
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;++i) wp[i].x=read(),wp[i].val=read();
	for(int i=1;i<=m;++i) am[i].x=read(),am[i].val=read();
	for(int i=1;i<=p;++i) mo[i].x=read(),mo[i].y=read(),mo[i].val=read();
	sort(wp+1,wp+n+1,cmp);
	sort(am+1,am+m+1,cmp);
	sort(mo+1,mo+p+1,cmp);
	for(int i=1;i<=m;++i){
		fy[i]=am[i].x;
		update(1,1,m,i,i,-am[i].val);
	}
	int pl=1,ans=-9223372036854775807;
	for(int i=1;i<=n;++i){
		while(pl<=p&&wp[i].x>mo[pl].x){
			int pos=upper_bound(fy+1,fy+m+1,mo[pl].y)-fy;
			if(pos<=m) update(1,1,m,pos,m,mo[pl].val);
			++pl;
		}
		ans=max(ans,s[1]-wp[i].val);
	}
	printf("%lld\n",ans);
	return 0;
}