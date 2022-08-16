#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;;
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
#define INF 1e9
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
void solve(){  
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(c==0 && d==0 && abs(a-b)<=1){
        cout << "YES" << ln;
        if(a>b) cout << "0 ";
        forn(i,min(a,b)) cout << "1 0 ";
        if(b>a) cout << "1 ";
        cout << ln;
        return;
    }
    if(a==0 && b==0 && abs(c-d)<=1){
        cout << "YES" << ln;
        if(c>d) cout << "2 ";
        forn(i,min(c,d)) cout << "3 2 ";
        if(d>c) cout << "3 ";
        cout << ln;
        return;
    }
    ll b1=b-a;
    ll c1=c-d;
    if(b1<0 || c1<0 || abs(b1-c1)>1){
        cout << "NO" << ln;
    }
    else{
        cout << "YES" << ln;
        if(b1 > c1) cout << "1 ";
        forn(i,a) cout << "0 1 ";
        forn(i,min(b1,c1)) cout << "2 1 ";
        forn(i,d) cout << "2 3 ";
        if(b1 < c1) cout << "2 ";
        cout << ln;   
    }
}
 
int main()
{

    fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}