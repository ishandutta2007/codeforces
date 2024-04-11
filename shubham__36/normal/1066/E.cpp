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


int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll ans=0;
    string s1,s2;
    int n,m;
    cin >> n >> m >> s1 >> s2;
    int a[m],c=0;
    forn(i,m){
        if(s2[i] == '1') c++;
        a[i]=c;
    }
    ll b[n];
    ll t=1;
    forn(i,n){
        b[i] = t;
        t*=2;
        t%=MOD;
    }
    forn(i,n){
        if(s1[i] == '1') {
            if(m-n+i >= 0){
                ans += a[m-n+i]*b[n-1-i];
                ans%=MOD;
            }
        }
    }
    cout << ans;
    return 0;
}