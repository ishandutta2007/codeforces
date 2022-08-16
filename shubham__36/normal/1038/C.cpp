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
string s;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll n,ans=0;
    cin >> n;
    ll a[n],b[n],i=n-1,j=n-1;
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    forn(k,n){
        if(j<0 || (i>=0 && a[i]>=b[j])) {
            ans+=a[i];
            i--;
            if(i<0 || (j>=0 && a[i]<=b[j])) {ans -= b[j]; j--;}
            else if(j<0 || (i>=0 && a[i]>b[j])) {i--;}
        }
        else if(i<0 || (j>=0 && a[i]<b[j])){
            j--;
            if(i<0 || (j>=0 && a[i]<=b[j])) { ans -= b[j]; j--;}
            else if(j<0 || (i>=0 && a[i]>b[j])) {i--;}
        }
    }
    cout << ans;
    return 0;
}