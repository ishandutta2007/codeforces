#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define P 1000000007
#define N 105
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
ll vsft[N],nsft[N];
int Q,T;ll X,K;
int lev(ll x){int s=0;while((1ll<<(s+1))-1<x)++s;return s;}
int main(){
	scanf("%d",&Q);
	rep(i,Q){
		scanf("%d",&T);
		if(T==1){scanf("%lld%lld",&X,&K);int p=lev(X);K=(K+(1ll<<p))%(1ll<<p);(vsft[p]+=K)%=(1ll<<p);}
		if(T==2){scanf("%lld%lld",&X,&K);int p=lev(X);K=(K+(1ll<<p))%(1ll<<p);(nsft[p]+=K)%=(1ll<<p);}
		if(T==3){
			scanf("%lld",&X);
			int tp=lev(X);
			X=(X-(1ll<<tp)+vsft[tp]+(1ll<<tp))%(1ll<<tp)+(1ll<<tp);
			while(X>1){
				int p=lev(X);//printf("%lld %d\n",X,p);
				printf("%lld ",(X-(1ll<<p)-vsft[p]+(1ll<<p))%(1ll<<p)+(1ll<<p));
				X=(X-(1ll<<p)+nsft[p]+(1ll<<p))%(1ll<<p)+(1ll<<p);
				X=X>>1;
			}
			puts("1");
		}
	}
	return 0;
}