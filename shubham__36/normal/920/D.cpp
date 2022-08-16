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
	ll n,k,v;
	cin >> n >> k >> v;
	ll tot = 0;
	ll a[n];
	forn(i,n){
		cin >> a[i];
		tot += a[i];
	}
	if(tot<v){
		cout << "NO" << ln;
		return;
	}
	v64 dp(k,0);
	dp[0]=n+1;
	forn(i,n){
		ll temp = a[i]%k;
		v64 arr(k,0);
		arr = dp;
		forn(j,k){
			if(dp[j]!=0 && dp[(j+temp)%k]==0){
				arr[(j+temp)%k] = i+1;
			}
		}
		dp = arr;
	}
	// forn(i,k) cout << dp[i] << " ";
	// cout << ln;
	if(dp[v%k]==0){
		cout << "NO" << ln;
	}
	else{
		cout << "YES" << ln;
		v64 vec;
		ll temp = v%k;
		while(temp!=0){
			vec.pb(dp[temp]);
			temp -= a[dp[temp]-1];
			temp %= k; 
			if(temp<0) temp+=k;
		}
		v64 vis(n,0);
		ll f=-1,s=-1;
		if((ll)vec.size()){
			f = vec[0]-1;
			vis[f] = 1;
			forsn(i,1,(ll)vec.size()){
				vis[vec[i]-1]=1;
				if(!a[vec[i]-1]) continue;
				cout << (a[vec[i]-1]+k-1)/k << " " << vec[i] << " " << f+1 << ln;
				a[f] += a[vec[i]-1];
				a[vec[i]-1]=0;
			}
		}
		forn(i,n){
			if(!vis[i]){
				if(s==-1){
					s = i;
				}
				else{
					if(!a[i]) continue;
					cout << (a[i]+k-1)/k << " " << i+1 << " " << s+1 << ln;
					a[s]+=a[i];
					a[i]=0;
				}
			}
		}
		if(f==-1){
			if(s-1>=0) f=s-1;
			else f = s+1; 

		}
		else if(s==-1){
			if(f-1>=0) s=f-1;
			else s = f+1;
		}
		if(a[f]<v){
			cout << (v-a[f])/k << " " << s+1 << " " << f+1 << ln;
		}
		else if(a[f]>v){
			cout << (a[f]-v)/k << " " << f+1 << " " << s+1 << ln;
		}
	}
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