#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,p;
int k;
struct node{
	PII stk[7];int top;
}tre[600010];
int tag[600010];
int a[150010];
node mer(node x,node y){
	// printf("x:");printf("%d ",x.top);
	// for(int i=1;i<=x.top;++i) printf("%d,%d ",x.stk[i].fi,x.stk[i].se);printf("\n");
	// printf("y:");printf("%d ",y.top);
	// for(int i=1;i<=y.top;++i) printf("%d,%d ",y.stk[i].fi,y.stk[i].se);printf("\n");
	priority_queue<PII>Q;
	PII stk[15];int top=0;
	for(int i=1;i<=x.top;++i) stk[++top]=x.stk[i];
	for(int i=1;i<=y.top;++i){
		bool fl=0;
		for(int j=1;j<=top;++j) if(y.stk[i].se==stk[j].se){stk[j].fi+=y.stk[i].fi;fl=1;}
		if(!fl) stk[++top]=y.stk[i];
	}
	for(int i=1;i<=top;++i) Q.push(stk[i]);
	while(Q.size()>k){
		for(int i=1;i<=k+1;++i) stk[i]=Q.top(),Q.pop();
		int mn=stk[k+1].fi;
		for(int i=1;i<=k;++i){
			stk[i].fi-=mn;if(stk[i].fi!=0) Q.push(stk[i]);
		}
	}
	node ret;ret.top=0;
	while(Q.size()) ret.stk[++ret.top]=Q.top(),Q.pop();
	// printf("ret:");printf("%d ",ret.top);
	// for(int i=1;i<=ret.top;++i) printf("%d,%d ",ret.stk[i].fi,ret.stk[i].se);printf("\n");
	return ret;
}
void pushup(int p){
	tre[p]=mer(tre[p<<1],tre[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
		tre[p].stk[tre[p].top=1]=mp(1,a[l]);return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	pushup(p);
}
void pushtag(int p,int l,int r,int k){
	tre[p].stk[tre[p].top=1]=mp(r-l+1,k);
	tag[p]=k;
}
void pushdown(int p,int l,int r){
	if(tag[p]!=0){
		int mid=l+r>>1;
		pushtag(p<<1,l,mid,tag[p]);
		pushtag(p<<1|1,mid+1,r,tag[p]);
		tag[p]=0;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		pushtag(p,l,r,k);return ;
	}
	pushdown(p,l,r);int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
node query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tre[p];
	pushdown(p,l,r);
	int mid=l+r>>1;
	node ret;ret.top=0;
	if(L<=mid) ret=mer(ret,query(p<<1,l,mid,L,R));
	if(R>mid) ret=mer(ret,query(p<<1|1,mid+1,r,L,R));
	return ret;
}
int main(){
	n=read(),m=read(),p=read();k=100/p;
	for(int i=1;i<=n;++i) a[i]=read();build(1,1,n);
	for(int i=1;i<=m;++i){
		int op=read();
		if(op==1){
			int l=read(),r=read(),id=read();
			update(1,1,n,l,r,id);
		}
		else{
			int l=read(),r=read();
			node t=query(1,1,n,l,r);
			printf("%d ",t.top);
			for(int j=1;j<=t.top;++j) printf("%d ",t.stk[j].se);printf("\n");
		}
	}
}