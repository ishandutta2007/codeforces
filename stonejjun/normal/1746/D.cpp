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
vector<ll> chd[1010101];
ll pre[1010101];
ll suf[1010101];
ll brr[1010101];
ll dep[1010101];
ll vis[1010101];
ll flw[1010101];
ll dp[1010101];
ll par[1010101];

bool sf(ll a,ll b){
	return dep[a]>dep[b];
}

bool sf2(ll a,ll b){
	return dp[a]>dp[b];
}

void dfs(ll x){
	for(auto k:v[x]){
		dep[k]=dep[x]+1;
		dfs(k);
	}
}
ll ans=0;

ll sol(ll x,ll mn,ll mx){
    //cout<<x<<' '<<mn<<' '<<mx<<'\n';
    ans+=mn*arr[x];
    if(chd[x].size()==0){
        return arr[x];
    }
    ll sz=chd[x].size();
    ll mnxt=(mn)/sz;
    ll mxxt=(mx+sz-1)/sz;
    vector<ll> lst;
    for(auto k:chd[x]){
        ll val=sol(k,mnxt,mxxt);
        lst.pb(val);
    }
    sort(lst.begin(), lst.end());
    reverse(lst.begin(), lst.end());
    for(ll i=0;i<mn%sz;i++){
        ans+=lst[i];
    }
    return lst[(mx+sz-1)%sz]+arr[x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
    	ll a,b,c,d,i,j,k,p,q;
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		par[i]=0;
    		v[i].clear();
    		chd[i].clear();
    		brr[i]=i;
    		dep[i]=0;
    		dp[i]=0;
    		flw[i]=0;

    	}
    	for(i=2;i<=n;i++){
    		cin>>par[i];
    		chd[par[i]].pb(i);
    		v[par[i]].pb(i);
    		//cout<<par[i]<<' '<<i<<'\n';
    	}
    	for(i=1;i<=n;i++){
    		cin>>arr[i];
    		//cout<<i<<' '<<chd[i].size()<<'\n';
    	}

    	ans=0;
    	sol(1,m,m);

    	cout<<ans<<'\n';

    }
}