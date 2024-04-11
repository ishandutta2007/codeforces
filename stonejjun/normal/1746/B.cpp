#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double dl;
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
string t;
ll arr[1010101];
vector<ll> v[1010101];
ll pre[1010101];
ll suf[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
    	ll a,b,c,d,i,j,k,p,q;
    	cin>>n;
    	ll fl=0;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    	}
    	ll ans=1e18;
    	for(i=0;i<=n+10;i++)
    		pre[i]=suf[i]=0;
    	for(i=1;i<=n;i++){
    		pre[i]=pre[i-1]+arr[i];
    	}
    	for(i=n;i>=1;i--){
    		suf[i]=suf[i+1]+1-arr[i];
    	}
    	for(i=0;i<=n;i++){
    		ans=min(ans,max(pre[i],suf[i+1]));
    		//cout<<i<<' '<<pre[i]<<' '<<suf[i+1]<<'\n';
    	}
    	cout<<ans<<'\n';

    }
}