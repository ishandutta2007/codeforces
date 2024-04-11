#include <cstdio>
#include <cstring>
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
ll m,n,l;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin >> m >> n;
    int a[n],k;
    forn(i,n) {
        cout << "1" << ln;
        fflush(stdout);
        cin >> a[i];
        if(a[i]==0) return 0;
    }
    forn(i,60-n) {
        cout << (m+l)/2 << ln;
        fflush(stdout);
        cin >> k;
        if(k==0){
            return 0;
        }
        if(k*a[i%n]==1){
            l=(m+l)/2+1;
        }
        else{
            m=(m+l)/2-1;
        }
    }
    return 0;
}