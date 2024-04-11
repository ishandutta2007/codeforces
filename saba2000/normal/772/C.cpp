#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((ll)(1e15+100))
#define ARRS ((ll)(1e6+100))
#define MOD ((ll)(1e9+7))
#define EP ((double)(1e-9))
#define EPS ((double)(1e-8))
#define pb push_back
#define PI ((double)3.141592653)


ll n,m,k,p;
ll a[ARRS];
ll d[ARRS];
ll f[ARRS];
pair<ll,ll> dp[ARRS];
vector<ll> v[ARRS];
vector<ll>g;
vector<ll>pas;


void gcd1(ll a, ll b, ll *x, ll *y)
{
    if (a == 0){
        *x = 0, *y = 1;
        return;
    }
    ll x1, y1;
    gcd1(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
}
ll inv(ll a, ll m)
{
    ll x, y;
    gcd1(a, m, &x, &y);
    ll res = (x%m + m) % m;
    return res;
}
ll go(ll a, ll b, ll m){
		if(b%m==0)return 0;
    ll g = __gcd(a,m);
    a/=g;
    b/=g;
    m/=g;
    return inv(a,m) * b % m;
}

int main(){
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for(ll i=0; i<n; i++){
		cin>>a[i];
		f[a[i]]=1;
		d[__gcd(a[i],m)]--;
	}
	for(ll i=0; i<m; i++)
		d[__gcd(i,m)]++;
	//for(int i=0; i<=m; i++)
		//cout<<d[i]<<endl;

	dp[1]={d[1],-1};
	for(ll i=2; i<=m; i++){
		if(__gcd(i,m)!=i)continue;
		for(ll j=1; j*j<=i; j++){
			ll k=j;
			if(__gcd(k,m)!=k)continue;
			if(i%k==0)
				dp[i]=max(dp[i],{dp[k].fr+d[i],k});

			k=i/j;
			if(__gcd(k,m)!=k)continue;
			if(k==i)continue;
			if(i%k==0)
				dp[i]=max(dp[i],{dp[k].fr+d[i],k});
		}
	}

	ll k=m;
	while(k!=-1){
		g.pb(k);
		k=dp[k].sc;
	}

	for(ll i=0; i<m; i++){
		if(!f[i])
			v[__gcd(i,m)].pb(i);
	}

	reverse(g.begin(),g.end());
	k=1; 
	ll t=1;
	for(auto x:g){
//		cout<<x<<" "<<v[x].size()<<endl;
		for(auto y:v[x]){
			pas.pb(go(k,y,m));
			k*=pas[pas.size()-1];
			k%=m;
		}
	}
	cout<<pas.size()<<endl;
	for(auto x:pas)
		cout<<x<<" ";
	//cout<<endl;
	//k=1;
	//for(auto x:pas)
		//k*=x,k%=m,cout<<k<<" ";
}