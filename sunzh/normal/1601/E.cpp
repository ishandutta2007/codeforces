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
#define int long long
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
int n,q,k;
int a[300010];
int b[300010];
int que[300010],head,tail;
vector<PII>qr[300010];
int ans[300010];
const int inf=1e10;
struct sgm{
	int sz;
	int mn[2000010],tag[2000010],sum[2000010];
	void pushup(int p){
		sum[p]=sum[p<<1]+sum[p<<1|1];mn[p]=min(mn[p<<1],mn[p<<1|1]);
	}
	void pushdown(int p,int l,int r){
		if(tag[p]!=inf){
			tag[p<<1]=tag[p<<1|1]=mn[p<<1]=mn[p<<1|1]=tag[p];
			int mid=l+r>>1;
			sum[p<<1]=tag[p]*(mid-l+1),sum[p<<1|1]=tag[p]*(r-mid);
			tag[p]=inf;
		}
	}
	void build(int p,int l,int r){
		tag[p]=inf,mn[p]=inf;
		if(l==r){
			sum[p]=inf;return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);sum[p]=inf*(r-l+1);
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(L>R) return ;
		if(l>=L&&r<=R){
			tag[p]=mn[p]=k;sum[p]=(r-l+1)*k;return ;
		}
		pushdown(p,l,r);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int query(int p,int l,int r,int k){
		if(l==r){
			return mn[p]>=k?l:-1;
		}
		pushdown(p,l,r);
		int mid=l+r>>1;
		if(mn[p<<1]>=k){
			int res=query(p<<1|1,mid+1,r,k);
			if(res==-1) return mid;
			else return res;
		}
		else return query(p<<1,l,mid,k);
	}
	int qsum(int p,int l,int r,int L,int R){
		if(L>R) return 0;
		if(l>=L&&r<=R) return sum[p];
		pushdown(p,l,r);
		int mid=l+r>>1;
		int sum=0;
		if(L<=mid) sum+=qsum(p<<1,l,mid,L,R);
		if(R>mid) sum+=qsum(p<<1|1,mid+1,r,L,R);return sum;
	}
	void rebuild(int s){
		sz=s;
		build(1,1,s);
	}
	void upd(int x,int k){
		int T=query(1,1,sz,k);
		update(1,1,sz,x,T,k);
	}
	int qry(int l,int r){
		return qsum(1,1,sz,l,r);
	}
}T;
signed main(){
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	head=1,tail=0;
	for(int i=n;i>=1;--i){
		while(head<=tail&&a[que[tail]]>=a[i]) --tail;
		while(head<=tail&&que[head]-i>=k) ++head;
		que[++tail]=i;
		b[i]=a[que[head]];
	}
	for(int i=1;i<=q;++i){
		int l=read(),r=read();
		qr[l].pb(mp(r,i));
	}
	for(int i=n;i>n-k;--i){
		int sz=(i/k+1);
		T.rebuild(sz);
		for(int j=i;j>=1;j-=k){
			T.upd(j/k+2,b[j]);
			T.upd(j/k+1,a[j]);
			for(PII l:qr[j]){
				ans[l.se]=T.qry(j/k+1,(l.fi%k>=i%k?0:-1)+(l.fi/k+1));
			}
		}
	}
	for(int i=1;i<=q;++i) printf("%lld\n",ans[i]);
	return 0;
}