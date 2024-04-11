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
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,ans=0;
    char prev;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(),s.end());
    prev=s[0];
    k--;
    ans+=s[0]-'a'+1;
    //forn(i,s.size()) cout << s[i] << " ";
    for(int i=1;i<s.size() && k!=0;i++){
        if(s[i]-prev >= 2){
            prev=s[i];
    k--;
    ans+=s[i]-'a'+1;
        }
    }
    if(k){
        cout << "-1" << ln;
        return 0;
    }
    cout << ans << ln;
    return 0;
}