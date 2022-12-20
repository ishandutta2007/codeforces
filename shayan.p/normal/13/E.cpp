// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10;

pll ans[maxn];//how many moves?// where would it be after those moves
ll a[maxn];
ll SQ;

int main(){
	ll n,m;scanf("%d%d",&n,&m);
	ll SQ=sqrt(n);
	REP(i,n)
		scanf("%d",&a[i]);
	REPD(i,n){
		if(i+a[i]>=n)
			ans[i]=MP(1,i);
		else
			ans[i]=(((i+a[i])/SQ)!=(i/SQ)?MP(ll(1),i):MP(1+ans[i+a[i]].F,ans[i+a[i]].S));
	}
		
	REP(j,m){
		ll act;scanf("%d",&act);
		ll A,B;
		if(act){
			scanf("%d",&A);A--;
			ll tot=0,lst;
			while(A<n){
				lst=A;
				tot+=ans[A].F;
				A=ans[A].S+a[ans[A].S];
			}
			printf("%d %d\n",ans[lst].S+1,tot);
		}
		else{
			scanf("%d%d",&A,&B);A--;
			a[A]=B;
			FORD(i,A,((A/SQ)*SQ)){
				if(i+a[i]>=n)
					ans[i]=MP(1,i);
				else
					ans[i]=(((i+a[i])/SQ)!=(i/SQ)?MP(ll(1),i):MP(1+ans[i+a[i]].F,ans[i+a[i]].S));
			}
		}
	}
}