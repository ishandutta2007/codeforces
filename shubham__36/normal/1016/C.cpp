#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

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
string s,t;

ll n;

void f(ll a[], ll b[], ll s[], ll l[], ll s1[], ll l1[], ll sum[], ll k)
{
    if(k==n) return;
    s1[n-1-k]=s1[n-k]+sum[n-k]+b[n-1-k]*(2*k+1);
    l1[n-k-1]=l1[n-k]+sum[n-k]+a[n-1-k]*(2*k+1);
    s[n-1-k]=max(b[n-1-k]+l[n-k]+2*sum[n-k],s1[n-k-1]);
    l[n-1-k]=max(a[n-1-k]+s[n-k]+2*sum[n-k],l1[n-k-1]);
    f(a,b,s,l,s1,l1,sum,k+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll a[n],b[n],s[n],l[n],s1[n],l1[n],sum[n];
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[i];
    sum[n-1]=a[n-1]+b[n-1];
    rforn(i,n-2) sum[i]=sum[i+1]+a[i]+b[i];
    s[n-1]=b[n-1];
    s1[n-1]=b[n-1];
    l[n-1]=a[n-1];
    l1[n-1]=a[n-1];
    f(a,b,s,l,s1,l1,sum,1);
    /*cout << sum[0] << " " << sum[1] << " " << sum[2];
    cout << s[0] << " " << s[1] << " " << s[2];
    cout << l[0] << " " << l[1] << " " << l[2];
    cout << s1[0] << " " << s1[1] << " " << s1[2];
    cout << l1[0] << " " << l1[1] << " " << l1[2];*/
    cout << s[0] << ln;
    return 0;
}