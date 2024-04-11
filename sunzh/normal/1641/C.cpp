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
struct oper{
	int l,r,x;
}e[200010];
PII qr[200010];
int qc;
int c;
const int inf=1e9;
int fir[200010];
int tag[800010],cnt[800010],mx[800010];
void pushup(int p,int l,int r){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	if(tag[p]!=inf) cnt[p]=r-l+1,mx[p]=min(mx[p],tag[p]);else cnt[p]=cnt[p<<1]+cnt[p<<1|1];
}
void build(int p,int l,int r){
	tag[p]=mx[p]=inf;cnt[p]=0;
	if(l==r) return ;
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	pushup(p,l,r);
}
void modify(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		tag[p]=min(tag[p],k);mx[p]=min(mx[p],k);if(l!=r) pushup(p,l,r);else if(k!=inf) cnt[p]=1;return ;
	}
	int mid=l+r>>1;
	if(L<=mid) modify(p<<1,l,mid,L,R,k);
	if(R>mid) modify(p<<1|1,mid+1,r,L,R,k);
	pushup(p,l,r);
}
int query(int p,int l,int r,int L,int R){
	if(L>R) return 0;
	if(tag[p]!=inf) return min(R,r)-max(L,l)+1;
	if(l>=L&&r<=R) return cnt[p];
	int res=0,mid=l+r>>1;
	if(L<=mid) res+=query(p<<1,l,mid,L,R);
	if(R>mid) res+=query(p<<1|1,mid+1,r,L,R);
	return res;
}
int qmin(int p,int l,int r,int pos){
	if(l==r) return tag[p];
	int mid=l+r>>1;
	if(pos<=mid) return min(tag[p],qmin(p<<1,l,mid,pos));
	else return min(tag[p],qmin(p<<1|1,mid+1,r,pos));
}
int qmax(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mx[p];
	int mid=l+r>>1;
	int ret=0;
	if(L<=mid) ret=max(ret,qmax(p<<1,l,mid,L,R));
	if(R>mid) ret=max(ret,qmax(p<<1|1,mid+1,r,L,R));
	return min(ret,tag[p]);
}
int Tmp;
void update(int p,int l,int r,int pos,int k){
	if(l==r){
		if(k==1) Tmp=tag[p],mx[p]=tag[p]=0,cnt[p]=1;
		else mx[p]=tag[p]=Tmp,cnt[p]=0;return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(p<<1,l,mid,pos,k);
	else update(p<<1|1,mid+1,r,pos,k);
	pushup(p,l,r);
}
int binery(int p,int l,int r,int L,int R){
	if(cnt[p]==r-l+1) return -1;
	if(l>=L&&r<=R){
		if(l==r){
			return cnt[p]?-1:l;
		}
		int mid=l+r>>1;
		if(cnt[p]==r-l+1)return -1;
		if(cnt[p<<1]==mid-l+1) return binery(p<<1|1,mid+1,r,L,R);
		else return binery(p<<1,l,mid,L,R);
	}
	int mid=l+r>>1;
	if(L<=mid){
		int t=binery(p<<1,l,mid,L,R);
		if(t!=-1) return t;
	}
	if(R>mid) return binery(p<<1|1,mid+1,r,L,R);
	return -1;
}
int main(){
	n=read(),q=read();
	build(1,1,n);
	for(int i=1;i<=q;++i){
		int op=read();
		if(op==0){
			int l=read(),r=read(),x=read();
			if(x==0) modify(1,1,n,l,r,i);
			else e[++c]=oper{l,r,i};
		}
		else{
			int x=read();
			qr[++qc]=mp(x,i);
		}
	}
	for(int i=1;i<=c;++i){
		int t=query(1,1,n,e[i].l,e[i].r);
		// printf("%d,%d,%d,t:%d\n",e[i].l,e[i].r,e[i].x,t);
		if(t==e[i].r-e[i].l){
			int pos=binery(1,1,n,e[i].l,e[i].r);
			// printf("pos:%d\n",pos);
			update(1,1,n,pos,1);
			if(fir[pos]==0) fir[pos]=inf;
			fir[pos]=min(fir[pos],max(e[i].x,qmax(1,1,n,e[i].l,e[i].r)));
			update(1,1,n,pos,-1);
		}
	}
	for(int i=1;i<=qc;++i){
		if(fir[qr[i].fi]!=0){
			printf(fir[qr[i].fi]<=qr[i].se?"YES\n":"N/A\n");
		}
		else{
			printf(qmin(1,1,n,qr[i].fi)<=qr[i].se?"NO\n":"N/A\n");
		}
	}
}