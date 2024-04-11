//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define forn(i,e) for(long long int i = 0; i < e; i++)
#define forsn(i,s,e) for(long long int i = s; i < e; i++)
#define rforn(i,s) for(long long int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(long long int i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
string s,b;

int f(char a,char b,char c,char d)
{
    int ar[26];
    forn(i,26) ar[i]=0;
    ar[a-'a']++;
    ar[b-'a']++;
    ar[c-'a']++;
    ar[d-'a']++;
    sort(ar,ar+26);
    if(ar[25]==4) return 0;
    if(ar[25]==2 && ar[24]==2) return 0;
    if(ar[23]==0) return 1;
    if(ar[22]==0 && a==b) return 2;
    if(ar[23]==0 || ar[22]==0) return 1;
    return 2;
}

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    long long int ans=0,n;
    cin >> n >> s >> b;
    forn(i,n/2){
        //cout << f(s[i],s[n-1-i],b[i],b[n-1-i]);
        ans+=f(s[i],s[n-1-i],b[i],b[n-1-i]);
    }
    if(n%2==1 && s[n/2]!=b[n/2]){
      ans++;
    }
    cout << ans;
    return 0;
}