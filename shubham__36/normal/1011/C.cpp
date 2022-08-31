#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

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
const int MOD = 1e9+7;
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
int n,m;
ld d;

ld f(int a[], int b[], int i){
    ld k,t;
    k=(1.0/a[i]);
    k+=(1-k)*(1.0/b[(i+1)%n]);
    if(k>=1) return -1;
    if(i==n-1)
        return k;
    else{
        t=f(a,b,i+1);
        if(t>=1 || t<=0) return -1;
        k+=(1-k)*t;
    }
    if(k>=1 || k<=0) return -1;
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a[n],b[n];
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[i];
    d=f(a,b,0);
    if(d==-1){
        cout << d << ln;
        return 0;
    }
    d=(d*m)/(1-d);
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    cout << d << ln;
    return 0;
}