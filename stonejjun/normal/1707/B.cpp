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
vector<ll> va;
vector<ll> vb;

bool sf(ll a,ll b){
	if(a*b==0) return a>b;
	return a<b;
}

int main(){
	ios_base::sync_with_stdio(0);
   	cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
    	va.clear();
    	vb.clear();

    	ll i,j,k,a,b,c,d,e,f;
    	cin>>n;
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    		vb.pb(arr[i]);
    	}

    	ll ans=0;
    	ll fl=0;
    	while(vb.size()!=1){
    		va=vb;
    		sort(va.begin(), va.end(),sf);
    		while(va.size()&&va[va.size()-1]==0){
    			fl++;
    			va.pop_back();
    		}
    		//cout<<va.size()<<' '<<vb.size()<<'\n';
    		vb.clear();
    		if(va.size()==0) break;
    		if(fl){
    			vb.pb(va[0]);
    			fl--;
    		}
    		for(i=1;i<va.size();i++){
    			vb.pb(va[i]-va[i-1]);
    		}
    	}

    	if(vb.size()==1){
    		cout<<vb[0]<<'\n';
    	}
    	else {
    		cout<<0<<'\n';
    	}

    }
}