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
    	ll num=1;
    	bool b1=false;
    	forn(i,n) {
    		cin >> a[i];
    		if(i==0) num = a[i];
    		if(i!=0){
    			ll t1 = __gcd(a[i],num);
    			ll temp = a[i]/t1;
    			if(num > ((ll)1e13)/temp){
    				cout << -1 <<ln;
	    			b1 = true;
	    			forsn(j,i+1,n) cin >> a[i];
	    			break;
    			}
    			num *= temp; 
    		}
    	}
    	if(b1) continue;
    	sort(a,a+n);
    	if(a[n-1]==num){
    		num *= a[0];
    	}
    	ll sf = sqrt(num);
    	sf++;
    	sf++;
    	ll in=0;
    	vector<ll> v;
    	forsn(i,2,sf){
    		if(i<num && i*i<=num && num%i==0){
    			v.pb(i);
    			if(i*i!=num) v.pb(num/i);
    		}
    	}
    	if((ll)v.size()!=n) cout << -1 <<ln;
    	else cout << num << ln;
    }
    return 0;
}