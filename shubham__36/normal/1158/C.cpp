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
    ll t;
    cin >> t;
    while(t>0){
    	t--;
    	ll n;
    	cin >> n;
    	ll a[n];
    	ll ans[n];
    	set<p64> s;
    	vector<ll> v;
    	bool bo=false;
    	forn(i,n) {
    		if((ll)v.size()!=0 && v[(ll)v.size()-1]==i+1){
    			v.pop_back();
    		}
    		cin >> a[i];
    		if(a[i]==-1){
    			s.insert(mp(i+2,-1*i));
    		}
    		else{
    			s.insert(mp(a[i],-1*i));
    			if((ll)v.size()==0 || v[(ll)v.size()-1]>a[i]){
    				v.pb(a[i]);
    			}
    			else if(v[(ll)v.size()-1]<a[i]) {
    				bo=true;
    			}
    		}
    	}
    	if(bo){
    		cout << -1 << ln;
    		continue;
    	}
    	ll in = 1;
    	for(auto it:s){
    		ll index = -1*it.se;
    		ans[index]=in;
    		in++;
    	}
    	forn(i,n) cout << ans[i] << " ";
    	cout << ln;
    }
    return 0;
}