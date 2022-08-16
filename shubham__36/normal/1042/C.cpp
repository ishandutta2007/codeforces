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
string c;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll n,m=-1000000001,p1,k=0,in;
    vector <ll> zeros;
    vector <ll> last;
    cin >> n;
    ll a;
    forn(i,n) {cin >> a;
        if(a==0) zeros.pb(i+1);
        else if(a>0) last.pb(i+1);
        else{
        if(a>m){
            m=a;
            in=i+1;
        }
        last.pb(i+1);
        k++;
        k%=2;
        }
    }
    if(k==1) zeros.pb(in);
    if(zeros.size() > 1){
    forn(i,zeros.size()-1){
        cout << "1" << " " << zeros[i] << " " << zeros[i+1] << ln;
    }
    }
    if(zeros.size()==n) return 0;
    if(zeros.size()!=0) cout << "2" << " " << zeros[zeros.size()-1] << ln;
    forn(i,last.size()-1){
        if(k != 0 && last[i+1]==in && i+2 < last.size()) cout << "1" << " " << last[i] << " " << last[i+2] << ln;
        else if(k == 0 || (last[i]!=in && last[i+1]!=in) ) cout << "1" << " " << last[i] << " " << last[i+1] << ln;
    }
    return 0;
}