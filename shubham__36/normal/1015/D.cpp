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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,k,s,a=1;
    cin >> n >> k >> s;
    if(s<k || s > (n-1)*k) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << ln;
    while(s-(n-1) >= k-1 && k>=1) {
        k--;
        s-=n-1;
        a=1+n-a;
        cout << a << " ";
    }
    bool bol=true;
    if(a==1) bol=false;
    while(k>1){
        k--;
        s--;
        if(bol){
                a++;
        if(a>n) a-=2;}
        else{
            a--;
           if(a<1) a+=2;
        }
        cout << a << " ";
    }
    if(k==1){
    a-=s;
    if(a < 1) a+=2*s;
    cout << a << endl;
    }
    return 0;
}