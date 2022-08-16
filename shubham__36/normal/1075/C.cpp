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
    ll a[n+1],b[m];
    ll temp;
    forn(i,n) cin >> a[i];
    a[n]=1000000000;
    ll in=0;
    forn(i,m){
        cin >> temp;
        if(temp!=1){
            cin >> temp;
            cin >> temp;
        }
        else{
            cin >> b[in];
            in++;
            cin >> temp;
        }
    }
    sort(a,a+n+1);
    sort(b,b+in);
    ll ans=1000000;
    ll ina=0,inb=0;
    while(ina!=n+1 && inb!=in){
        if(b[inb]<a[ina]){
            inb++;
        }
        else{
            ans=min(ans,ina+in-inb);
            ina++;
        }
    }
    ans=min(ans,ina+in-inb);
    cout << ans << ln;
    return 0;
}