#include <bits/stdc++.h>
#include <set>
#include <iomanip> 
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

const ll m = 1e5+5;
ll d[m];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,w,ans=0,a,b;
    cin >> n >> w;
    forn(i,n-1){
        cin >> a >> b;
        d[a]++;
        d[b]++;
    }
    forn(i,n+1){
        if(i==0) continue;
        if(d[i]==1) ans++;
    }
    long double an=2*w;
    an/=ans;
    cout << std::setprecision(30) << fixed;
    cout << an << ln;
}