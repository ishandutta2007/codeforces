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

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll a[n];
    ll l,r,sum=0;
    forn(i,n) {
    	cin >> a[i];
    	sum+=a[i];
    }
    ll lim = 4e5+5;
    vv64 b(lim);
    forn(i,m){
    	ll t1,t2;
    	cin >> t1 >> t2;
    	b[t1-1].pb(t2-1);
    }
    l = sum;
    r = 2*l;
    ll last[n];
    forn(i,n) last[i]=-1;
    set<p64> s;
    while(l!=r){
    	ll t1 = 0;
    	ll mid=(l+r)/2;
    	forn(i,mid){
    		forn(j,(ll)b[i].size()){
    			last[b[i][j]]=i+1;
    		}
    	}
    	forn(i,n){
    		if(last[i]!=-1) s.insert(mp(last[i],i));
    	}
    	for(auto it:s){
    		ll index = it.se,quan=it.fi;
    		ll n1 = min(a[index],quan-t1);
    		t1 += n1;
    	}
    	// cout << t1 << ln;
    	if(t1+(sum-t1)*2<=mid){
    		r = mid;
    	}
    	else{
    		l = mid+1;
    	}
    	forn(i,n) last[i]=-1;
    	set<p64>().swap(s);
    	// cout << mid << ln;
    }
    cout << l << ln;
    return 0;
}