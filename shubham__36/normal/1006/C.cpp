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
string s;

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll p=0,n;
    cin >> n;
    ll a[n],j=1,sum1=0,sum2=0,k=n-2;
    forn(i,n) cin >> a[i];
    if(n==1){
        cout << "0";
        return 0;
    }
    sum1=a[0],sum2=a[n-1];
    while(j<=k){
        if(sum1==sum2){
            p=sum1;
        }
        if(sum1<=sum2){
            sum1+=a[j];
            j++;
            continue;
        }
        if(sum1>sum2){
            sum2+=a[k];
            k--;
        }
    }
    if(sum1==sum2){
            p=sum1;
        }
    cout << p;
    return 0;
}