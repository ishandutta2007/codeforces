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
    int n,m;
    cin >> n >> m;
    vv64 vec(m);
    v64 cou(n);
    int s,r;
    forn(i,n) cou[i]=0;
    forn(i,n){
        cin >> s >> r;
        r *= -1;
        vec[s-1].pb(r);
    }
    ll temp=0;
    forn(i,m){
        sort(vec[i].begin(),vec[i].end());
        temp=0;
        forn(j,vec[i].size()){
            temp+=vec[i][j];
            if(temp<0) cou[j]+=temp;
        }
    }
    sort(cou.begin(),cou.end());
    if(cou[0]>=0) cout << 0 << ln;
    else cout << (-1) * cou[0] << ln;
    return 0;
}