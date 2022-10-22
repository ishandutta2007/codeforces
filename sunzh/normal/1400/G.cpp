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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
PII a[300010];
const int mod=998244353;
int fac[300010],ifac[300010];
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
void uad(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
struct BIT{
	int sum[300010];
	void update(int x,int k){
//		printf("x:%d,k:%d\n",x,k);
		while(x<=n){
			uad(sum[x],k);
			x+=x&-x;
		}
	}
	int query(int x){
		int res=0;
		while(x){
			uad(res,sum[x]);
			x-=x&-x;
		}
		return res;
	}
	int qry(int l,int r){
		return (query(r)-query(l-1)+mod)%mod;
	}
}tre[42];
struct segmen{
	int tag[1200010];
	void update(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R){
			++tag[p];return ;
		}
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R);
		if(R>mid) update(p<<1|1,mid+1,r,L,R);
	}
	int query(int p,int l,int r,int pos,int k){
		if(l==r) return k+tag[p];
		int mid=l+r>>1;
		if(pos<=mid) return query(p<<1,l,mid,pos,k+tag[p]);
		else return query(p<<1|1,mid+1,r,pos,k+tag[p]);
	} 
}T;
int C(int x,int y){
	if(x<0||y<0) return 0;
	if(x<y) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod; 
}
PII e[22];
int main(){
	n=read(),m=read();
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);
	for(int i=n-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i) {
		int l=read(),r=read();
		T.update(1,1,n,l,r);a[i]=mp(l,r);
	}
	for(int i=1;i<=n;++i){
		int s=T.query(1,1,n,i,0);
//		printf("i:%d,s:%d\n",i,s);
		for(int j=0;j<=40;++j){
			tre[j].update(i,C(s-j,i-j));
		}
	}
	for(int i=1;i<=m;++i){
		e[i].fi=read(),e[i].se=read();
	}
	int ans=0;
	for(int i=0;i<(1<<m);++i){
		PII seq=mp(1,n);
		set<int>st;
		int k=1;
		for(int j=1;j<=m;++j){
			if(i&(1<<j-1)){
				st.insert(e[j].fi);st.insert(e[j].se);k=~k+1;
			}
		}
		for(int j:st) seq.fi=max(seq.fi,a[j].fi),seq.se=min(seq.se,a[j].se);
		if(seq.fi<=seq.se){
//			printf("%d %d k:%d,i:%d\n",seq.fi,seq.se,k,i);
			uad(ans,(k==-1?mod-tre[st.size()].qry(seq.fi,seq.se):tre[st.size()].qry(seq.fi,seq.se)));
		}
	}
	printf("%d\n",ans);
}