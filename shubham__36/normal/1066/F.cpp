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

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (abs(a.fi-b.fi) + abs(a.se-b.se));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll a,b;
    map <ll, pair<ll, ll> > s;
    map <ll, pair<ll, ll> > e;
    map <ll, pair<ll, ll> >::iterator its;
    map <ll, pair<ll, ll> >::iterator ite;
    map <ll, pair<ll, ll> >::iterator itsp;
    map <ll, pair<ll, ll> >::iterator itep;
    forn(i,n){
        cin >> a >> b;
        if(s.find(max(a,b)) == s.end()){
            s[max(a,b)] = mp(a,b);
            e[max(a,b)] = mp(a,b);
        }
        else{
            if(a<s[max(a,b)].fi || (a==s[max(a,b)].fi && b>s[max(a,b)].se)) s[max(a,b)] = mp(a,b);
            if(b<e[max(a,b)].se || (b==e[max(a,b)].se && a>e[max(a,b)].fi)) e[max(a,b)] = mp(a,b);
        }
    }
    ll dps=0,dpe=0,t1,t2;
    for(its=s.begin(),ite=e.begin();its!=s.end();its++,ite++){
        ll k = dist((*its).se,(*ite).se);
        if(its==s.begin()){
            dps = abs((*ite).se.fi) + abs((*ite).se.se) + k;
            dpe = abs((*its).se.fi) + abs((*its).se.se) + k;
        }
        else{
            t1 = k+min(dps+dist((*itsp).se,(*ite).se),dpe+dist((*itep).se,(*ite).se));
            t2 = k+min(dps+dist((*itsp).se,(*its).se),dpe+dist((*itep).se,(*its).se));
            dps = t1;
            dpe = t2;
        }
        itsp = its;
        itep = ite;
    }
    cout << min(dps,dpe);
    return 0;
}