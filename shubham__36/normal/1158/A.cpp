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
    ll n,m;
    cin >> n >> m;
    ll b[n],g[m],ans=0;;
    forn(i,n) {cin >> b[i];ans+=b[i];}
    forn(i,m) cin >> g[i];
    ans*=m;
    sort(b,b+n);
    sort(g,g+m);
    if(b[n-1]>g[0] || (n==1 && b[n-1]!=g[0])){
    	cout << -1 << ln;
    }
    else{
    	forn(i,m){
    		if(i!=m-1) ans += g[m-1-i]-b[n-1];
    		else{
    			if(g[0]!=b[n-1]){
    				ans+=g[0]-b[n-2];
    			}
    		}
    	}
    	cout << ans << ln;
    }
    return 0;
}