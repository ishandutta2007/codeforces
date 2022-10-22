#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define pow powl
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;
int a[200010];
int sum[800010],minn[800010],tag[800010],maxn[800010];
void pushup(int p){
	sum[p]=sum[p<<1]+sum[p<<1|1];
	minn[p]=min(minn[p<<1],minn[p<<1|1]);
	maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
}

void pushdown(int p,int l,int r){
	if(tag[p]){
		tag[p<<1]=tag[p<<1|1]=tag[p];
		minn[p<<1]=minn[p<<1|1]=maxn[p<<1]=maxn[p<<1|1]=tag[p];
		int mid=l+r>>1;
		sum[p<<1]=tag[p]*(mid-l+1);
		sum[p<<1|1]=tag[p]*(r-mid);
		tag[p]=0;
	}
}

void build(int p,int l,int r){
	if(l==r){
		sum[p]=minn[p]=maxn[p]=a[l];return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p);
}

void update(int p,int l,int r,int L,int R,int k){
	if(L>R) return ;
	if(l>=L&&r<=R){
		sum[p]=k*(r-l+1);minn[p]=maxn[p]=k;tag[p]=k;return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}

int bsmax(int p,int l,int r,int k){
//	printf("k:%d,l:%d,r:%d\n",k,l,r);
	if(l==r) return l;
	int mid=l+r>>1;
	pushdown(p,l,r);
	if(minn[p<<1]>k) return bsmax(p<<1|1,mid+1,r,k);
	else return bsmax(p<<1,l,mid,k);
}
int bssum(int p,int l,int r,int k){
	if(l==r) return l;
	pushdown(p,l,r);
	int mid=l+r>>1;
//	printf("p:%d,l:%d,r:%d,k:%d\n",p,l,r,k);
	if(sum[p<<1]+maxn[p<<1|1]>k) return bssum(p<<1,l,mid,k);
	else return bssum(p<<1|1,mid+1,r,k-sum[p<<1]);
}
int qsum(int p,int l,int r,int L,int R){
	if(L>R) return 0;
	if(l>=L&&r<=R) return sum[p];
	pushdown(p,l,r);
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res+=qsum(p<<1,l,mid,L,R);
	if(R>mid) res+=qsum(p<<1|1,mid+1,r,L,R);return res;
}
signed main(){
	memset(minn,0x3f,sizeof(minn));
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	a[0]=0x3f3f3f3f,a[n+1]=0;
	build(1,0,n+1);
	while(q--){
		int op=read();
		int x=read(),y=read();
		if(op==1){
			int pos=bsmax(1,0,n+1,y);
			update(1,0,n+1,pos,x,y);
		}
		else{
			int l=x;
			int ans=0;
			while(l<=n){
				int pos=max(x,bsmax(1,0,n+1,y));
//				printf("pos:%d\n",pos);
				if(qsum(1,0,n+1,pos,pos)>y) break ;
				int sum=y+qsum(1,0,n+1,0,pos-1);
//				printf("sum:%lld\n",sum);
				int p=min(n,bssum(1,0,n+1,sum));
//				if(p<pos) break ;
				ans+=p-pos+1;
				y-=qsum(1,0,n+1,pos,p);
//				printf("p:%d,pos:%d,y:%d\n",p,pos,y);
				l=p+1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}