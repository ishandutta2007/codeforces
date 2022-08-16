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
    ll n;
    cin >> n;
    ll c = 100005;
    ll v[n];
    ll a[c];
    forn(i,c){
    	a[i]=0;
    }
    multiset<ll> s;
    forn(i,n){
    	ll temp;
    	cin >> temp;
    	v[i]=temp;
    	a[temp]++;
    }
    forn(i,c){
    	if(a[i]!=0) s.insert(a[i]);
    }
    ll ans = n;
    forn(i,n){
    	if((ll)s.size()==1){
    		cout << ans << ln;
    		return 0;
    	}
    	multiset<ll>::iterator it = s.begin();
    	ll fi = *it;
    	it++;
    	ll se = *it;
    	it = s.end();
    	it--;
    	ll la = *it;
    	it--;
    	ll sla = *it;
    	if((la-1==sla && fi == sla)|| (se == la && fi==1)){
    		cout << ans << ln;
    		return 0;
    	}
    	s.erase(s.find(a[v[n-1-i]]));
    	a[v[n-1-i]]--;
    	if(a[v[n-1-i]]!=0) s.insert(a[v[n-1-i]]);
    	ans--;
    }
    return 0;
}