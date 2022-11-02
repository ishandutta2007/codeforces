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
ll ans[1010101];

void sol(ll fl){
	ll i;
    ll iq=m;
	for(i=1;i<=n-fl;i++){
    	if(i>n) break;
		if(arr[i]<=iq){
			fl--;
			ans[i]=1;
		}
		else ans[i]=0;
	}
	for(i=n-fl+1;i<=n;i++){
		ans[i]=1;
		if(arr[i]>iq){
			iq--;
		}
	}
	return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
    	ll i,j,k,a,b,c,d,e,f;
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    	}

    	ll lo=0,hi=n+1;
    	ll fians=0;
    	while(lo<hi){
    		ll mid=(lo+hi)/2;
    		ll fl=mid;
    		ll iq=m;
    		ll chk=0;
    		for(i=1;i<=n-fl;i++){
    			if(i>n) break;
    			if(arr[i]<=iq){
    				fl--;
    			}

    		}
    		for(i=n-fl+1;i<=n;i++){
				if(arr[i]>iq){
					iq--;
				}
    		}
    		if(iq>=0){
    			fians=max(fians,mid);
    			lo=mid+1;
    		}
    		else{
    			hi=mid;
    		}
    	}
    	//cout<<fians<<'\n';
    	sol(fians);
    	for(i=1;i<=n;i++)
    		cout<<ans[i];
    	cout<<'\n';

    }


}