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
// string s,p;
// ll t,n,m,ans,a,b1,c,c1;
// vv64 g;
// v32 vis;
// bool b;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    int a[n+1],ai[n],b[n+1];
    forn(i,n+1) a[i]=0,b[i]=i;
    set<int> s;
    forn(i,n){
    	cin >> ai[i];
    	a[n-ai[i]]++;
    }
    bool bo=true;
    ll t=0;
    forn(i,n+1){
    	if(i==0) continue;
    	if(a[i]%i!=0) bo=false;
    	if(a[i]==0) s.insert(i);
    }
    if(bo){
    	cout << "Possible" << ln;
    	forn(i,n){
    		ll t = n-ai[i];
    		cout << b[t] << " ";
    		a[t]--;
    		if(a[t]!=0 && a[t]%t == 0){
    			b[t]=*(s.begin());
    			s.erase(s.begin());
    		}
    	}
    }
    else{
    	cout << "Impossible";
    }
}