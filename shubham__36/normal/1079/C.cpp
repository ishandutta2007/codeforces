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
    int a[n];
    forn(i,n) cin >> a[i];
    int b[n];
    forn(i,n) b[i]=0;
    int d=0;
    forn(i,n-1){
        if(a[i]>a[i+1] && d==-1) {
            b[i]=b[i-1]-1;
            if(b[i]==0){
                cout << -1;
                return 0;
            }
        }
        else if(a[i]>a[i+1] && d==1) b[i]=5;
        else if(a[i]>a[i+1] && d==0 && (i==0 || b[i-1]!=5)) b[i]=5;
        else if(a[i]>a[i+1] && d==0) b[i]=4;
        else if(a[i]<a[i+1] && d==1) {
            b[i]=b[i-1]+1;
            if(b[i]==6){
                cout << -1 ;
                return 0;
            }
        }
        else if(a[i]<a[i+1] && d==-1) b[i]=1;
        else if(a[i]<a[i+1] && d==0 && (i==0 || b[i-1]!=1)) b[i]=1;
        else if(a[i]<a[i+1] && d==0) b[i]=2;
        if(a[i]>a[i+1]) d=-1;
        else if(a[i]<a[i+1]) d=1;
        else {
            if(d==1 && b[i]==0) b[i]=b[i-1]+1;
            else if(d==-1 && b[i]==0) b[i]=b[i-1]-1;
            else if(i!=0 && b[i-1]!=3 && b[i]==0) b[i]=3;
            else if(b[i]==0) b[i]=2;
            d=0;
        }
    }
    if(n==1) b[n-1]=3;
    else if(d==1) b[n-1]=b[n-2]+1;
    else if(d==-1) b[n-1]=b[n-2]-1;
    else if(b[n-2]!=3) b[n-1]=3;
    else b[n-1]=2;
    forn(i,n){
        if(b[i]<1 || b[i]>5 || (i!=0 && b[i-1]==b[i])){
            cout << -1 ;
            return 0;
        }
    }
    forn(i,n){
        cout << b[i] << " ";
    }
    return 0;
}