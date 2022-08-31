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
    ll a[n][m],b[n][m];
    forn(i,n) forn(j,m) cin >> a[i][j];
    forn(i,n) forn(j,m) cin >> b[i][j];
    forn(i1,n+m-1){
    	m32 mm;
    	ll j=0;
    	ll i=i1;
    	if(i>=m) {
    		j=i-m+1;
    		i=m-1;
    	}
    	while(j<n && i>=0){
    		if(mm.find(a[j][i])==mm.end()) mm[a[j][i]]=1;
    		else {
    			mm[a[j][i]]++;
    			if(mm[a[j][i]]==0) mm.erase(mm.find(a[j][i]));
    		}
    		if(mm.find(b[j][i])==mm.end()) mm[b[j][i]]=-1;
    		else {
    			mm[b[j][i]]--;
    			if(mm[b[j][i]]==0) mm.erase(mm.find(b[j][i]));
    		}
    		j++;
    		i--;
    	}
    	if((ll)mm.size()!=0){
    		cout << "NO" << endl;
    		return 0;
    	}
    }
    cout << "YES" << ln;
    return 0;
}