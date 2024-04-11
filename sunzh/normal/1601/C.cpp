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
int Tm;
int n,m;
int a[1000010],b[1000010],c[1000010];
struct BIT{
	int tre[1000010];
	void add(int x){
		while(x) tre[x]++,x-=x&-x;
	}
	int query(int x){
		int res=0;
		while(x<=n){
			res+=tre[x];x+=x&-x;
		}
		return res;
	}
}T;
vector<int>vec[1000010];
int mn[4000010],tag[4000010],pos[4000010];
void pushup(int p){
	if(mn[p<<1]<=mn[p<<1|1]) mn[p]=mn[p<<1],pos[p]=pos[p<<1];
	else mn[p]=mn[p<<1|1],pos[p]=pos[p<<1|1];
	// mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
void build(int p,int l,int r){
	tag[p]=0;
	if(l==r){
		mn[p]=l;pos[p]=l;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	pushup(p);
}
void pushdown(int p){
	if(tag[p]){
		tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];
		mn[p<<1]+=tag[p],mn[p<<1|1]+=tag[p];
		tag[p]=0;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		tag[p]+=k;mn[p]+=k;
		return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
PII query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mp(mn[p],pos[p]);
	int mid=l+r>>1;
	pushdown(p);
	PII res=mp(0x3f3f3f3f,0);
	if(L<=mid) res=min(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=min(res,query(p<<1|1,mid+1,r,L,R));
	return res;
}
int main(){
	Tm=read();
	while(Tm--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) c[i]=a[i]=read();
		for(int i=1;i<=m;++i) b[i]=read();
		sort(b+1,b+m+1);
		long long ans=0;
		sort(c+1,c+n+1);
		int M=unique(c+1,c+n+1)-c-1;
		for(int i=1;i<=M;++i) vector<int>().swap(vec[i]);
		// for(int i=1;i<=n;++i) printf("%d ",T.tre[i]);
		for(int i=1;i<=n;++i){
			int p=lower_bound(c+1,c+M+1,a[i])-c;
			ans+=T.query(p+1);T.add(p);vec[p].pb(i);
		}
		for(int i=1;i<=n;++i) T.tre[i]=0;
		build(1,0,n);
		int ls=0;
		int it=0;bool fl=0;
		// printf("%lld\n",ans);
		for(int i=1;i<=m;++i){
			while(it<M&&c[it+1]<b[i]){
				++it;
				for(int j:vec[it]){
					if(!fl) update(1,0,n,j,n,-1);
					update(1,0,n,0,j-1,1);
				}fl=0;
			}
			if(it!=M&&c[it+1]==b[i]&&!fl){
				fl=1;
				for(int j:vec[it+1]){
					update(1,0,n,j,n,-1);
				}
			}
			PII t=query(1,0,n,ls,n);
			// printf("i:%d,t:%d,%d\n",i,t.fi,t.se);
			ans+=t.fi;ls=t.se;
		}
		printf("%lld\n",ans);
	}
}