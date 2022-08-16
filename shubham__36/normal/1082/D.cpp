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
    int n;
    cin >> n;
    int a[n];
    int ans[n];
    int rem[n];
    int in=0;
    int in1=0;
    int fa = -1;
    int c =0;
    int total=0;
    forn(i,n){
        ans[i]=0;
        rem[i]=0;
    }
    forn(i,n){
        cin >> a[i];
        total+=a[i];
        if(a[i]>1) {ans[in]=i+1; fa++; in++;}
        else {c++; rem[in1]=i+1; in1++;}
    }
    forn(i,n-1){
        if(ans[i+1]!=0) {
            a[ans[i]-1]--;
            a[ans[i+1]-1]--;
        }
    }
    if(total < 2*(n-1)){
        cout << "NO" << ln;
        return 0;
    }
    else{
        if(c>=2) fa+=2;
        else fa +=c;
        cout << "YES" << " " << fa << ln;
        cout << n-1 << ln;
        forn(i,n-1){
            if(ans[i+1]!=0) cout << ans[i] << " " << ans[i+1] << ln;
        }
        forn(i,n-1){
            if(rem[i]!=0 && i==0){
                cout << ans[0] << " " << rem[i] << ln;
                a[ans[0]-1]--;
            }
            else if(rem[i]!=0){
                while(a[ans[in-1]-1] == 0) in--;
                cout << ans[in-1] << " " << rem[i] << ln;
                a[ans[in-1]-1]--;
            }
        }
    }
    return 0;
}