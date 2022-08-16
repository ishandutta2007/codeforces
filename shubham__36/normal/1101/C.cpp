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
ll c = 1e6;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	multiset<p32> s;
    	multiset<int> s1;
    	ll l,r;
    	v32 ans(n,0);
    	v32 last(n,0);
    	forn(i,n){
    		cin >> l >> r;
    		s.insert(mp(r,i));
    		s1.insert(l);
    		last[i]=l;
    	}
    	ll temp=1e7,coun=0;
    	for(auto a : s){
    		s1.erase(s1.find(last[(a).se]));
    		if((a).fi < *(s1.begin())){
    			ans[(a).se]=1;
    			coun++;
    			break;
    		}
    		ans[(a).se]=1;
    		coun++;
    	}
    	if(coun == n){
    		cout << -1 << ln;
    	}
    	else{
    		forn(i,n){
    			if(ans[i]==0) cout << 2 << " ";
    			else cout << ans[i] << " ";
    		}
    		cout << ln;
    	}
    }
    return 0;
}