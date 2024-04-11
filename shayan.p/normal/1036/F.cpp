// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Big=1e9+10;
const ll inf=2e18;

int a[65],MX[65];

inline bool over(ll a,ll b){
    return (a>=(inf/b));
}

ll tavan0(ll a,int b){
    ll ans=1;
    while(true){
	if(b&1){
	    if(over(ans,a))return inf;
	    ans*=a;
	}
	b/=2;
	if(b==0)break;
	if(over(a,a))return inf;
	a*=a;
    }
    return ans;
}

ll tavan(ll a,int b){
    ll ans=1;
    while(b){
	if(b&1) ans*=a;
	a*=a;
	b/=2;
    }
    return ans;
}

int main(){
    for(int i=2;i<65;i++){
	int l=1,r=Big;
	while(l<=r){
	    int mid=(l+r)/2;
	    if(tavan0(mid,i)<inf){
		MX[i]=mid;
		l=mid+1;
	    }
	    else{
		r=mid-1;
	    }
	}
    }
    
    int t;scanf("%d",&t);
    while(t--){
	ll n;scanf("%lld",&n);
	int ans=0;
	for(int i=64;i>=2;i--){
	    int l=1,r=MX[i];
	    while(l<=r){
		int mid=(l+r)/2;
		if(tavan(mid,i)<=n){
		    a[i]=mid;
		    l=mid+1;
		}
		else{
		    r=mid-1;
		}
	    }
	    a[i]--;
	    for(int j=2*i;j<65;j+=i){
		a[i]-=a[j];
	    }
	    ans+=a[i];
	}
	ll ANS=n-1-ans;
	printf("%lld\n",ANS);
    }
}