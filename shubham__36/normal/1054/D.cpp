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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ne,k;
    cin >> ne >> k;
    unordered_map<ll, ll> umap;
    umap[0]=1;
    ll a = pow(2,k) - 1;
    ll wr=0,in=0,input;
    ll n,tr;
    forn(i,ne){
        cin >> input;
        //input = (i+1)%(a+1);
        in ^= input;
        if(umap.find(in)==umap.end()) n=0;
        else n=umap[in];
        if(umap.find(a^in)==umap.end()) tr=0;
        else tr = umap[a^in];
        if(n<=tr){
            wr+=n;
            if(umap.find(in)==umap.end()) umap[in]=1;
            else umap[in]++;
        }
        else {
            in = a^in;
            wr+=tr;
            if(umap.find(in)==umap.end()) umap[in]=1;
            else umap[in]++;
        }
    }
    ll answer = (ne*(ne-1))/2 + ne - wr;
    cout << answer;
    return 0;
}