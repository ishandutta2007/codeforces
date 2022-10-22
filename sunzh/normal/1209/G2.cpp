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
int n,q;
int a[200010];
struct node{
	int mn,mx,tag,lmx,rmx,sum;
}tre[800010];
set<int>st[200010];
void pushdown(int p){
	if(tre[p].tag){
		tre[p<<1].mn+=tre[p].tag;
		tre[p<<1|1].mn+=tre[p].tag;
		tre[p<<1].tag+=tre[p].tag;
		tre[p<<1|1].tag+=tre[p].tag;
		tre[p].tag=0;
	}
}
void pushup(int p){
	tre[p].mx=max(tre[p<<1].mx,tre[p<<1|1].mx);
	if(tre[p<<1].mn<tre[p<<1|1].mn){
		tre[p].mn=tre[p<<1].mn;
		tre[p].lmx=tre[p<<1].lmx;
		tre[p].rmx=max(tre[p<<1].rmx,tre[p<<1|1].mx);
		tre[p].sum=tre[p<<1].sum;
	}
	else if(tre[p<<1].mn==tre[p<<1|1].mn){
		tre[p].mn=tre[p<<1].mn;
		tre[p].lmx=tre[p<<1].lmx,tre[p].rmx=tre[p<<1|1].rmx;
		tre[p].sum=tre[p<<1].sum+tre[p<<1|1].sum+max(tre[p<<1].rmx,tre[p<<1|1].lmx);
	}
	else{
		tre[p].mn=tre[p<<1|1].mn;
		tre[p].lmx=max(tre[p<<1].mx,tre[p<<1|1].lmx);
		tre[p].rmx=tre[p<<1|1].rmx;
		tre[p].sum=tre[p<<1|1].sum;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(L>R) return ;
	if(l>=L&&r<=R){
		tre[p].mn+=k;tre[p].tag+=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
void upd(int p,int l,int r,int pos,int k){
	if(l==r){
		tre[p].mx=tre[p].lmx=k;
		return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(pos<=mid) upd(p<<1,l,mid,pos,k);
	else upd(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
void add(int x,int k){
	if(!st[x].size()) return ;
	int l=*st[x].begin();
	auto it=st[x].end();int r=*(--it);
	// printf("l:%d,r:%d\n",l,r);
	update(1,0,n+1,l,r-1,k);
	if(k==-1) upd(1,0,n+1,l,0);
	else upd(1,0,n+1,l,st[x].size());
}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read(),st[a[i]].insert(i);
	for(int i=1;i<=200000;++i) add(i,1);
	printf("%d\n",n-tre[1].sum);
	for(int i=1;i<=q;++i){
		int x=read(),y=read();
		add(a[x],-1);
		st[a[x]].erase(x);add(a[x],1);
		add(y,-1);st[y].insert(x);add(y,1);a[x]=y;
		printf("%d\n",n-tre[1].sum);
	}
}