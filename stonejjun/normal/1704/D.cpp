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
vector<ll> arr[1010101];
vector<ll> v[1010101];
ll lg[1010101];
ll rg[1010101];

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
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		arr[i].clear();
    		arr[i].pb(0);

    		for(j=1;j<=m;j++){
    			cin>>a;
    			arr[i].pb(a);
    		}
    		lg[i]=rg[i]=0;
    	}

    	for(i=2;i<=n;i++){
    		for(j=m;j>=2;j--){
    			if(arr[i][j]>arr[1][j]){
    				ll val=arr[i][j]-arr[1][j];
    				lg[i]+=val;
    				arr[i][j]-=val;
    				arr[i][j-1]+=val;
    			}
    			else{
    				ll val=-arr[i][j]+arr[1][j];
    				rg[i]+=val;
    				arr[i][j]+=val;
    				arr[i][j-1]-=val;
    			}
    		}
    	}

    	ll ans1,ans2;
    	for(i=2;i<=n;i++){
    		if(rg[i]>lg[i]){
    			cout<<1<<' '<<rg[i]-lg[i]<<'\n';
    			break;
    		}
    		else if(lg[i]>rg[i]){
    			cout<<i<<' '<<lg[i]-rg[i]<<'\n';
    			break;
    		}
    	}

    }
}