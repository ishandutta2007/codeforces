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
    int n,m;
    cin >> n >> m;
    char c;
    int ans=0;
    int a[n][m];
    int b[n][m];
    forn(i,n){
        forn(j,m){
            cin >> c;
            if(c=='#') a[i][j] = 1;
            else a[i][j] =0;
            b[i][j]=a[i][j];
        }
    }
    forn(i,n){
        forn(j,m){
                if(b[i][j] == 1 && i+1 < n && i+2 < n && j+1 < m && j+2 < m && b[i+1][j] == 1 && b[i+2][j] == 1 && b[i][j+1] == 1  && b[i][j+2] == 1  && b[i+1][j+2] == 1  && b[i+2][j+1] == 1  && b[i+2][j+2] == 1){
                    a[i][j] = 0;
                    a[i+1][j] = 0;
                    a[i+2][j] = 0;
                    a[i][j+2] = 0;
                    a[i+1][j+2] = 0;
                    a[i+2][j+2] = 0;
                    a[i][j+1] = 0;
                    a[i+2][j+1] = 0;
                }
                else if(a[i][j] == 1) {
                    ans =1;
                    break;
                }
        }
        if(ans == 1) break;
    }
    if(ans) cout << "NO";
    else cout << "YES";
    return 0;
}