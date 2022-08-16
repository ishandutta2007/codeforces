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
    ll n;
    cin >> n;
    ll a[n];
    forn(i,n) cin >> a[i];
    ll g=0,s=0,b=0;
    ll pg=a[0],ps=-1,pb=a[n/2]+1;
    forn(i,n){
        if(a[i]>=pg) g++;
        else if(ps==-1){
            s++;
            ps = a[i];
        }
        else if(a[i] >= ps){
            s++;
        }
        else if(s<=g){
            s++;
            ps = a[i];
        }
        else if(a[i]>=pb){
            b++;
        }
    }
    if(g<s && g<b){
        cout << g << " " << s << " " << b << ln;
    }
    else{
        cout << 0 << " " << 0 << " " << 0 << ln;
    }
}
 
int main()
{

    fast_cin();
    ll t=1;
    cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}