#include <bits/stdc++.h>
#include <queue>
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
typedef pair < ll, pair < ll, ll > > myp;
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
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 998244353;
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,a;
    cin >> n >> m;
    vector<ll> v(m,0);
    forn(i,n){
    	cin >> a;
    	v[a-1]++;
    }
    ll dp[m][3][3];
    forn(i,m){
    	forn(j,3){
    		forn(k,3) dp[i][j][k]=-1;
    	}
    }
    forn(i,m){
    	forn(j,3){
    		forn(k,3){
    			if(i==0){
    				if(j==0 && v[i]>=k) dp[i][j][k]=(v[i]-k)/3;  
    			}
    			else {
    				forn(t,3){
    					if(dp[i-1][t][j]!=-1 && v[i]>=(j+k+t)) dp[i][j][k]=max(dp[i][j][k],dp[i-1][t][j]+t+(v[i]-t-j-k)/3);
    				}
    			}
    		}
    	}
    }
    cout << dp[m-1][0][0] << ln;
    return 0;
}