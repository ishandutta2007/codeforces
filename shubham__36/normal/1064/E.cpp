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
ll MOD = 1e9+7;
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
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int n;
    cin >> n;
    ll l=1,h=1000000000;
    string temp,temp1;
    forn(i,n){
        if(i==0) cout << 0 << " " << 0 << ln;
        else if(i==n-1) cout << (l+h)/2 << " " << 1 << ln;
        else cout << (l+h)/2 << " " << 0 << ln;
        fflush(stdout);
        if(i==0) cin >> temp;
        else if(i==n-1) cin >> temp1;
        else{
            cin >> s;
            if(s==temp) l = (l+h)/2 + 1;
            else h = (l+h)/2 - 1;
        }
    }
    if(temp1 == temp) cout << (l+h)/2 << " " << 0 << " " << (l+h)/2 + 1 << " " << 1 << ln;
    else cout << (l+h)/2 << " " << 0 << " " << (l+h)/2 - 1 << " " << 1 << ln;
    fflush(stdout);
    return 0;
}