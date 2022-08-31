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
    ll n,k;
    bool b =false;
    cin >> n;
    ll ans =(n*(n+1))/2;
    forn(i,int(sqrt(ans))+1) if(i>1 && ans % (i+1) == 0){
    b = true;
    k = i+1;
    break;
    }
    if(!b){
        if(ans % 2 == 0){
            cout << "Yes" << endl;
            vector <ll> a;
            vector <ll> b;
            ll s1=0,s2=0;
            forn(i,n){
                if(s1+n-i <= ans/2){
                    s1 += n-i;
                    a.pb(n-i);
                }
                else{
                    s2 += n-i;
                    b.pb(n-i);
                }
            }
            cout << a.size() << " ";
            forn(i,a.size()) cout << a[i] << " ";
            cout << ln;
            cout << b.size() << " ";
            forn(i,b.size()) cout << b[i] << " ";
            return 0;
        }
    }
    if(!b){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    cout << n-1 << " ";
    forn(i,n){
        if(i+1 == k) continue;
        cout << i+1 << " ";
    }
    cout << ln;
    cout << 1 << " ";
    cout << k;
    return 0;
}