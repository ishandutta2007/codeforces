// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O1")
#pragma GCC Optimize("O2")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O4")
#pragma GCC Optimize("O5")

const ll Big=262144;

ll a[maxn],n;
ll smx[maxn],smr[maxn];
    
ll solve(ll l,ll r){
    if(l==r)return 0;
    ll mid=(l+r)/2;
    ll ans=solve(l,mid)+solve(mid+1,r);

    FOR(i,mid+1,r){
	smx[i]=max((i==(mid+1)?0:smx[i-1]),a[i]);
	smr[i]=((i==(mid+1)?0:smr[i-1])|a[i]);
    }
    FORD(i,mid,l){
	smx[i]=max((i==(mid)?0:smx[i+1]),a[i]);
	smr[i]=((i==(mid)?0:smr[i+1])|a[i]);
    }
    
    ll MX=0,OR=0;
    FOR(i,mid+1,r){
	MX=max(MX,a[i]);
	OR=OR|a[i];
	ll L=l,R=mid,idmx=mid+1,idor=l-1;
	while(L<=R){
	    ll md=(L+R)/2;
	    if((smr[md]|OR)>MX){
		idor=md;
		L=md+1;
	    }
	    else{
		R=md-1;
	    }
	}
	L=l;R=mid;
	while(L<=R){
	    ll md=(L+R)/2;
	    if(smx[md]<=MX){
		idmx=md;
		R=md-1;
	    }
	    else{
		L=md+1;
	    }
	}
	ans+=max(idor-idmx+1,ll(0));
    }

    MX=0;OR=0;
    FORD(i,mid,l){
	MX=max(MX,a[i]);
	OR=OR|a[i];
	ll L=mid+1,R=r,idmx=mid,idor=r+1;
	while(L<=R){
	    ll md=(L+R)/2;
	    if((OR|smr[md])>MX){
		idor=md;
		R=md-1;
	    }
	    else{
		L=md+1;
	    }
	}
	L=mid+1;R=r;
	while(L<=R){
	    ll md=(L+R)/2;
	    if(smx[md]<MX){
		idmx=md;
		L=md+1;
	    }
	    else{
		R=md-1;
	    }
	}
	ans+=max(idmx-idor+1,ll(0));
    }
    return ans;
}

int main(){
    scanf("%lld",&n);
    ll mx=0;
    REP(i,n){
	scanf("%lld",&a[i]);
	mx=max(mx,a[i]);
    }
    printf("%lld",solve(0,n-1));
}