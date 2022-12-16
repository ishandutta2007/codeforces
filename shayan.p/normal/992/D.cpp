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

const ll inf=8e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll a[maxn],sm[maxn];
ll cnt[maxn];
ll nxt[maxn];

bool over(ll a,ll b){
    return (b>=(inf/a));
}

inline ll SUM(ll l,ll r){
    ll x=sm[r];
    ll y=(l==0?0:sm[l-1]);
    return x-y;
}

int main(){
    ll n,k;cin>>n>>k;
    REP(i,n){
	cin>>a[i];
	sm[i]=(i==0?0:sm[i-1])+a[i];
    }
    ll cn=0,lst=n;
    REPD(i,n){
	nxt[i]=lst;
	cnt[i]=cn;
	if(a[i]==1)
	    cn++;
	else
	    cn=0;
	if(a[i]!=1)
	    lst=i;
    }
    ll ans=0;
    REP(i,n){
	ll x=a[i];
	ll ind=i;
	while(true){
	    if(x%k==0){
		ll y=x/k;
		y-=SUM(i,ind);
		if(0<=y&&y<=cnt[ind])
		    ans++;
	    }

	    if(nxt[ind]==n||over(x,a[nxt[ind]]))
		break;
	    ind=nxt[ind];
	    x*=a[ind];
	}
    }
    cout<<ans;
}