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
const int mod=998244353;
int n,k;
int a[100010];
PII ls[100010];
int dp[100010];
const int B=350;
int cnt;
int bel[100010];
void Add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
struct block{
	int l,r,add;
	int cnt[B+10],sum[B+B+10],val[B+10];
	void update(int L,int R,int w){
		if(L>R) return ;
		L=max(L,l),R=min(r,R);
		if(L>R) return ;
		if(L==l&&R==r){
			add+=w;
		}
		else {
			memset(sum,0,sizeof(sum));
			for(int i=L-l+1;i<=R-l+1;++i) cnt[i]+=w;
			for(int i=1;i<=r-l+1;++i) Add(sum[cnt[i]+B],val[i]);
			for(int i=1;i<B+B+1;++i) Add(sum[i],sum[i-1]);
		}
	}
	int query(){
		int lim=min(B,k-add);
		// printf("lim:%d\n",lim);
		return lim<=-B?0:sum[lim+B];
	}
	void upd(int x,int k){
		Add(val[x],k);for(int i=cnt[x]+B;i<B+B+1;++i) Add(sum[i],k);
	}
}b[B];
void upd(int x,int k){
	b[bel[x]].upd(x-b[bel[x]].l+1,k);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=0;i<=n;i+=B){
		++cnt;b[cnt].l=i;
		for(int j=0;j<B&&i+j<=n;++j) bel[i+j]=cnt,b[cnt].r=i+j;
	}
	upd(0,1);
	for(int i=1;i<=n;++i){
		for(int j=bel[ls[a[i]].se];j<=bel[ls[a[i]].fi-1];++j) b[j].update(ls[a[i]].se,ls[a[i]].fi-1,-1);
		ls[a[i]].se=ls[a[i]].fi,ls[a[i]].fi=i;
		for(int j=bel[ls[a[i]].se];j<=bel[ls[a[i]].fi-1];++j) b[j].update(ls[a[i]].se,ls[a[i]].fi-1,1);
		// ins(ls[a[i]].se,ls[a[i]].fi-1);
		for(int j=1;j<=bel[i];++j) Add(dp[i],b[j].query());
		upd(i,dp[i]);
	}
	printf("%d\n",(dp[n]+mod)%mod);
}