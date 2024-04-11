#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss second
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=998244353;
string s;
ll arr[1010101];
ll cnt[1010101];
ll pre[1010101];
ll suf[1010101];
vector<ll> v[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    
    cin>>t;
    while(t--){
    	cin>>n;
   		ll i,j,k,a,b,c,d,e,f;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    		pre[i]=0;
    		cnt[i]=0;
    		suf[i]=0;
    	}
    	for(i=0;i<=n+10;i++){
    		pre[i]=0;
    		suf[i]=0;
    		cnt[i]=0;
    	}
    	ll ans=1e18;
    	if(n%2){
    		ans=0;
    		for(i=2;i<=n;i+=2){
    			ll be=max(arr[i-1],arr[i+1])+1;
    			ans+=max(arr[i],be)-arr[i];
    		}
    	}
    	else{
    		ll a1=0,a2=0;
    		for(i=2;i<n;i++){
    			ll be=max(arr[i-1],arr[i+1])+1;
    			cnt[i]=max(arr[i],be)-arr[i];
    		}
    		for(i=2;i<=n;i+=2){
    			pre[i+1]=pre[i]=pre[i-2]+cnt[i];
    			//cout<<i<<' '<<pre[i]<<'\n';
    		}
    		for(i=n-1;i>=1;i-=2){
    			suf[i-1]=suf[i]=suf[i+2]+cnt[i];
    			//cout<<i<<' '<<suf[i]<<'\n';
    		}

    		for(i=1;i<n;i++){
    			ans=min(ans,pre[i]+suf[i+1]);
    		}
    	}

    	cout<<ans<<'\n';
    }
}