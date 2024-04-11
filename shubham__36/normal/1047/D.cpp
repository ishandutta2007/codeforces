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
    ll n,m,ans;
    cin >> n >> m;
    ll t = min(n,m);
    if(t==1){
        ans = (n+m-t)%6;
        ans = min(ans,6-ans);
        ans = n*m - ans;
    }
    else if(t==2){
        if(n+m-t == 2) ans = 4;
        else if(n+m-t == 1 || n+m-t == 3 || n+m-t == 7) ans = 2;
        else ans =0;
        ans = n*m -ans;
    }
    else if(n*m % 2 == 0) ans =n*m;
    else ans = n*m-1;
    cout << ans;
    return 0;
}