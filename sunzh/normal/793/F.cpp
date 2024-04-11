#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
const int inf=1e9+7;
int n,m,Q;
vector<int>vec[100010];
vector<PII>q[100010];
int ans[100010];
int mx[400010],tag[400010];
void pushup(int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void pushdown(int p){
	if(tag[p]!=inf){
		tag[p<<1]=min(tag[p],tag[p<<1]);
		tag[p<<1|1]=min(tag[p],tag[p<<1|1]);
		mx[p<<1]=min(tag[p],mx[p<<1]);
		mx[p<<1|1]=min(tag[p],mx[p<<1|1]);
		tag[p]=inf;
	}
}
void change(int p,int l,int r,int pos,int w){
	if(l==r){
		mx[p]=w;
		return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(pos<=mid) change(p<<1,l,mid,pos,w);
	else change(p<<1|1,mid+1,r,pos,w);
	pushup(p);
}
void modify(int p,int l,int r,int L,int R,int w){
//	printf("p:%d,l:%d,r:%d,L:%d,R:%d,w:%d\n",p,l,r,L,R,w);
	if(l>=L&&r<=R){
		mx[p]=min(mx[p],w);tag[p]=min(tag[p],w);return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) modify(p<<1,l,mid,L,R,w);
	if(R>mid) modify(p<<1|1,mid+1,r,L,R,w);
	pushup(p); 
}
int query(int p,int l,int r,int v){
//	printf("p:%d,l:%d,r:%d,v:%d\n",p,l,r,v);
	if(l==r){
//		printf("l:%d\n",l);
		return l;
	}
	pushdown(p);
	int mid=l+r>>1;
//	printf("mx:%d,%d %d\n",mx[p],mx[p<<1],mx[p<<1|1]); 
	if(mx[p<<1]<=v) return query(p<<1|1,mid+1,r,v);
	else return query(p<<1,l,mid,v);
}
int main(){
	for(int i=0;i<=400000;++i) mx[i]=0,tag[i]=inf;
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int a=read(),b=read();
		if(a==b) continue ;
		vec[a].pb(b);
	}
	Q=read();
	for(int i=1;i<=Q;++i){
		int l=read(),r=read();q[l].pb(mp(r,i));
	}
	for(int i=n;i>=1;--i){
		change(1,1,n,i,inf);
//		modify(1,1,n,i,i,inf);
//		modify(1,1,n,i,i,i);
		for(int v:vec[i]) modify(1,1,n,i,v-1,v);
		for(auto j:q[i]){
			ans[j.se]=query(1,1,n,j.fi);
		}
	}
	for(int i=1;i<=Q;++i) printf("%d\n",ans[i]);
	return 0;
}