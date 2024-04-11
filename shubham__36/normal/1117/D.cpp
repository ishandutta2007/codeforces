#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

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
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 1e9 + 7;
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
#define INF LLONG_MAX
ll n,k;
vv64 mat;
vv64 a;
vv64 c;

void mult(){
    forn(i,k){
        forn(j,k){
            c[i][j]=0;
            forn(t,k){
                c[i][j]+=a[i][t]*mat[t][j];
                c[i][j]%=MOD;
            }
        }
    }
    forn(i,k){
        forn(j,k){
            a[i][j]=c[i][j];
        }
    }
}

void sq(){
    forn(i,k){
        forn(j,k){
            c[i][j]=0;
            forn(t,k){
                c[i][j]+=(a[i][t]*a[t][j]);
                c[i][j]%=MOD;
            }
        }
    }
    forn(i,k){
        forn(j,k){
            a[i][j]=c[i][j];
        }
    }
}

void mpow(ll p){
    if(p==1) return;
    if(p%2){
       // sq();
        mpow(p/2);
        sq();
        mult();
        return;
    }
    else{
       // sq();
        mpow(p/2);
        sq();
        return;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    mat.resize(k,vector<ll> (k));
    a.resize(k,vector<ll>(k));
    c.resize(k,vector<ll>(k));
    forn(i,k){
        forn(j,k){
            if(i==0){
                if(j==0 || j==k-1) mat[i][j]=1;
                else mat[i][j]=0; 
            }
            else{
                if(j==i-1) mat[i][j]=1;
                else mat[i][j]=0;
            }
        }
    }
    forn(i,k){
        forn(j,k){
            a[i][j]=mat[i][j];
        }
    }
    mpow(n);
    cout << a[0][0] << ln;
    return 0;
}