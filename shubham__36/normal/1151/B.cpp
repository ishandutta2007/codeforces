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
    ll n,m;
    cin >> n >> m;
    ll a[n][m];
    bool bo = false;
    ll v;
    forn(i,n){
    	ll temp=-1;
    	forn(j,m){
    		cin >> a[i][j];
    		if(temp==-1) temp=a[i][j];
    		if(!bo && temp!=a[i][j]) {
    			bo=true;
    			v = i;
    		}
    	}
    }
    if(bo){
    	cout << "TAK" << ln;
    	forn(i,v) cout << 1 << " ";
    	ll temp=0;
    	forn(i,v) temp ^= a[i][0];
    	forsn(i,v+1,n) temp ^= a[i][0];
    	// cout << temp;
    	forn(j,m){
    		if(a[v][j]!=temp) 
    			{
    				cout << j+1 << " ";
    				// cout << a[v][j] << ln;
    				break;
    			}
    	}
    	forsn(i,v+1,n) cout << 1 << " ";
    	cout << ln;
    }
    if(!bo){
    	ll temp=0;
    	forn(i,n) temp ^= a[i][0];
    	if(temp==0){
    		cout << "NIE" << ln;
    	}
    	else{
    		cout << "TAK" << ln;
    		forn(i,n) cout << 1 << " ";
    	}
    }
    return 0;
}