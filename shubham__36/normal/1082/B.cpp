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
    int n;
    cin >> n;
    cin >> s;
    ll ans=0,temp=0;
    bool b=true;
    int c=0;
    forn(i,n){
        if(s[i]=='G') {temp++; b=false;}
        else if(b == false){
            c++;
            b = true;
            ans = max(ans,temp);
            temp = 0;
        }
    }
    if(b == false){
    c++;
    b = true;
    ans = max(ans,temp);
    temp = 0;
    }
    if(c>1) ans++;
    ll temp1=0;
    bool bo=false;
    forn(i,n){
        if(s[i]=='G') temp++;
        else if(i!=n-1 && s[i]=='S' && s[i+1]=='G') {if(c>2) ans = max(temp1+temp+1,ans); else ans = max(temp1+temp,ans); temp1 = temp; temp=0;}
        else {if(c>2) ans = max(temp1+temp+1,ans); else ans = max(temp1+temp,ans); temp=0; temp1=0;}
    }
    if(c>2) ans = max(temp1+temp+1,ans); else ans = max(temp1+temp,ans);
    cout << ans << ln;
    return 0;
}