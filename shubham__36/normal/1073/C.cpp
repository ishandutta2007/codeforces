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
int x,y,fx,fy;

bool check(int k)
{
    int x1=0,y1=0,fxl,fyl;
    forn(i,s.size()){
        if(s[i]=='R') x1++;
        else if(s[i]=='L') x1--;
        else if(s[i]=='D') y1--;
        else if(s[i]=='U') y1++;
        if(i>=k){
            if(s[i-k]=='R') x1--;
            else if(s[i-k]=='L') x1++;
            else if(s[i-k]=='D') y1++;
            else if(s[i-k]=='U') y1--;
        }
        if(i>=k-1){
            fxl=fx-x1;
            fyl=fy-y1;
            if(abs(x-fxl)+abs(y-fyl)<=k) return true;
        }
    }
    return false;
}

int f(int l, int u)
{
    if(l==u) return l;
    int mid = (l+u)/2;
    bool bo = check(mid);
    if(bo) return f(l,mid);
    else return f(mid+1,u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    cin >> x >> y;
    if(n < abs(x) + abs(y) || (n - abs(x) + abs(y))%2 == 1) {cout << "-1" << ln; return 0;}
    forn(i,s.size()){
        if(s[i]=='R') fx++;
        else if(s[i]=='L') fx--;
        else if(s[i]=='D') fy--;
        else if(s[i]=='U') fy++;
    }
    cout << f(0,n);
    return 0;
}