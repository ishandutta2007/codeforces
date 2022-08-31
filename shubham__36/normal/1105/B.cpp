#include <bits/stdc++.h>
#include <iomanip> 
#include <set>
#include <queue>
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
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 998244353;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[26];
    forn(i,26) a[i]=0;
    char temp='1';
    int temp1=0;
    forn(i,s.size()){
        if(s[i]==temp){
            temp1++;
        }
        else{
            temp=s[i];
            temp1=1;
        }
        if(temp1==k){
            temp1=0;
            a[temp-'a']++;
        }
    }
    int ans=0;
    forn(i,26) ans = max(ans,a[i]);
    cout << ans << ln;
    return 0;
}