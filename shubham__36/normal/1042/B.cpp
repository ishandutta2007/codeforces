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
string c;

bool f(string c, char b){
    forn(i,c.size()){
        if(c[i]==b) return true;
    }
    return false;
}

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll n,m,sum=0,ma=0;
    cin >> n;
    ll a[7];
    forn(i,7) a[i] = 1000000;
    forn(i,n) {cin >> m; cin >> c;
        if(f(c,'A') && f(c,'B') && f(c,'C')) a[6]=min(a[6],m);
        else if(f(c,'A') && f(c,'B') && !f(c,'C')) a[5]=min(a[5],m);
        else if(f(c,'A') && !f(c,'B') && f(c,'C')) a[4]=min(a[4],m);
        else if(!f(c,'A') && f(c,'B') && f(c,'C')) a[3]=min(a[3],m);
        else if(!f(c,'A') && !f(c,'B') && f(c,'C')) a[2]=min(a[2],m);
        else if(!f(c,'A') && f(c,'B') && !f(c,'C')) a[1]=min(a[1],m);
        else if(f(c,'A') && !f(c,'B') && !f(c,'C')) a[0]=min(a[0],m);
    }
    ll ans = min(min(min(min(min(min(min(a[0]+a[1]+a[2],a[6]),a[5]+a[2]),a[4]+a[1]),a[3]+a[0]),a[3]+a[4]),a[3]+a[5]),a[4]+a[5]);
    if(ans == 1000000) cout << -1;
    else cout << ans ;
    return 0;
}