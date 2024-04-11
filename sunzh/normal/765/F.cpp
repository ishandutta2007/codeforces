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
int a[100010],c[100010];
vector<PII>vec[100010];
int ans[300010];
int tre[100010];
void init(){
	for(int i=1;i<=n;++i) tre[i]=2e9;
}
void upd(int x,int k){
	while(x){
		tre[x]=min(tre[x],k);x-=x&-x;
	}
}
int qry(int x){
	int rs=2e9;
	while(x<=n){
		rs=min(rs,tre[x]);x+=x&-x;
	}
	return rs;
}
int mx[400010];
void pushup(int p){mx[p]=max(mx[p<<1],mx[p<<1|1]);}
void build(int p,int l,int r){
	if(l==r){
		mx[p]=0;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p);
}
void modify(int p,int l,int r,int pos,int k){
	if(l==r){
		mx[p]=max(mx[p],k);return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(p<<1,l,mid,pos,k);
	else modify(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mx[p];
	int res=0,mid=l+r>>1;
	if(L<=mid) res=max(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,query(p<<1|1,mid+1,r,L,R));
	return res;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=c[i]=read();
	sort(c+1,c+n+1);q=read();
	int m=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;++i) a[i]=lower_bound(c+1,c+m+1,a[i])-c;
	for(int i=1;i<=q;++i){
		int l=read(),r=read();
		vec[r].pb(mp(l,i));
	}
	memset(ans,0x3f,sizeof(ans));
	build(1,1,m);init();
	for(int i=1;i<=n;++i){
		int pos=query(1,1,m,1,a[i]);
		while(pos){
			int k=c[a[i]]-c[a[pos]];
			upd(pos,k);
			if(k==0) break ;
			k>>=1;
			int p=lower_bound(c+1,c+m+1,c[a[i]]-k)-c;
			pos=query(1,1,m,p,a[i]);
		}
		for(PII j:vec[i]) ans[j.se]=min(ans[j.se],qry(j.fi));
		modify(1,1,m,a[i],i);
	}
	build(1,1,m);init();
	for(int i=1;i<=n;++i){
		int pos=query(1,1,m,a[i],m);
		while(pos){
			int k=c[a[pos]]-c[a[i]];
			upd(pos,k);
			if(k==0) break ;
			k>>=1;
			int p=upper_bound(c+1,c+m+1,c[a[i]]+k)-c-1;
			pos=query(1,1,m,a[i],p);
		}
		for(PII j:vec[i]) ans[j.se]=min(ans[j.se],qry(j.fi));
		modify(1,1,m,a[i],i);
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
}