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
ll brr[1010101];

bool sf(ll a,ll b){
	return arr[a-1]-arr[a]<arr[b-1]-arr[b];
}

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
    		brr[i]=i;
    	}

    	sort(brr+1,brr+1+n,sf);
    	for(i=1;i<=n;i++){
    		cout<<brr[i]<<'\n';
    	}

    }
}