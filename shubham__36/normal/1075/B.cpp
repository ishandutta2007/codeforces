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
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll x[n+m],t[m],r[n];
    ll b;
    ll i1=0,i2=0;
    forn(i,n+m) cin >> x[i];
    forn(i,n+m){
        cin >> b;
        if(b==1) {
            t[i1]=x[i];
            i1++;
        }
        else{
            r[i2]=x[i];
            i2++;
        }
    }
    ll ans[m];
    forn(i,m) ans[i]=0;
    i1=0,i2=1;
    ll i=0;
    while(i!=n){
        ll a = abs(r[i]-t[i1]);
        ll b = 10000000000;
        if(i2<m) b = abs(r[i]-t[i2]);
        if(a<=b) ans[i1]++;
        else{
            i--;
            i1++,i2++;
        }
        i++;
    }
    forn(i,m) cout << ans[i] << " ";
    return 0;
}