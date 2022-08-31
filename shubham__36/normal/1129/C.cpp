#include <bits/stdc++.h> 
#include <complex>
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
#include <iomanip>

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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
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
#define INF LLONG_MAX
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

bool check(bool a, bool b, bool c, bool d){
	if(!a && !b && c && d) return 0;
	if(!a && b && !c && d) return 0;
	if(a && b && c && !d) return 0;
	if(a && b && c && d) return 0;
	return 1;
}

void solve(){
	ll n;
	cin >> n;
	bool a[n];
	ll ans=0;
	ll dp[n][n],f[n][n];
	forn(i,n) forn(j,n) dp[i][j]=f[i][j]=0;
	forn(i,n) f[i][i]=1;
	forn(i,n) {
		cin >> a[i];
		forn(j,i){
			if(i-4>=j && check(a[i-3],a[i-2],a[i-1],a[i])) f[j][i]+=f[j][i-4];
			if(i-3==j && check(a[i-3],a[i-2],a[i-1],a[i])) f[j][i]++;
			if(i-3>=j) f[j][i]+=f[j][i-3];
			if(i-2==j) f[j][i]++;
			if(i-2>=j) f[j][i]+=f[j][i-2];
			if(i-1==j) f[j][i]++;
			if(i-1>=j) f[j][i]+=f[j][i-1];
			if(i==j) f[j][i]++;
			f[j][i]%=MOD;
			if(a[j]==a[i]){
				if(j!=0) dp[j][i] = dp[j-1][i-1]+1;
				else dp[j][i] = 1;
			}
		}
		ll temp = 0;
		forn(j,i){
			temp = max(temp,dp[j][i]);
		}
		forn(j,i+1-temp){
			ans += f[j][i]; 
			ans %= MOD;
		}
		cout << ans << ln;
	}
}


int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}