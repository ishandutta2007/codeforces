//#include <bits/stdc++.h>
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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
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

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll n,m,k;
    cin >> n >> m >> k;
    ll a = 2*n*m;
    if(a % k != 0){
        cout << "NO" << ln;
        return 0;
    }
    a = a/k;
    ll p2=__gcd(k,m);
    ll y;
    if(p2!=1) {
        y = 2*(m/p2);
    }
    else{
        y = m;
    }
    ll x;
    if(a % y == 0)  x= a/y;
    else y/=2;
    x = a/y;
    cout << "YES" << ln;
    cout << 0 << " " << y << ln;
    cout << 0 << " " << 0 << ln;
    cout << x << " " << y << ln;
    return 0;
}