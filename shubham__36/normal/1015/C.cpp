//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

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
const int MOD = 1e9+7;
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
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll n,m,ans=0,f,s,sum=0;
    cin >> n >> m;
    ans=n;
    ll a[n];
    forn(i,n) {
        cin >> f >> s;
        sum+=s;
        a[i]=f-s;
    }
    if(sum > m) {cout << -1 << ln; return 0;}
    sort(a,a+n);
    rforn(i,n-1){
        sum+=a[n-1-i];
        ans--;
        if(sum > m) {
            cout << ans+1 << ln;
            return 0;
        }
    }
    cout << "0" << ln;
    return 0;
}