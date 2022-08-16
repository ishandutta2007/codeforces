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

const ll N = 1e5+5;
const ll block = 320;
v64 mcount(N,0);
v64 offset(block,0);
v64 mprev(N,0),dp(N,0);
v64 recent(N,0);
ll n,k;
ll ans;
vv64 sum(block,v64 (N,0));

void update(ll st, ll la, ll val){
	if(st<=0 || la<=0) return;
	forn(i,block){
		ll stb = i*block+1,lab = (i+1)*block;
		if(stb > la || lab < st) continue;
		else if(stb>=st && la>=lab){
			if(val==1 && k-offset[i]>=0) ans -= sum[i][k-offset[i]];
			else if(val==-1 && k+1-offset[i]>=0) ans += sum[i][k+1-offset[i]];
			ans = (ans+MOD)%MOD;
			offset[i]+=val;	
		}
		else{
			forsn(j,stb,lab+1){
				if(j<st || j>la) continue;
				if(val==1 && offset[i]+mcount[j]==k) {
					ans-=dp[j-1];
					// cout << ans << ln;
				}
				else if(val==-1 && offset[i]+mcount[j]==k+1) ans+=dp[j-1];
				ans = (ans+MOD)%MOD;
				sum[i][mcount[j]]-=dp[j-1]-MOD;
				sum[i][mcount[j]]%=MOD;
				mcount[j]+=val;
				sum[i][mcount[j]]+=dp[j-1];
				sum[i][mcount[j]]%=MOD;
			}
		}
	}
}

void solve(){
	cin >> n >> k;
	dp[0]=1;
	forsn(i,1,n+1){
		ll a;
		cin >> a;
		ans += dp[i-1];
		ans %= MOD;
		// cout << ans << ln;
		sum[(i-1)/block][0]+=dp[i-1];
		sum[(i-1)/block][0] %= MOD;
		mprev[i]=recent[a];
		update(mprev[i]+1,i,1);
		// cout << ans << ln;
		update(mprev[mprev[i]]+1,mprev[i],-1);
		recent[a]=i;
		dp[i]=ans;
		// cout << ans << ln;
	}
	// forsn(i,1,n+1) cout << dp[i] << " ";
	// cout << ln;
	cout << ans << ln;
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