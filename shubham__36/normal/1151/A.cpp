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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = INF;
    forn(i,n-3){
    	ll a1 = abs(s[i]-'A');
    	ll a2 = abs(s[i+1]-'C');
    	ll a3 = abs(s[i+2]-'T');
    	ll a4 = abs(s[i+3]-'G');
    	a1 = min(a1,26-a1);
    	a2 = min(a2,26-a2);
    	a3 = min(a3,26-a3);
    	a4 = min(a4,26-a4);
    	// cout << a1 << " " << a2 << " " << a3 << " " << a4 << ln;
    	ans = min(ans,a1+a2+a3+a4);
    }
    cout << ans << ln;
    return 0;
}