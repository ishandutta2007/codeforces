#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
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
int res;
int a[100010];
bool tu[400010];
int tag[400010];
int tre[400010],ou[400010],minn[400010];
inline void pushup(int p){
	tre[p]=min(tre[p<<1],tre[p<<1|1]);
	tu[p]=tu[p<<1]|tu[p<<1|1];
	ou[p]=max(ou[p<<1],ou[p<<1|1]);
	minn[p]=min(minn[p<<1],minn[p<<1|1]);
}
inline void pushdown(int p){
	if(tag[p]){
		tre[p<<1]+=tag[p],tre[p<<1|1]+=tag[p];
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p]; 
		tag[p]=0;
	}
}
void build(int p,int l,int r){
	if(l==r){
		tre[p]=a[l];
		tu[p]=(a[l-1]<=a[l]&&a[l+1]<=a[l]);
		if(a[l-1]>=a[l]&&a[l+1]>=a[l]) ou[p]=l;
		if(a[l-1]>=a[l]&&a[l]>=a[l+1]) minn[p]=a[l-1]-a[l];
		else if(a[l-1]<=a[l]&&a[l]<=a[l+1]) minn[p]=a[l+1]-a[l];
		else minn[p]=0x3f3f3f3f3f3f3f3f;
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
inline int query(int p,int l,int r,int k){
	if(l==r) return tre[p];
	int mid=l+r>>1;
	pushdown(p);
	if(k<=mid) return query(p<<1,l,mid,k);
	else return query(p<<1|1,mid+1,r,k);
}
inline void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		tre[p]+=k,tag[p]+=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
//	pushup(p);
} 
inline void fix(int p,int l,int r,int pos){
	if(pos<1||pos>n) return ;
	if(l==r){
		int lf=query(1,1,n,l-1),ri=query(1,1,n,l+1);
		tu[p]=(lf<=tre[p]&&ri<=tre[p]);
		if(lf>=tre[p]&&ri>=tre[p]) ou[p]=l;
		else ou[p]=0;
		if(lf>=tre[p]&&tre[p]>=ri) minn[p]=lf-tre[p];
		else if(ri>=tre[p]&&tre[p]>=lf) minn[p]=ri-tre[p];
		else minn[p]=0x3f3f3f3f3f3f3f3f;
		return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(pos<=mid) fix(p<<1,l,mid,pos);
	else fix(p<<1|1,mid+1,r,pos);
	pushup(p);
}
inline bool queryt(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tu[p];
	pushdown(p);
	int mid=l+r>>1;
	bool f=0;
	if(L<=mid) f=f|queryt(p<<1,l,mid,L,R);
	if(R>mid) f=f|queryt(p<<1|1,mid+1,r,L,R);
	return f;
}
inline int queryo(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return ou[p];
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res=max(res,queryo(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,queryo(p<<1|1,mid+1,r,L,R));
	return res;
}
inline int querymin(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return minn[p];
	int mid=l+r>>1;
	int res=0x3f3f3f3f3f3f3f3f;
	if(L<=mid) res=min(res,querymin(p<<1,l,mid,L,R));
	if(R>mid) res=min(res,querymin(p<<1|1,mid+1,r,L,R));
	return res;
}
signed main(){
	memset(minn,0x3f,sizeof(minn));
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<n;++i) res+=abs(a[i]-a[i+1]);
	build(1,1,n);
	int q=read();
	while(q--){
		int op=read(),l=read(),r=read(),x=read();
		if(op==1){
			int ans=-0x3f3f3f3f3f3f3f3f;
			if(l==1){
				int ax=query(1,1,n,1),ay=query(1,1,n,2);
				if(ax-ay>=0) ans=x;
				else ans=max(-x,x-2*(ay-ax));++l;
			}
			if(r==n){
				int ax=query(1,1,n,n-1),ay=query(1,1,n,n);
				if(ay-ax>=0) ans=max(ans,x);
				else ans=max(ans,max(-x,x-2*(ax-ay)));--r;
			}
			if(l<=r){
				bool f=queryt(1,1,n,l,r);
				if(f) ans=(x<<1);
				else{
					int tmp=querymin(1,1,n,l,r);
//					printf("%d\n",tmp);
					if(tmp<0x3f3f3f3f3f3f3f3f) ans=max(ans,max(0ll,(x-tmp))<<1ll);
					int c=queryo(1,1,n,l,r);
					if(c){
						int ax=query(1,1,n,c-1),ay=query(1,1,n,c),az=query(1,1,n,c+1);
						ans=max(ans,max(-x,x-(ax-ay<<1))+max(-x,x-(az-ay<<1)));
					}
				}
			}
//			if(ans==-0x3f3f3f3f3f3f3f3f) cout<<4097324092183<<endl;
			printf("%I64d\n",ans+res);
		}
		else{
			if(l>1) res-=abs(query(1,1,n,l-1)-query(1,1,n,l));
			if(r<n) res-=abs(query(1,1,n,r)-query(1,1,n,r+1));
			update(1,1,n,l,r,x);
			if(l>1) res+=abs(query(1,1,n,l-1)-query(1,1,n,l));
			if(r<n) res+=abs(query(1,1,n,r)-query(1,1,n,r+1));
			fix(1,1,n,l-1);fix(1,1,n,l);
			fix(1,1,n,r);fix(1,1,n,r+1);
		}
	}
}