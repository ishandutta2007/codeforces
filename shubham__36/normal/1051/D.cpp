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
string s;
int b[100];
ll vec[1000][2000][2];

ll f(ll n,ll k,int p)
{
    if(k<=0 || n<=0 || k>2*n) return 0;
    if(vec[n-1][k-1][p]!=0) return vec[n-1][k-1][p];
    if(p==1){
        if(k>2*n) return 0;
        if(k==2*n) return 2;
        ll ans = f(n-1,k,1) + 2*f(n-1,k-1,0) + f(n-1,k-2,1);
        ans = ans % MOD;
        vec[n-1][k-1][p] = ans;
        return ans;
    }
    else{
        if(k>=2*n) return 0;
        if(n==1 && k==1) return 2;
        ll ans = 2*f(n-1,k,1) + f(n-1,k,0) + f(n-1,k-1,0);
        ans = ans % MOD;
        vec[n-1][k-1][p] = ans;
        return ans;
    }
}

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int n,k;
    cin >> n >> k;
    //cout << f(1,1,0) << ln;
    ll ans = f(n,k,1) + f(n,k,0);
    ans = ans % MOD;
    cout << ans;
    return 0;
}