#include <bits/stdc++.h>
#include <iomanip>
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
ll MOD = 1e9 + 7;
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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    // cin >> t;
    t=1;
    forn(k,t){
    	ll n;
    	cin >> n;
    	ll a[n];
    	forn(i,n) cin >> a[i];
    	sort(a,a+n);
    	m64 m;
    	m64 change,sum;
    	forn(i,n-1){
    		ll temp = a[i+1]-a[i];
    		if(m.find(temp)!=m.end()) m[temp]++;
    		else m[temp]=1;
    	} 
    	ll prev_sum=0,ch=n;
    	ll temp=0;    	
    	change[0]=n;
    	sum[0]=0;
    	for(auto i : m){
    		prev_sum += ch*(i.fi-temp);
    		ch -= i.se;
    		change[i.fi]=ch;
    		sum[i.fi] = prev_sum;
    		temp = i.fi;
    	}
    	ll q;
    	cin >> q;
    	forn(i,q){
    		ll a,b;
    		cin >> a >> b;
    		auto it = sum.upper_bound(b-a);
    		it--;
    		ll t1 = it->fi;
    		ll t2 = it->se;
    		it = change.upper_bound(b-a);
    		it--;
    		ll t3 = it->se;
    		cout << t2 + (b-a+1-t1)*t3 << " "; 
    	}
    	cout << ln;
    }
    return 0;
}