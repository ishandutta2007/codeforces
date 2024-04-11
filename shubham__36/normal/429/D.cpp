#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <iomanip>
#include <fstream>
 
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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
    if(b >= (MOD-1)) b %= (MOD-1);
    if(b==0) return 1;
    ll t1 = mpow(a,b/2);
    t1 *= t1;
    t1 %= MOD;
    if(b%2) t1 *= a;
    t1 %= MOD;
    return t1;
}
 
ll mpow(ll a, ll b, ll p){
    if(b==0) return 1;
    ll t1 = mpow(a,b/2,p);
    t1 *= t1;
    t1 %= p;
    if(b%2) t1 *= a;
    t1 %= p;
    return t1;
}
 
ll modinverse(ll a, ll m){
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}
 
ll range(ll l, ll r){
    return l + rand()%(r-l+1);
}

// Points to be noted:-
// 1. Take square root of mindist if minimum distance is required(instead of square of minimum distance)

struct Point
{
    ll x, y;

    Point operator -(Point p)
    {
        return {x-p.x, y-p.y};
    }

    ll dist()
    {
        return x*x + y*y; // return square of distance from origin
    }
};

bool by_x(Point &a, Point &b)
{
    return a.x < b.x;
}

bool by_y(Point &a, Point &b)
{
    return a.y < b.y;
}

const ll N=1e5+5; // upper limit on number of points
Point pt[N];

ll mindist(ll L, ll R) //returns square of minimum distance of points [pt[L],pt[R]] (both endpoints included)
{
    if(L==R)
        return INF; // defined in our template
    ll M=(L+R)/2;
    // sort(pt+L, pt+R+1, by_x);
    ll d=min(mindist(L, M), mindist(M+1, R)); // recursive step
    ll midx=pt[L+(R-L+1)/2].x;
    vector<Point> v;
    for(ll i=L;i<=R;i++)
    {
        if(Point{pt[i].x-midx, 0}.dist()<d)
        {
            v.push_back(pt[i]); // selecting points whose x-coordinates is closer to midx( less than d distance away) 
        }
    }
    sort(v.begin(), v.end(), by_y);
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(Point{0, v[i].y-v[j].y}.dist()>d)
                break; // will break for <=8 points (Thus total complexity of O(n*log(n)) for mindist)
            d=min(d, (v[i]-v[j]).dist());
        }
    }
    return d;
}   

void solve(){
    ll n;
    cin >> n;
    ll pr = 0;
    forn(i,n){
        ll x;
        cin >> x;
        pr += x;
        pt[i] = Point{i, pr};
    }
    cout << mindist(0,n-1) << ln;
}
 
int main()
{
    fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}