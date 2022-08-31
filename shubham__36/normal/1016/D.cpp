#include <bits/stdc++.h>
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    ll x=0;
    cin >> n >> m;
    int a[n],b[m];
    forn(i,n) cin >> a[i];
    forn(i,m) cin >> b[i];
    forn(i,n) x=x^a[i];
    forn(i,m) x=x^b[i];
    if(x!=0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << ln;
    ll v[n*m];
    forn(i,m) x=x^b[i];
    x=x^b[0];
    x=x^a[0];
    forn(i,n){
        forn(j,m){
            if(i==0 && j==0) v[i*m+j]=x;
            else if(i==0) v[i*m+j]=b[j];
            else if(j==0) v[i*m+j]=a[i];
            else v[i*m+j]=0;
        }
    }
    forn(i,n){
        forn(j,m){
            cout << v[i*m+j] << " ";
        }
        cout << ln;
    }
    return 0;
}