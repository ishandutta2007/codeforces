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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    ll n,m;
    ll x1,x2,x3,x4,y1,y2,y3,y4;
    cin >> t;
    forn(i,t){
        cin >> n >> m;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        cin >> x4 >> y4;
        ll nb = (n*m)/2;
        nb -= ((x2-x1+1)*(y2-y1+1))/2;
        if((x1+y1) %2 == 1 && (x2-x1)%2 == 0 && (y2-y1)%2 == 0) nb--;
        //cout << n*m - nb << " " << nb << ln;
        nb += ((x4-x3+1)*(y4-y3+1))/2;
        if((x3+y3) %2 == 0 && (x3-x4)%2 == 0 && (y4-y3)%2 == 0) nb++;
        //cout << n*m - nb << " " << nb << ln;
        ll x5,x6,y5,y6;
        x5 = max(x1,x3),y5 = max(y1,y3);
        x6 = min(x4,x2),y6 = min(y4,y2);
        if(x6 >= x5 && y6 >= y5){
            nb += ((x6-x5+1)*(y6-y5+1))/2;
            if((x5+y5) %2 == 1 && (x5-x6)%2 == 0 && (y5-y6)%2 == 0) nb++;
        }
        cout << n*m - nb << " " << nb << ln;
    }
    return 0;
}