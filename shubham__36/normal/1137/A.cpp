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
#define INF LLONG_MAX/2

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll a[n][m],rm[n],cm[m],r[n][m],c[n][m];
    forn(i,n){
    	forn(j,m){
    		cin >> a[i][j];
    	}
    }
    forn(i,n){
    	set<ll> s;
    	forn(j,m){
    		s.insert(a[i][j]);
    	}
    	rm[i]=s.size();
    	m32 mm;
    	ll temp=1;
    	for(auto y : s){
    		mm[y]=temp;
    		temp++;
    	}
    	forn(j,m){
    		r[i][j]=mm[a[i][j]];
    	}
    }
    forn(i,m){
    	set<ll> s;
    	forn(j,n){
    		s.insert(a[j][i]);
    	}
    	cm[i]=s.size();
    	m32 mm;
    	ll temp=1;
    	for(auto y : s){
    		mm[y]=temp;
    		temp++;
    	}
    	forn(j,n){
    		c[j][i]=mm[a[j][i]];
    	}
    }
    forn(i,n){
    	forn(j,m){
    		if(r[i][j]==c[i][j]){
    			cout << max(rm[i],cm[j]) << " ";
    		}
    		else if(r[i][j]>c[i][j]){
    			cout << max(rm[i],cm[j]+r[i][j]-c[i][j]) << " ";
    		}
    		else{
    			cout << max(rm[i]-r[i][j]+c[i][j],cm[j]) << " ";
    		}
    	}
    	cout << ln;
    }
    return 0;
}