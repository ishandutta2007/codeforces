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
typedef unordered_map<int,int> m32;
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
string t;
ll p = 31;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    ll pin[t.size()+1];
    pin[0] = 129032259;
    forn(i,t.size()){
        pin[i+1] = (pin[i]*pin[0])%MOD;
    }
    ll a[t.size()+1];
    a[0]=0;
    ll temp=1;
    forn(i,t.size()){
        a[i+1] = (a[i] + (t[i] - 'a' + 1)*temp) % MOD;
        temp *= p;
        temp %= MOD;
    }
    ll c0=0,c1=0;
    forn(i,s.size()){
        if(s[i]=='0') c0++;
        else c1++;
    }
    ll ans=0;
    for(ll i=1;i<=t.size()/c0;i++){
        if((t.size()-i*c0) % c1 != 0 || t.size()-i*c0 == 0) continue;
        ll code0=-1,code1=-1;
        ll temp1 = 1;
        ll size0 = i;
        ll size1 = (t.size()-i*c0)/ c1;
        bool b=true;
        forn(j,s.size()){
            if(s[j]=='0'){
                ll temp;
                int ini = temp1;
                int fin = temp1+size0-1;
                temp1 += size0;
                temp = (a[fin]-a[ini-1]+MOD) % MOD;
                temp *= pin[ini];
                temp %= MOD;
                if(code0==-1){
                    code0 = temp;
                }
                else{
                    if(code0 != temp){
                        b = false;
                        break;
                    }
                }
            }
            else{
                ll temp;
                int ini = temp1;
                int fin = temp1+size1-1;
                temp1+=size1;
                temp = (a[fin]-a[ini-1]+MOD) % MOD;
                temp *= pin[ini];
                temp %= MOD;
                if(code1==-1){
                    code1 = temp;
                }
                else{
                    if(code1 != temp){
                        b = false;
                        break;
                    }
                }
            }
        }
        if(code0 != -1 && code1!= -1 && code0 == code1) b=false;
        if(b) ans++;
    }
    cout << ans << ln;
    return 0;
}