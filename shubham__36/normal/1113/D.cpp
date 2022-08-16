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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll n = s.size();
   	char c=s[0];
   	bool bo1=false;
   	forn(i,n/2){
   		if(s[i]!=c || s[n-1-i]!=c) bo1 = true;
   	}
   	if(!bo1) {
   		cout << "Impossible"<< ln;
    	return 0;
   	}
    forn(i,n){
    	char c[n];
    	forn(j,n) c[j]=s[(j+i)%n];
    	bool bo = false;
    	forn(j,n){
    		if(c[j]!=s[j]) bo = true;
    	}
    	if(!bo) continue;
    	forn(j,n/2){
    		if(c[j]!=c[n-1-j]) bo = false;
    	}
    	if(!bo) continue;
    	cout << 1 << ln;
    	return 0;
    }
    cout << 2 << ln;
    return 0;
}