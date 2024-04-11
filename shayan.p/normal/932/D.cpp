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

#define bit(num,i) ((num>>i)&1)

#define bug(i) cerr<<i<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=4e5+10;
const ll LG=20;

#pragma GCC Optimize("Ofast")

ll nxt[maxn][LG+5];
ll sm[maxn][LG+5];
ll w[maxn];
ll t=1;

void q1(ll r,ll W){
	w[++t]=W;
	ll nx=r;
	if(w[r]>=W){
		nxt[t][0]=r;
	}
	else{
		FORD(i,LG,0){
			if(nxt[nx][i]!=0&&w[nxt[nx][i]]<W){
				nx=nxt[nx][i];
			}
		}
		nx=nxt[nx][0];
		nxt[t][0]=nx;
	}
	sm[t][0]=w[nx];
	FOR(i,1,LG){
		nxt[t][i]=nxt[nxt[t][i-1]][i-1];
		sm[t][i]=sm[t][i-1]+sm[nxt[t][i-1]][i-1];
	}
}


ll q2(ll r,ll x){
	if(r>t)return 0;
	if(w[r]>x)return 0;
	ll ans=1;
	x-=w[r];
	FORD(i,LG,0){
		if(nxt[r][i]!=0&&sm[r][i]<=x){
			ans+=(1<<i);
			x-=sm[r][i];
			r=nxt[r][i];
		}
	}
	return ans;
}

int main(){
	ll q,lst=0;scanf("%lld",&q);
	REP(i,q){
		ll act,p,q;scanf("%lld%lld%lld",&act,&p,&q);
		p^=lst;q^=lst;
		if(act==1){
			q1(p,q);
		}
		if(act==2){
			lst=q2(p,q);
			printf("%lld\n",lst);
		}
	}
}