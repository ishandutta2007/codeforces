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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    char c;
    ll a=0,b=0;
    forn(i,n){
    	cin >> c;
    	if(c=='+'){
    		ll n1,n2;
    		cin >> n1 >> n2;
    		if(n1<n2) swap(n1,n2);
    		a=max(a,n1);
    		b=max(b,n2);
    	}
    	else{
    		ll n1,n2;
    		cin >> n1 >> n2;
    		if(n1<n2) swap(n1,n2);
    		if(a<=n1 && b<=n2){
    			cout << "YES" << ln;
    		}
    		else{
    			cout << "NO" << ln;
    		}
    	}
    }
    return 0;
}