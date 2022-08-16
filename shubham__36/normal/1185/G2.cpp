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
#define INF LLONG_MAX/2e5

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(){
	ll sz = 51;
	ll dp[sz][sz][sz][3];
	forn(i,sz) forn(j,sz) forn(k,sz) forn(t,3) dp[i][j][k][t]=0;
		dp[1][0][0][0]=1;
		dp[0][1][0][1]=1;
		dp[0][0][1][2]=1;
		forsn(tot,2,3*sz-2){
			forn(j,sz){
				forn(k,sz){
					if(tot-j-k>=0 && tot-j-k<=sz-1){
						if(j>0) {
							dp[j][k][tot-j-k][0]+=dp[j-1][k][tot-j-k][1]+dp[j-1][k][tot-j-k][2];
							dp[j][k][tot-j-k][0]%=MOD;
						}
						if(k>0) {
							dp[j][k][tot-j-k][1]+=dp[j][k-1][tot-j-k][0]+dp[j][k-1][tot-j-k][2];
							dp[j][k][tot-j-k][1]%=MOD;
						}
						if(tot-j-k>0) {
							dp[j][k][tot-j-k][2]+=dp[j][k][tot-j-k-1][1]+dp[j][k][tot-j-k-1][0];
							dp[j][k][tot-j-k][2]%=MOD;
						}
					}
				}
			}
		}
	ll n,t;
	cin >> n >> t;
	ll a[n],b[n];
	ll c1=0,c2=0,c3=0;
	forn(i,n) {
		cin >> a[i] >> b[i];
		if(b[i]==1) c1++;
		else if(b[i]==2) c2++;
		else c3++;
	}
	ll dp1[c1+1][c2+1][c3+1][t+1];
	forn(i1,c1+1) forn(i2,c2+1) forn(i3,c3+1) forn(i4,t+1) dp1[i1][i2][i3][i4]=0;
	dp1[0][0][0][0]=1;
	ll k1=0,k2=0,k3=0;
	ll tmax = 0;
	forn(i,n){
		if(b[i]==1) k1++;
		else if(b[i]==2) k2++;
		else k3++;
		rforn(j,min(tmax,t-a[i])){
			rforn(i1,k1){
				rforn(i2,k2){
					rforn(i3,k3){
						if(b[i]==1 && i1>0){
							dp1[i1][i2][i3][j+a[i]] += dp1[i1-1][i2][i3][j];
						}
						else if(b[i]==2 && i2>0){
							dp1[i1][i2][i3][j+a[i]] += dp1[i1][i2-1][i3][j];
						}
						else if(b[i]==3 && i3>0){
							dp1[i1][i2][i3][j+a[i]] += dp1[i1][i2][i3-1][j];
						}
						else{
							continue;
						}
						if(dp1[i1][i2][i3][j+a[i]]){
							tmax = max(tmax,j+a[i]);
							dp1[i1][i2][i3][j+a[i]] %= MOD;
						}
					}
				}
			}
		}
	}
	ll fans = 0;
	ll fact[sz];
	fact[0]=1;
	forsn(i,1,sz) fact[i]=(fact[i-1]*i)%MOD;
	forn(i1,c1+1){
		forn(i2,c2+1){
			forn(i3,c3+1){
				if(dp1[i1][i2][i3][t]==0 || i1+i2+i3==0) continue; 
				// cout << i1 << " " << i2 << " " << i3 << " " << dp1[i1][i2][i3][t] << ln;
				ll ans = dp1[i1][i2][i3][t]*(dp[i1][i2][i3][0]+dp[i1][i2][i3][1]+dp[i1][i2][i3][2]);
				ans %= MOD;
				ans *= fact[i1];
				ans %= MOD;
				ans *= fact[i2];
				ans %= MOD;
				ans *= fact[i3];
				ans %= MOD;
				fans += ans;
				fans %= MOD;
			}
		}
	}
	cout << fans << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}