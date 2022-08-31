#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

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
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 998244353;
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
#define INF LLONG_MAX

ll n,m;

ll f(ll a, ll b, ll c){
	if(c==0){
		if(a==b) return 0;
		else return 1;
	} 
	if(a==-1 && b==-1){
		ll ans=1;
		forn(i,c){
			if(i==0) ans *= m;
			else ans *= (m-1);
			ans %= MOD;
		}
		return ans;
	}
	else if(a==-1 || b==-1){
		ll ans=1;
		forn(i,c){
			ans *= (m-1);
			ans %= MOD;
		}
		return ans;
	}
	else if(a==b){
		ll pa=1,pb=0,a,b;
		forn(i,c){
			a = pb;
			b = pa*(m-1)+pb*(m-2);
			pa = a;
			pb = b;
			pa %= MOD;
			pb %= MOD;
		}
		return pb;
	}
	else{
		ll pa=0,pb=1,a,b;
		forn(i,c){
			a = pb;
			b = pa*(m-1)+pb*(m-2);
			pa = a;
			pb = b;
			pa %= MOD;
			pb %= MOD;
		}
		return pb;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll a[n];
    ll ans=1;
    forn(i,n) cin >> a[i];
    ll temp = -1;
    ll count = 0;
    forn(i,(n+1)/2){
    	if(a[2*i]!=-1){
    		ans *= f(temp,a[2*i],count);
    		// cout << f(temp,a[2*i],count) << ln;
    		ans %= MOD;
    		count = 0;
    		temp = a[2*i];
    	}
    	else{
    		count++;
    	}
    }
    if(count!=0){
    	ans *= f(temp,-1,count);
    	ans %= MOD;
    	count = 0;
    }
    temp = -1;
    forn(i,n/2){
    	if(a[2*i+1]!=-1){
    		ans *= f(temp,a[2*i+1],count);
    		ans %= MOD;
    		count = 0;
    		temp = a[2*i+1];
    	}
    	else{
    		count++;
    	}
    }
    if(count!=0){
    	ans *= f(temp,-1,count);
    	// cout << f(temp,-1,count) << ln;
    	// cout << ((ll)40000000000)%MOD << ln;
    	ans %= MOD;
    	count = 0;
    }
    cout << ans << ln;
    // cout << ((ll)199999*(ll)70225880)%MOD << ln;
    return 0;
}