//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
string s;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int n,k;
    ll p=0;
    cin >> n >>k;
    vector<pair<int,int> > a(n);
    int b[k];
    forn(i,n) {
        a.pb(mp(0,0));
        cin >> a[i].fi;
    a[i].se=i+1;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    forn(i,k) {p+=a[i].fi;b[i]=a[i].se;}
    sort(b,b+k);
    cout << p << ln;
    if(k==1) {cout << n;
    return 0;}
    if(k>1) cout << b[0] << " ";
    forsn(i,1,k-1) cout << (b[i]-b[i-1]) << " ";
    if(k>1) cout << (n-b[k-2]);
    return 0;
}