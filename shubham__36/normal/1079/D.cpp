#include <bits/stdc++.h>
#include <iomanip>
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

long double f(ll a, ll b, ll c, ll x, ll y){
    long double ans;
    if(x!=2000000000) {
        ans = (-1.0 * (a*x+c))/b;
    }
    else{
        ans = (-1.0 * (b*y+c))/a;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::cout << setprecision(20) << fixed << '\n';
    ll a,b,c,x1,x2,y1,y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    long double ans = abs(x1-x2)+abs(y1-y2);;
    if(a==0 || b==0 || y1 == y2 || x1 == x2 || (1.0 * (a*(y1-y2)))/(b*(x1-x2)) > 0) {
        cout << ans;
        return 0;
    }
    long double temp = a*a+b*b;
    long double r = sqrt(temp);
    long double tan = abs(a)*1.0/b;
    long double cos = abs(b)*1.0/r;
    long double sin = abs(a)*1.0/r;
    long double dal,da,ptx1,ptx2,pty1,pty2;
    temp = f(a,b,c,x1,2000000000);
    long double temp1=0;
    bool b1=false,b2=false;
    if((y2-y1)*(temp-y1) >= 0) {
        ptx1 = x1;
        pty1 = temp;
        temp1 += abs(y1-temp);
        b1 = true;
    }
    temp = f(a,b,c,2000000000,y1);
    if(!b1 && (x2-x1)*(temp-x1) >= 0) {
        ptx1 = temp;
        pty1 = y1;
        temp1 += abs(x1-temp);
    }
    temp = f(a,b,c,x2,2000000000);
    if((y1-y2)*(temp-y2) >= 0) {
        ptx2 = x2;
        pty2 = temp;
        temp1 += abs(y2-temp);
        b2 = true;
    }
    temp = f(a,b,c,2000000000,y2);
    if(!b2 && (x1-x2)*(temp-x2) >= 0) {
        ptx2 = temp;
        pty2 = y2;
        temp1 += abs(x2-temp);
    }
    long double dis = sqrt((ptx1-ptx2)*(ptx1-ptx2) + (pty1-pty2)*(pty1-pty2));
    ans = min(ans , dis + temp1);
    cout << ans;
    return 0;
}