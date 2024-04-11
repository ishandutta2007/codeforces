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

ll fr(ll r1, ll l, ll r){
    if(l==r) return l;
    ll mid = (l+r)/2;
    cout << "? " << r1 << " " << l << " " << r1 << " " << mid << endl;
    ll temp =0;
    cin >> temp;
    if(temp%2==1) return fr(r1,l,mid);
    else return fr(r1,mid+1,r);
}

ll fc(ll c, ll l, ll r){
    if(l==r) return l;
    ll mid = (l+r)/2;
    cout << "? " << l << " " << c << " " << mid << " " << c << endl;
    ll temp =0;
    cin >> temp;
    if(temp%2==1) return fc(c,l,mid);
    else return fc(c,mid+1,r);
}

int main(){
	// ios_base::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
    ll n;
    cin >> n;
    v64 r,c;
    forn(i,n-1){
        cout << "? " << 1 << " " << i+1 << " " << n << " " << i+1 << endl;
        ll temp =0;
        cin >> temp;
        if(temp%2==1) c.pb(i+1);
    }
    if((ll)c.size()==1) c.pb(n);
    forn(i,n-1){
        cout << "? " << i+1 << " " << 1 << " " << i+1 << " " << n << endl;
        ll temp =0;
        cin >> temp;
        if(temp%2==1) r.pb(i+1);
    }
    if((ll)r.size()==1) r.pb(n);
    if((ll)r.size()==2){
        ll p1 = fr(r[0],1,n),p2 = fr(r[1],1,n);
        cout << "! " << r[0] << " " << p1 << " " << r[1] << " " << p2 << endl;
    }
    else{
        ll p1 = fc(c[0],1,n),p2 = fc(c[1],1,n);
        cout << "! " << p1 << " " << c[0] << " " << p2 << " " << c[1] << endl;
    }
    return 0;
}