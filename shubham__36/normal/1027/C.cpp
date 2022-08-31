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
//string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,k;
    cin >> t;
    forn(i,t) {
        cin >> k;
        int a[k];
        forn(j,k) {
            cin >> a[j];
            //cout << a << ln;
        }
        //cout << k << endl;
        sort(a,a+k);
        vector <int> vec;
        bool bo = true;
        ll temp=a[0],mcount=1;
        forn(j,k) {
            if(j==0) continue;
            if(temp == a[j]) {mcount++;}
            if(mcount == 4) {cout << a[j] << " " << a[j] << " " <<  a[j] << " " <<  a[j] << ln; bo=false; break;}
            if(temp != a[j]){
                if(mcount >= 2) vec.pb(temp);
                mcount = 1;
                temp = a[j];
            }
        }
        if(mcount >= 2) vec.pb(temp);
        if(!bo) continue;
        int s1,s2;
        double r;
        s1 = vec[0];
        s2 = vec[1];
        r = (s1 * 1.0) / s2;
        for(ll j=2;j<vec.size();j++){
            if(((vec[j-1] * 1.0) / vec[j]) > r) {
                s1 = vec[j-1];
                s2 = vec[j];
                r = ((vec[j-1] * 1.0) / vec[j]);
            }
        }
        cout << s1 << " " << s1 << " " << s2 << " " << s2 << ln;
    }
    return 0;
}