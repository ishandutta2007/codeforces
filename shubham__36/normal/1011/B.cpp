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
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans=0,k,te=0;
    char prev;
    cin >> n >> m;
    te=n;
    int a[100]={0};
    forn(i,m) {
        cin >> k;
        a[k-1]++;
    }
    if(m<n){
        cout << "0" << ln;
        return 0;
    }
    sort(a,a+100);
    //forn(i,100) cout << a[i] << " ";
    ans=a[100-n];
    while(te>=n){
    te=0;
    forn(i,n-1) {
        te+=a[99-i]/(ans+1);
    }
    //cout << te << ln;
    if(te>=n) ans++;
    }
    cout << ans << endl;
    return 0;
}