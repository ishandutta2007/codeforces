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
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    forn(i,n){
        cin >> a[i];
        c[a[i]-1]=i;
        b[i]=0;
    }
    int temp;
    rforn(i,n-1){
        if(c[i]+i+1 < n){
            temp = c[i]+i+1;
            while(temp < n){
                if(a[temp] > i+1 && b[temp] == 0){
                    b[c[i]] = 1;
                    break;
                }
                temp+=i+1;
            }
        }
        if(b[c[i]]==0 && c[i]-i-1 >= 0){
            temp = c[i]-i-1;
            while(temp >= 0){
                if(a[temp] > i+1 && b[temp] == 0){
                    b[c[i]] = 1;
                    break;
                }
                temp-=i+1;
            }
        }
    }
    forn(i,n){
        if(b[i]==0) cout << "B";
        else cout << "A";
    }
    return 0;
}