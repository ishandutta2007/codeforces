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
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin >> n;
    int c[n];
    forn(i,n) c[i]=0;
    forn(i,n-1){
        cin >> a >> b;
        c[a-1]++;
        c[b-1]++;
    }
    vector<int> vec1;
    vector<int> vec2;
    forn(i,n){
        if(c[i]==0) vec1.pb(i+1);
        else vec2.pb(i+1);
    }
    int ans[n];
    ans[n-1]=n;
    if(c[n-1]!=n-1){
            cout << "NO" << ln;
            return 0;
        }
    int j1=vec1.size()-1,j2=vec2.size()-2,j=n-2;
    while(j2!=-1){
        if(j1!=-1){
            if(vec2[j2] < vec1[j1]){
            cout << "NO" << ln;
            return 0;
            }
        }
        forn(i,c[vec2[j2]-1]-1){
            ans[j]=vec1[j1];
            j1--;
            j--;
        }
        ans[j]=vec2[j2];
        j2--;
        j--;
    }
    if(j>=0){
        cout << "NO" << ln;
        return 0;
    }
    cout << "YES" << ln;
    forn(i,n-1) cout << ans[i] << " " << ans[i+1] << ln;
    return 0;
}