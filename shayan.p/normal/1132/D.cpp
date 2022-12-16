// Wanna Hack? GL...

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

const int maxn=2e5+10;
const ll Big=1e18,inf=2e18;

ll a[maxn],b[maxn];
int val[maxn],n,k;

bool check(ll z){
    int cnt=0;
    for(int i=0;i<n;i++){
	for(int j=0;;j++){
	    if(j>(inf/z)) break;
	    ll t=((1ll*j*z+a[i])/b[i])+1;
	    if(t>=k) break;
	    if((++cnt)>=k) return 0;
	    val[t]++;
	}
    }
    int sm=0;
    for(int i=0;i<k;i++){
	sm+=val[i];
	if(sm>i) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	cin>>b[i];
    }
    bool ok=1;
    for(int i=0;i<n;i++){
	ok&=(1ll*a[i]>=1ll*b[i]*(k-1));
    }
    if(ok) return cout<<0<<endl,0;
    ll l=1,r=Big,ans=-1;
    while(l<=r){
	ll mid=(l+r)>>1;
	memset(val,0,sizeof val);
	if(check(mid)) ans=mid,r=mid-1;
	else l=mid+1;
    }
    return cout<<ans<<endl,0;
}