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

const int maxn=2010,mod=1e9+7;
const ll inf=1e18;

map<ll,ll>mp;
ll a[maxn],b[maxn],sma[maxn],smb[maxn];
int n,m;

int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	cin>>a[i];
	sma[i]=sma[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
	cin>>b[i];
	smb[i]=smb[i-1]+b[i];
    }
    ll x;cin>>x;
    for(int i=0;i<n;i++){
	for(int j=i+1;j<=n;j++){
	    mp[sma[j]-sma[i]]=max(mp[sma[j]-sma[i]],ll(j-i));
	}
    }
    ll mx=0;
    for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++){
	mx=max(mx,it->S);
	it->S=mx;
    }
    ll ans=0;
    for(int i=0;i<m;i++){
	for(int j=i+1;j<=m;j++){
	    int A=smb[j]-smb[i];
	    auto it=mp.upper_bound(x/A);
	    if(it!=mp.begin()){
		ans=max(ans,1ll*(j-i)*((--it)->S));
	    }
	}
    }
    cout<<ans;
}