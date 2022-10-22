#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
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
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
const int inf=1e9+7;
int n;
int a[150010],pos[150010];
struct info{
	int sum,mx,sec;
	int cmx,cnt,tag,admx;
};
struct sgmb{
	info tre[600010];
	void pushup(int p){
		if(!tre[p<<1].cnt) tre[p<<1].mx=tre[p<<1].sec=-inf;
		if(!tre[p<<1|1].cnt) tre[p<<1|1].sec=tre[p<<1|1].mx=-inf; 
		if(tre[p<<1].cmx==tre[p<<1].cnt) tre[p<<1].sec=-inf;
		if(tre[p<<1|1].cmx==tre[p<<1|1].cnt) tre[p<<1|1].sec=-inf;
		if(tre[p<<1].mx>tre[p<<1|1].mx){
			tre[p].mx=tre[p<<1].mx,tre[p].cmx=tre[p<<1].cmx;
			tre[p].sec=max(tre[p<<1].sec,tre[p<<1|1].mx);
		}
		else if(tre[p<<1].mx<tre[p<<1|1].mx){
			tre[p].mx=tre[p<<1|1].mx,tre[p].cmx=tre[p<<1|1].cmx;
			tre[p].sec=max(tre[p<<1|1].sec,tre[p<<1].mx);
		}
		else tre[p].mx=tre[p<<1].mx,tre[p].cmx=tre[p<<1].cmx+tre[p<<1|1].cmx,tre[p].sec=max(tre[p<<1].sec,tre[p<<1|1].sec);
		tre[p].cnt=tre[p<<1].cnt+tre[p<<1|1].cnt;tre[p].sum=tre[p<<1].sum+tre[p<<1|1].sum;
	}
	void pushdown(int p,int l,int r){
		if(tre[p].admx){
			int mx=max(tre[p<<1].cnt?tre[p<<1].mx:-inf,tre[p<<1|1].cnt?tre[p<<1|1].mx:-inf);
//			printf("mx:%d,admx:%d\n",mx,tre[p].admx);
			if(tre[p<<1].mx==mx) tre[p<<1].mx+=tre[p].admx,tre[p<<1].sum+=tre[p<<1].cmx*tre[p].admx,tre[p<<1].admx+=tre[p].admx;
			if(tre[p<<1|1].mx==mx) tre[p<<1|1].mx+=tre[p].admx,tre[p<<1|1].sum+=tre[p<<1|1].cmx*tre[p].admx,tre[p<<1|1].admx+=tre[p].admx;
			tre[p].admx=0;
		}
		pushup(p);//printf("%d\n",tre[p].sum);
		if(tre[p].tag){
			tre[p<<1].tag+=tre[p].tag;tre[p<<1|1].tag+=tre[p].tag;
			tre[p<<1].mx+=tre[p].tag,tre[p<<1|1].mx+=tre[p].tag;
			tre[p<<1].sec+=tre[p].tag,tre[p<<1|1].sec+=tre[p].tag;
			tre[p<<1].sum+=tre[p<<1].cnt*tre[p].tag,tre[p<<1|1].sum+=tre[p<<1|1].cnt*tre[p].tag;
			tre[p].tag=0;
		}
	}
	void update(int p,int l,int r,int pos,int k){
		if(l==r){
//			printf("k:%d\n",k);
			tre[p].mx=k,tre[p].sec=-inf,tre[p].cmx=1,tre[p].cnt=1,tre[p].sum=k;tre[p].tag=tre[p].admx=0;return ;
		}
		int mid=l+r>>1;
//		printf("p:%d,%lld ",p,tre[p].sum);
		pushdown(p,l,r);
		pushup(p);
//		printf("%lld\n",tre[p].sum);
		if(pos<=mid) update(p<<1,l,mid,pos,k);
		else update(p<<1|1,mid+1,r,pos,k);
		pushup(p);
	}
	void build(int p,int l,int r){
		if(l==r){
			tre[p].mx=tre[p].sec=-inf,tre[p].cnt=tre[p].cmx=0;tre[p].sum=0;return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p);
	}
	void add(int p,int l,int r,int L,int R,int k){
		// printf("p:%d,l:%d,r:%d,L:%d,R:%d\n",p,l,r,L,R);
		if(L>R) return ;if(!tre[p].cnt) return ;
		if(l>=L&&r<=R){
			tre[p].mx+=k,tre[p].sec+=k;tre[p].tag+=k;
			tre[p].sum+=tre[p].cnt*k;
			return ;
		}
		int mid=l+r>>1;
		pushdown(p,l,r);
		if(L<=mid) add(p<<1,l,mid,L,R,k);
		if(R>mid) add(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	void min(int p,int l,int r,int L,int R,int k){
		if(L>R) return ;
		if(tre[p].mx<=k||!tre[p].cnt) return ;
		if(l>=L&&r<=R){
			if(tre[p].cnt==tre[p].cmx){
				tre[p].admx-=tre[p].mx-k;
				tre[p].sum-=(tre[p].mx-k)*tre[p].cmx;
				tre[p].mx=k;
				return ;
			}
			else if(tre[p].sec<=k){
				tre[p].admx-=tre[p].mx-k;
				tre[p].sum-=(tre[p].mx-k)*tre[p].cmx;
				tre[p].mx=k;
				return ;
			}
			else{
				pushdown(p,l,r);
				int mid=l+r>>1;
				min(p<<1,l,mid,L,R,k);min(p<<1|1,mid+1,r,L,R,k);pushup(p);return ;
			}
		}
//		printf("p:%d,%lld ",p,tre[p].sum);
		pushdown(p,l,r);
		pushup(p);
//		printf("%lld\n",tre[p].sum);
		int mid=l+r>>1;
		if(L<=mid) min(p<<1,l,mid,L,R,k);
		if(R>mid) min(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int qcnt(int p,int l,int r,int L,int R){
		if(L>R) return 0;
		if(l>=L&&r<=R) return tre[p].cnt;
		pushdown(p,l,r);
		int mid=l+r>>1;
		int res=0;
		if(L<=mid) res+=qcnt(p<<1,l,mid,L,R);
		if(R>mid) res+=qcnt(p<<1|1,mid+1,r,L,R);
		return res;
	}
	
}T1,T2;
signed main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;T1.build(1,1,n);T2.build(1,1,n);
	
	for(int i=1;i<=n;++i){
		int p=T1.qcnt(1,1,n,1,pos[i])+1;
//		printf("p:%d\n",p);
		T1.update(1,1,n,pos[i],i+1);
//		 printf("%lld ",T1.tre[1].sum);
		T1.add(1,1,n,pos[i]+1,n,1);
//		 printf("%lld ",T1.tre[1].sum);
		// printf("p:%d\n",p);
		T1.min(1,1,n,1,pos[i]-1,p);
//		 printf("%lld ",T1.tre[1].sum);printf("\n");
		// printf("p:%d\n",p);
		T2.update(1,1,n,pos[i],0);
//		 printf("%lld ",T2.tre[1].sum);
		// printf("p:%d\n",p);
		T2.min(1,1,n,pos[i]+1,n,-p+1);
//		 printf("%lld ",T2.tre[1].sum);
		// printf("p:%d\n",p);
		T2.add(1,1,n,pos[i]+1,n,-1);
//		 printf("%lld ",T2.tre[1].sum);printf("\n");
		// printf("p:%d\n",p);
		int ans=T1.tre[1].sum+T2.tre[1].sum;
//		printf("%lld %lld\n",T1.tre[1].sum,T2.tre[1].sum);
		printf("%lld\n",ans-i);
	}
}