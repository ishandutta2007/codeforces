#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
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
typedef set<p32> ms;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 1e9+7;
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
#define pi 3.141592653589793238462643383279502884L
#define L 1e9

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cout.tie(0);
    ll q;
    cin >> q;
    while(q--){
    	ll n;
    	cin >> n;
    	string s;
    	cin >> s;
    	if(n==2 && s[0]>=s[1]){
    		cout << "NO" << ln;
    	}
    	else{
    		cout << "YES" << ln;
    		cout << 2 << ln;
    		cout << s[0] << " ";
    		forn(i,n-1){
    			cout << s[i+1];
    		}
    		cout << ln;
    	}

    }
    return 0;
}