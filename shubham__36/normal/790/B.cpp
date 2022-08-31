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

vv64 gr;
ll ans;
vv64 dp,mcount;
ll n,k;

void dfs(ll v, ll p){
	mcount[v][0]++;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]==p) continue;
		dfs(gr[v][i],v);
		ll t1[k],t2[k];
		forn(j,k){
			if(j==((k+1)%k)){
				t1[j]=mcount[gr[v][i]][(j-1+k)%k];
				t2[j]=dp[gr[v][i]][(j-1+k)%k]+mcount[gr[v][i]][(j-1+k)%k];
				// cout << j << " " << t1[j] << " " << t2[j] << ln;
			}
			else{
				// cout << "entered2" << ln;
				t1[j]=mcount[gr[v][i]][(j-1+k)%k];
				t2[j]=dp[gr[v][i]][(j-1+k)%k];
			}
		}
		forn(j,k){
			forn(l,k){
				ans += dp[v][j]*t1[l];
				ans += t2[l]*mcount[v][j];
				if(j+l<=k && j!=0 && l!=0){
					ans -= mcount[v][j]*t1[l];
				}
			}
		}
		forn(j,k){
			mcount[v][j]+=t1[j];
			dp[v][j]+=t2[j];
		}
	}
	// cout << v << " " << ans << ln;
}

void solve(){
	cin >> n >> k;
	gr.resize(n);
	dp.resize(n,v64(k,0));
	mcount.resize(n,v64(k,0));
	forn(i,n-1){
		ll a,b;
		cin >> a >> b;
		a--,b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs(0,-1);
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