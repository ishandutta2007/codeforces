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
int K[20];
int minn[400010],tag[400010],pos[400010],add[400010];
int n,Q;
int a[100010];
int num[100010];
set<int>st;
void pushup(int p){
	if(minn[p<<1]<minn[p<<1|1]){
		minn[p]=minn[p<<1],pos[p]=pos[p<<1];
	}
	else{
		minn[p]=minn[p<<1|1],pos[p]=pos[p<<1|1];
	}
}
void build(int p,int l,int r){
	if(l==r){
		minn[p]=K[num[l]]-a[l];pos[p]=l;tag[p]=add[p]=0;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p); 
}
const int INF=1e18;
void pushdown(int p,int l,int r){
	if(tag[p]){
		add[p<<1]=add[p<<1|1]=0;
		tag[p<<1]=tag[p<<1|1]=tag[p];
		minn[p<<1]=minn[p<<1|1]=tag[p];
		pos[p<<1]=l,pos[p<<1|1]=l+r>>1;
		tag[p]=0;
	}
	if(add[p]){
		add[p<<1]+=add[p],add[p<<1|1]+=add[p];
		minn[p<<1]+=add[p],minn[p<<1|1]+=add[p];
		add[p]=0;
	}
}
void change(int p,int l,int r,int L,int R,int k){
	if(L>R) return ;
	if(l>=L&&r<=R){
		minn[p]=k,tag[p]=k,pos[p]=l,add[p]=0;
		return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	if(L<=mid) change(p<<1,l,mid,L,R,k);
	if(R>mid) change(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}

void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		minn[p]+=k;add[p]+=k;return ;
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
PII query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return mp(minn[p],pos[p]);
	}
	pushdown(p,l,r);
	int mid=l+r>>1;
	PII res=mp(INF+1,-1);
	if(L<=mid){
		PII tmp=query(p<<1,l,mid,L,R);
		if(tmp.fi<res.fi) res=tmp;
	}
	if(R>mid){
		PII tmp=query(p<<1|1,mid+1,r,L,R);
		if(tmp.fi<res.fi) res=tmp;
	}
	return res;
}
signed main(){
	memset(minn,0x15,sizeof(minn));
	K[0]=1;
	for(int i=1;i<=11;++i) K[i]=K[i-1]*42;
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();st.insert(i);num[i]=lower_bound(K+1,K+12,a[i])-K;
	}
	build(1,1,n);
	while(Q--){
		int op=read();
		switch(op){
			case 1:{
				int x=read();
				int pos=*st.lower_bound(x);
				int tmp=query(1,1,n,pos,pos).fi;
				printf("%lld\n",K[num[pos]]-tmp);
				break;
			}
			case 2:{
				int l=read(),r=read(),x=read();
				if(l>1){
					int t=*st.lower_bound(l-1);
					num[l-1]=num[t];change(1,1,n,l-1,l-1,query(1,1,n,t,t).fi);st.insert(l-1);
				}
				st.erase(st.lower_bound(l),st.lower_bound(r));
				st.insert(r);
				num[r]=lower_bound(K+1,K+12,x)-K;
				change(1,1,n,r,r,K[num[r]]-x);
				change(1,1,n,l,r-1,INF);
				break;
			}
			case 3:{
				int l=read(),r=read(),x=read();
				int t=*st.lower_bound(l-1);
				if(l>1){
					num[l-1]=num[t];change(1,1,n,l-1,l-1,query(1,1,n,t,t).fi);st.insert(l-1);
				}
				t=*st.lower_bound(r);
				num[r]=num[t];
				st.insert(r);
				change(1,1,n,r,r,query(1,1,n,t,t).fi);
				update(1,1,n,l,r,-x);
				int tmp=query(1,1,n,l,r).fi;
				while(tmp<=0){
					if(tmp==0){
						update(1,1,n,l,r,-x);
					}
					else{
						int pos=query(1,1,n,l,r).se;
						while(tmp<0){
							tmp+=K[num[pos]+1]-K[num[pos]];
							++num[pos];
						}
						change(1,1,n,pos,pos,tmp);
					}
					tmp=query(1,1,n,l,r).fi;
				}
				break;
			}
		}
	}
}