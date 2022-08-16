#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <set>
#include <queue>
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
typedef set<p32> ms;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
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
#define pi 3.141592653589793238462643383279502884L

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int vx[4],vy[4];
    forn(i,4){
        vy[i]=i+1;
        vx[i]=1;
    }
    int hx[2],hy[2];
    forn(i,2){
        hy[i]=2*i+1;
        hx[i]=3;
    }
    int v=0,h=0;
    forn(i,s.size()){
        if(s[i]=='0'){
            cout << vx[v] << " " << vy[v] << ln;
            v++;
            v%=4;
        }
        else{
            cout << hx[h] << " " << hy[h] << ln;
            h++;
            h%=2;
        }
    }
    return 0;
}