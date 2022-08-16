#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

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
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 1e9 + 7;
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
#define INF LLONG_MAX

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll a,b;
    ll c[n],mi[n];
    forn(i,n) mi[i]=INF,c[i]=0;
    ll t=0;
    forn(i,m){
        cin >> a >> b;
        c[a-1]++;
        t=max(t,c[a-1]);
        ll d;
        if(b>=a) d=b-a;
        else d = (b-a+n)%n;
        mi[a-1] = min(mi[a-1],d);
    }
    ll ans[n];
    ll k = (t-1)*n;
    // cout << k << ln;
    // forn(i,n) cout << c[i] << " ";
    // cout << ln;
    // forn(i,n) cout << mi[i] << " ";
    // cout << ln;
    forn(i,n) ans[i] = k;
    forn(i,n){
        forn(j,n){
            if(c[(j+i)%n]==t) ans[i] = max(ans[i],k+j+mi[(j+i)%n]);
            else if(c[(j+i)%n]==t-1 && mi[(j+i)%n]!=INF) ans[i]=max(ans[i],k+j-n+mi[(j+i)%n]);
        }
    }
    forn(i,n) cout << ans[i] << " ";
    cout << ln;
    return 0;
}