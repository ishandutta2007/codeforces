#include <bits/stdc++.h>
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
typedef vector<vector<ll> > vv64;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,c;
    cin >> n >> c;
    int lim = 500001;
    vv32 vec(lim);
    int a;
    int ans=0;
    forn(i,n){
        cin >> a;
        if(a==c) ans++;
        vec[a].pb(i);
    }
    int ftemp=0;
    forn(i,lim){
        if(i==0 || i==c) continue;
        int temp=0;
        int in=0;
        forn(j,vec[i].size()){
            if(in < vec[c].size() && vec[c][in] < vec[i][j]){
                temp--;
                in++;
                j--;
            }
            else{
                temp++;
            }
            if(temp < 0) temp=0;
            ftemp = max(ftemp,temp);
        }
    }
    cout << ans + ftemp << ln;
    return 0;
}