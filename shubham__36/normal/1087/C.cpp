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
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<p32,ll> my;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 998244353;
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





int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vp32 v(3);
    forn(i,3) cin >> v[i].fi >> v[i].se;
    sort(v.begin(), v.end());
    ll ans=abs(v[0].fi-v[1].fi)+abs(v[0].se-v[1].se)+1;
    ans += abs(v[2].fi-v[1].fi);
    if((v[2].se-v[1].se)*(v[2].se-v[0].se)>0) ans+=min(abs(v[2].se-v[1].se),abs(v[2].se-v[0].se));
    ll x=v[0].fi,y=v[0].se;
    cout << ans << ln;
    while(x!=v[1].fi || y!=v[1].se){
        cout << x << " " << y << ln;
        if(x!=v[1].fi) x++;
        else if(v[1].se > y) y++;
        else y--;
    }
    cout << x << " " << y << ln;
    if((v[2].se-v[1].se)*(v[2].se-v[0].se)<=0) y=v[2].se;
    else if(abs(v[2].se-v[1].se) < abs(v[2].se-v[0].se)) y=v[1].se;
    else y=v[0].se;
    while(x!=v[2].fi || y!=v[2].se){
        if(x!=v[2].fi) x++;
        else if(v[2].se > y) y++;
        else y--;
        cout << x << " " << y << ln;
    }
    // cout << x << " " << y << ln;
}