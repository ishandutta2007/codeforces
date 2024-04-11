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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int Tm,n;
int ps[300010];
int a[300010];
PII operator +(PII x,PII y){
	if(x.fi>y.fi) swap(x,y);
	if(x.fi!=y.fi) return x;else return mp(x.fi,y.se+x.se);
}
struct sgmt{
	int mn[2000010],cnt[2000010],tag[2000010];
	void pushup(int p){
		if(mn[p<<1]<mn[p<<1|1]) mn[p]=mn[p<<1],cnt[p]=cnt[p<<1];
		else if(mn[p<<1]==mn[p<<1|1]) mn[p]=mn[p<<1],cnt[p]=cnt[p<<1]+cnt[p<<1|1];
		else mn[p]=mn[p<<1|1],cnt[p]=cnt[p<<1|1];
	}
	void pushdown(int p){
		if(tag[p]){
			mn[p<<1]+=tag[p];mn[p<<1|1]+=tag[p];
			tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];tag[p]=0;
		}
	}
	void build(int p,int l,int r){
		mn[p]=0;cnt[p]=r-l+1;tag[p]=0;
		if(l==r) return ;
		int mid=l+r>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	}
	void update(int p,int l,int r,int L,int R,int k){
		// printf("p:%d,l:%d,r:%d,L:%d,R:%d,k:%d\n",p,l,r,L,R,k);
		if(l>=L&&r<=R){
			tag[p]+=k;mn[p]+=k;return ;
		}
		pushdown(p);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int query(int p,int l,int r,int L,int R){
		if(L>R) return 1e9;
		if(l==r){
			if(mn[p]<0) return -1;else return l;
		}
		pushdown(p);
		int mid=l+r>>1;
		if(l>=L&&r<=R){
			if(mn[p<<1]<0) return query(p<<1,l,mid,L,R);
			else {
				int t=query(p<<1|1,mid+1,r,L,R);
				if(t==-1) return mid;else return t;
			}
		}
		if(L>mid) return query(p<<1|1,mid+1,r,L,R);
		else if(R<=mid) return query(p<<1,l,mid,L,R);
		else{
			int t=query(p<<1,l,mid,L,R);
			if(t==mid){
				int q=query(p<<1|1,mid+1,r,L,R);
				return q==-1?t:q;
			}else return t;
		}
		return 1e9;
	}
	PII qry(int p,int l,int r,int L,int R){
		// printf("p:%d,l:%d,r:%d,L:%d,R:%d\n",p,l,r,L,R);
		if(L>R) return mp(0,0);
		if(l>=L&&r<=R) return mp(mn[p],cnt[p]);
		pushdown(p);
		int mid=l+r>>1;
		PII res=mp(1e9,0);
		if(L<=mid) res=res+qry(p<<1,l,mid,L,R);
		if(R>mid) res=res+qry(p<<1|1,mid+1,r,L,R);return res;
	}
}T[2];
signed main(){
	Tm=read();
	while(Tm--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		T[0].build(1,1,(n+1>>1)+1);
		T[1].build(1,1,(n>>1)+1);
		long long ans=0;
		for(int i=n;i>=1;--i){
			int p[2]={i+1>>1,i>>1};
			if(i&1) p[1]++;else p[0]++;
			// printf("i:%d,%d %d\n",i,p[0],p[1]);
			T[0].update(1,1,(n+1>>1)+1,p[0],(n+1>>1)+1,(i&1)?a[i]:-a[i]);
			T[1].update(1,1,(n>>1)+1,p[1],(n>>1)+1,(i&1)?-a[i]:a[i]);
			int P=min(T[0].query(1,1,(n+1>>1)+1,p[0],(n+1>>1)+1)*2-1,2*T[1].query(1,1,(n>>1)+1,p[1],(n>>1)+1));
			P=min(P,n);
			// printf("i:%d,P:%d\n",i,P);
			// printf("%d %d\n",T[0].query(1,1,(n+1>>1)+1,p[0],(n+1>>1)+1),T[1].query(1,1,(n>>1)+1,p[1],(n>>1)+1));
			PII a=T[0].qry(1,1,(n+1>>1)+1,p[0],(P+1>>1)),b=T[1].qry(1,1,(n>>1)+1,p[1],P>>1);
			// printf("%d %d,%d %d\n",a.fi,a.se,b.fi,b.se);
			if(a.fi==0) ans+=a.se;if(b.fi==0) ans+=b.se;
		}
		printf("%lld\n",ans);
	}
}