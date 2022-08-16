#include <bits/stdc++.h>
#include <iomanip> 
#include <set>
#include <queue>
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
#define MAX 300000

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n],b[n];
    m64 umap;
    bool bo=false;
    forn(i,n){
    	cin >> a[i];
    	if(i!=0){
    		if(umap.find(a[i]-a[i-1])==umap.end()) umap[a[i]-a[i-1]]=1;
    		else umap[a[i]-a[i-1]]++;
    	} 
    }
    forn(i,n){
    	cin >> b[i];
    	if(i!=0){
    		if(umap.find(b[i]-b[i-1])==umap.end()) bo=true;
    		else {
    			umap[b[i]-b[i-1]]--;
    			if(umap[b[i]-b[i-1]]<0) bo=true;
    		}
    	}
    }
    if(bo || a[0]!=b[0] || a[n-1]!=b[n-1]) cout << "No" << ln;
    else cout << "Yes" << ln;
    return 0;
}