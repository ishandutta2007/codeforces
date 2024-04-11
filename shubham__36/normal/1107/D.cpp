#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
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
typedef set<p32> ms;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
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
#define pi 3.141592653589793238462643383279502884L
#define L 1e9

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vv32 a(n,vector<int>(n));
    char s;
    int temp;
    forn(i,n){
    	forn(j,n/4){
    		cin >> s;
    		if(s-'0' <= 9 && s-'0'>=0){
    			temp=s-'0';
    		}
    		else{
    			temp=s-'A'+10;
    		}
    		forn(k,4){
    			a[i][4*j+3-k]=(temp&(1<<k))/(1<<k);
    		}
    	}
    }
    // forn(i,n){
    //     forn(j,n){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << ln;
    // }
    int k=1;
    int ans=n;
    bool bo=true;
    forn(i,n){
    	if(bo) {bo=false;k=1;continue;}
    	forn(j,n){		
    		if(a[i][j]!=a[i-1][j]){
    			bo=true;
    			ans = __gcd(ans,k);
    			i--;
    			break;
    		}
    	}
    	if(!bo) {k++;}
    }
    ans = __gcd(ans,k);
    k=1;
    bo=true;
    forn(i,n){
    	if(bo) {bo=false;k=1;continue; }
    	forn(j,n){		
    		if(a[j][i]!=a[j][i-1]){
    			bo=true;
    			ans = __gcd(ans,k);
    			i--;
    			break;
    		}
    	}
    	if(!bo) {k++;}
    }
    ans = __gcd(ans,k);
    cout << ans << ln;
    return 0;
}