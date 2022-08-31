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
ll MOD = 1e13+7;
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

ll modinverse(ll a, ll m){
	ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}

ll range(ll l, ll r){
	return l + rand()%(r-l+1);
}

ll n;
string s;
ll in1,in2,in3;
const ll maxn = 80;
ll dp[maxn][maxn][maxn][2];
v64 v,k,o;

ll f(ll i, ll j, ll k1, ll m){
	ll ans = 0;
	while(i<(ll)v.size() && v[i]<m){
		ans++;
		i++;
	}
	while(j<(ll)k.size() && k[j]<m){
		ans++;
		j++;
	}
	while(k1<(ll)o.size() && o[k1]<m){
		ans++;
		k1++;
	}
	return ans;
}

void solve(){
	cin >> n;
	cin >> s;
	forn(i,maxn){
		forn(j,maxn){
			forn(k1,maxn){
				forn(t,2){
					dp[i][j][k1][t]=INF;
				}
			}
		}
	}
	forn(i,n){
		if(s[i]=='V') v.pb(i);
		else if(s[i]=='K') k.pb(i);
		else o.pb(i);
	}
	dp[0][0][0][1]=0;
	forn(i,(ll)v.size()+1){
		forn(j,(ll)k.size()+1){
			forn(k1,(ll)o.size()+1){
				forn(t,2){
					if(dp[i][j][k1][t]==INF) continue;
					if(i<(ll)v.size()) dp[i+1][j][k1][0] = min(dp[i+1][j][k1][0],dp[i][j][k1][t]+f(i,j,k1,v[i]));
					if(j<(ll)k.size() && t==1) dp[i][j+1][k1][1] = min(dp[i][j+1][k1][1],dp[i][j][k1][t]+f(i,j,k1,k[j]));
					if(k1<(ll)o.size()) dp[i][j][k1+1][1] = min(dp[i][j][k1+1][1],dp[i][j][k1][t]+f(i,j,k1,o[k1]));
				}
			}
		}
	}
	ll ans = INF;
	forn(t,2){
		ans = min(ans,dp[(ll)v.size()][(ll)k.size()][(ll)o.size()][t]);
	}
	cout << ans << ln;
}


int main()
{
	fast_cin();
    ll t=1;
    forn(i,t) {
    	solve();
    }
    return 0;
}