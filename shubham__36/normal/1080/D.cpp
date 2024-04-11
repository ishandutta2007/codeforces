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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
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
string s;

ll f(ll a, ll l, ll h, ll fix)
{
    if (l==h) return l;
    ll i = (l+h)/2;
    ll t = pow(2,i);
    if(fix-i > 31) return f(a,l,i,fix);
    ll ct = pow(4,fix-i);
    if((t*t-1)/3+(t-1)*(t-1)*((ct-1)/3) >= a) return f(a,l,i,fix);
    else return f(a,i+1,h,fix);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    ll n,k;
    cin >> t;
    forn(i,t){
        cin >> n >> k;
        if(n>32) cout << "YES" << " " << n-1 << ln;
        else if(n==2 && k==3) cout << "NO" << ln;
        else{
            ll hgj = 31;
            ll c = f(k,1,min(n,hgj),n);
            if (n<31 && pow(4,n) < 3*k + 1) cout << "NO" << ln;
            else cout << "YES" << " " << n-c << ln;
        }
    }
    return 0;
}