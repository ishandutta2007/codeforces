#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <fstream>
 
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
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(b >= (MOD-1)) b %= (MOD-1);
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2,p);
	t1 *= t1;
	t1 %= p;
	if(b%2) t1 *= a;
	t1 %= p;
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

ll rev(ll v){
	return mpow(v,MOD-2);
}

ll n,m;
vv64 sum,a,ans,sumans;

ll f(ll i, ll j, ll val, bool bo){
	ll r1=min(n,i+1+val);
	ll r2=max((ll)0,i-val);
	ll c1=min(m,j+1+val);
	ll c2=max((ll)0,j-val);
	if(bo) return sum[r1][c1] - sum[r2][c1] - sum[r1][c2] + sum[r2][c2];
	else return sumans[r1][c1] - sumans[r2][c1] - sumans[r1][c2] + sumans[r2][c2];
}

void construct(ll val){
	ans.clear();
	sumans.clear();
	ans.resize(n,v64(m,0));
	sumans.resize(n+1,v64(m+1,0));
	forn(i,n){
		forn(j,m){
			if(i-val>=0 && i+val<n && j-val>=0 && j+val<m){
				ll temp = f(i,j,val,1);
				if(temp == (2*val+1)*(2*val+1)) ans[i][j]=1;
			}
		}
	}
	forsn(i,1,n+1){
    	forsn(j,1,m+1){
    		sumans[i][j] = ans[i-1][j-1] + sumans[i-1][j] + sumans[i][j-1] - sumans[i-1][j-1];
    	}
    }
}

bool check(ll val){
	construct(val);
	forn(i,n){
		forn(j,m){
			if(a[i][j]==1){
				if(!f(i,j,val,0)) return 0;
			}
		}
	}
	return 1;
}

void solve(){
    cin >> n >> m;
    a.resize(n,v64(m));
    forn(i,n){
    	forn(j,m){
    		char c;
    		cin >> c;
    		if(c=='.') a[i][j]=0;
    		else a[i][j]=1;
    	}
    }
    sum.resize(n+1,v64(m+1,0));
    forsn(i,1,n+1){
    	forsn(j,1,m+1){
    		sum[i][j] = a[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    	}
    }
    ll l = 0,r=(min(n,m)+1)/2;
    while(l!=r){
    	ll mid = (l+r+1)/2;
    	if(check(mid)) l = mid;
    	else r = mid-1;
    }
    cout << l << ln;
    construct(l);
    forn(i,n){
    	forn(j,m){
    		if(ans[i][j]==0) cout << '.';
    		else cout << "X";
    	}
    	cout << ln;
    }
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}