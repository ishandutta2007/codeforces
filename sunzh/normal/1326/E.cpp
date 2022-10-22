#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
PII a[300010];
int q[300010];
int maxn[1200010],tag[1200010];
void pushup(int p){
	maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
}
void pushdown(int p){
	if(tag[p]){
		maxn[p<<1]+=tag[p];maxn[p<<1|1]+=tag[p];
		tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];
		tag[p]=0;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		maxn[p]+=k;tag[p]+=k; return ;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=i;
	for(int i=1;i<=n;++i) q[i]=read();
	sort(a+1,a+n+1);
	int ps=n;
	update(1,1,n,1,a[n].se,1);
	for(int i=1;i<=n;++i){
		printf("%d ",a[ps].fi);
		update(1,1,n,1,q[i],-1);
		while(ps>1&&maxn[1]<=0){
			update(1,1,n,1,a[--ps].se,1);
		}
	}
	return 0;
}