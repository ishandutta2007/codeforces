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
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,q;
int a[110],b[100010];
struct sgmt1{
	int sum[400010];
	int tagk[400010],tagb[400010];
	int get(int x){
		return (x+1)*x>>1;
	}
	void pushtag(int p,int l,int r,int k,int b){
		tagk[p]+=k;
		tagb[p]+=b;
		sum[p]+=k*get(r-l+1)+b*(r-l+1);
	}
	void pushup(int p){
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
	void pushdown(int p,int l,int r){
		int mid=l+r>>1;
		pushtag(p<<1,l,mid,tagk[p],tagb[p]);
		pushtag(p<<1|1,mid+1,r,tagk[p],tagb[p]+tagk[p]*(mid-l+1));
		tagk[p]=tagb[p]=0;
	}
	void build(int p,int l,int r){
		if(l==r){
			sum[p]=b[l];return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);pushup(p);
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(l>=L&&r<=R){
			pushtag(p,l,r,k,k*(l-L));return ;
		}
		pushdown(p,l,r);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int query(int p,int l,int r,int L,int R){
		if(L>R) return 0;
		if(l>=L&&r<=R) return sum[p];
		pushdown(p,l,r);
		int mid=l+r>>1;
		int sum=0;
		if(L<=mid) sum+=query(p<<1,l,mid,L,R);
		if(R>mid) sum+=query(p<<1|1,mid+1,r,L,R);
		return sum;
	}
}T1;
struct sgmt2{
	int mn[400010],tag[400010];
	void pushup(int p){
		mn[p]=min(mn[p<<1|1],mn[p<<1]);
	}
	void pushdown(int p){
		if(tag[p]){
			mn[p<<1]+=tag[p],mn[p<<1|1]+=tag[p];
			tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
			tag[p]=0;
		}
	}
	void build(int p,int l,int r){
		if(l==r){
			mn[p]=b[l+1]-b[l];return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(l>=L&&r<=R){
			mn[p]+=k;tag[p]+=k;return ;
		}
		pushdown(p);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int query(int p,int l,int r,int k){
		// printf("p:%d,l:%d,r:%d,k:%d\n",p,l,r,k);
		// printf("%d\n",mn[p]);
		if(l==r){
			return mn[p]>k?l:-1;
		}pushdown(p);
		int mid=l+r>>1;
		if(mn[p<<1|1]>k){
			int t=query(p<<1,l,mid,k);
			return t==-1?mid+1:t;
		}
		else{
			return query(p<<1|1,mid+1,r,k);
		}
	}
}T2;
void getans(){
	int lst=0;
	int ans=a[1]+T1.query(1,1,m,1,1);
	// for(int i=1;i<=n;++i) ans+=a[i];
	for(int i=1;i<n;++i){
		int p=T2.query(1,1,m-1,a[i+1]-a[i]);
		if(p==-1) p=m;--p;
		// printf("i:%d,p:%d\n",i,p);
		ans+=a[i]*(p-lst)+T1.query(1,1,m,lst+2,p+1);lst=p;
		ans+=a[i+1]+T1.query(1,1,m,p+1,p+1);
	}
	ans+=T1.query(1,1,m,lst+2,m)+a[n]*(m-lst-1);
	printf("%lld\n",ans);
}
signed main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	T1.build(1,1,m);T2.build(1,1,m-1);
	// for(int i=1;i<=m;++i) printf("%d ",T1.query(1,1,m,i,i));printf("\n");
	for(int i=1;i<=q;++i){
		int tp=read(),k=read(),d=read();
		if(tp==1){
			for(int j=1;j<=k;++j){
				a[n-k+j]+=d*j;
			}
		}
		else{
			T1.update(1,1,m,m-k+1,m,d);
			T2.update(1,1,m-1,max(1ll,m-k),m-1,d);
		}
		getans();
		// for(int i=1;i<=m;++i) printf("%d ",T1.query(1,1,m,i,i));printf("\n");
	}
}