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
string t;
ll arr[1010101];
vector<ll> v[1010101];

bool sf(ll a,ll b){
	return a>b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt;
    cin>>tt;
    while(tt--){
    	x.clear();
    	ll i,j,k,l,a,b,c;
    	cin>>m>>n;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    	}

    	sort(arr+1,arr+1+n);
    	for(i=2;i<=n;i++){
    		x.pb(arr[i]-arr[i-1]-1);
    	}
    	x.pb(arr[1]-arr[n]+m-1);

    	ll ans=0;
    	ll fl=1;

    	sort(x.begin(), x.end(),sf);
    	for(auto k:x){
    		//cout<<k<<' '<<fl<<'\n';
    		ll mx=max(0LL,k-fl);
    		if(k==fl) ans++;
    		else ans+=mx;
    		fl+=4;
    	}

    	cout<<m-ans<<'\n';
    }
}