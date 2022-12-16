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

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;
const ll Big=1e9+10;

#pragma GCC Optimize("Ofast")

const ll tw=131072;
ll dp[maxn],a[maxn];
ll n;

struct Segment{
    ll mx[2*tw],mn[2*tw],MN[2*tw];
    Segment(){////////////////////////////////
	fill(MN,MN+2*tw,inf);
	fill(mn,mn+2*tw,inf);
    }    
    void build(ll *arr){
	REP(i,n){
	    mn[i+tw]=mx[i+tw]=arr[i];
	}
	FORD(i,tw-1,1){
	    mx[i]=max(mx[2*i],mx[2*i+1]);
	    mn[i]=min(mn[2*i],mn[2*i+1]);
	}
    }
    ll Ls(ll f,ll x){
	ll s=2*tw-1;
	f=f+tw;
	while(f<s&&mx[f]<=x){
	    if(f%2) f++;
	    f/=2;s/=2;
	}
	while(f<tw){
	    if(mx[2*f]<=x)
		f=f*2+1;
	    else
		f=f*2;
	}
	return f-tw-1;
    }
    ll Gr(ll f,ll x){
	ll s=2*tw-1;
	f=f+tw;
	while(f<s&&mn[f]>=x){
	    if(f%2) f++;
	    f/=2;s/=2;
	}
	while(f<tw){
	    if(mn[2*f]>=x)
		f=f*2+1;
	    else
		f=f*2;
	}
	return f-tw-1;
    }
    void Add(ll ind,ll x){
	ind+=tw;
	while(ind>0){
	    MN[ind]=min(MN[ind],x);
	    ind/=2;
	}
    }
    ll Min(ll f,ll s){
	f+=tw;s+=tw+1;
	ll ans=inf;
	while(f<s){
	    if(f%2) ans=min(ans,MN[f++]);
	    if(s%2) ans=min(ans,MN[--s]);
	    f/=2;s/=2;
	}
	return ans;
    }
};
Segment A,B;

bool ok(ll ind,ll x){
    ll till=min(n-1,min(A.Ls(ind,a[ind]+x),A.Gr(ind,a[ind]-x)));
    return (ind<till&&B.Min(ind+1,till)<=x);
}

int main(){
    ll q,w;cin>>n>>q>>w;
    a[0]=q;a[1]=w;
    n+=2;
    FOR(i,2,n-1)
	cin>>a[i];
    A.build(a);

    B.Add(n-1,0);
    REPD(i,n-1){;
	ll l=abs(a[i+1]-a[i]),r=Big;
	dp[i]=l;
	while(l<=r){
	    ll mid=(l+r)/2;
	    if(ok(i,mid)){
		dp[i]=mid;
		r=mid-1;
	    }
	    else{
		l=mid+1;
	    }
	}
	B.Add(i,dp[i]);
    }
    cout<<dp[0];
}