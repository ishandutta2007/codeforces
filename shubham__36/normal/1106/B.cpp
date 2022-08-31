#include <bits/stdc++.h>
#include <iomanip> 
#include <set>
#include <queue>
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


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll a[n],c[n];
    set<p64 > s;
    forn(i,n){
    	cin >> a[i];
    }
    forn(i,n){
    	cin >> c[i];
    	s.insert(mp(c[i],i));
    }
    forn(i,m){
    	ll t,d;
    	cin >> t >> d;
    	ll ans = min(a[t-1],d)*c[t-1];
    	if(d<=a[t-1]){
    		a[t-1]-=d;
    		cout << ans << ln;
    	}
    	else{
    		d-=a[t-1];
    		a[t-1]=0;
    		while(s.size() && d){
    			ll temp2 = (*(s.begin())).se;
    			if(d>=a[temp2]){
    				ans+=a[temp2]*c[temp2];
    				s.erase(*(s.begin()));
    				d-=a[temp2];
    				a[temp2]=0;
    			}
    			else{
    				ans+=d*c[temp2];
    				a[temp2]-=d;
    				d=0;
    			}
    		}
    		if(!d) cout << ans << ln;
    		else cout << 0 << ln;
    	}
    }
    return 0;
}