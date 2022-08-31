#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
int a[1000005];

ll mpow(ll a,ll b){
	if(b==0) return 1;
	ll k = mpow(a,b/2);
	k = k*k;
	k%=MOD;
	if(b%2!=0) {
		k*=a;
		k%=MOD;
	} 
	return k;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll c = mpow(2,MOD-1-k);
    ll t = sqrt(n);
    if(t*t<n) t++;
    if(t*t<n) t++;
    ll ans=1;
    forn(i,t+1){
    	if(i==0 || i==1) continue;
    	int co=0;
    	while(n%i==0) {co++; n/=i;}
    	if(co==1) {ans *= ((i-1)*(c)+1)%MOD; ans%=MOD;}
    	else if(co>1){
    		v64 v;
    		forn(pa,co+1){
    			v.pb(mpow(i,pa));
    		}
    		// cout << v[0] << " " << v[1] << " " << v[2]<< ln;
    		forn(j,k){
    			ll sum=0;
    			forn(i,co+1){
	    			sum+=v[i];
	    			sum%=MOD;
	    			ll t1=mpow(i+1,MOD-2);
	    			v[i]=sum*t1;
	    			v[i]%=MOD;
	    		}
	    		// cout << v[0] << " " << v[1] << " " << v[2]<< ln;
    		}
    		ans *= v[co]; ans%=MOD;
    	}
    	if(n==1) break;
    }
    if(n!=1){
    	ans *= (((n-1)%MOD)*(c)+1)%MOD; ans%=MOD;
    }
    cout << ans;
    return 0;
}