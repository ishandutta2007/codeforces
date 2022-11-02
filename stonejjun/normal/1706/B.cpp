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
    	}
    	for(i=1;i<=n;i++){
    		ll x=arr[i];
    		if(pre[x]==0||(i-pre[x])%2){
    			pre[x]=i;
    			cnt[x]++;
    		}
    	}

    	for(i=1;i<=n;i++)
    		cout<<cnt[i]<<' ';
    	cout<<'\n';
    }
}