#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
ll MOD = 1e9+7;
double eps = 1e-12;
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
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(a==0) return 0;
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

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r){
	return l + mt()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

void solve(){
	ll n,m;
	cin >> n >> m;
	ll a[n][m];
	ll r[n],c[m];
	forn(i,n) r[i]=0;
	forn(i,m) c[i]=0;
	ll ans[n][m],nb[n][m];
	ll val[n*m+1];
	forn(i,n){
		forn(j,m){
			cin >> a[i][j];
			nb[i][j]=ans[i][j]=0;
			val[i*m+j+1]=0;
			r[i]=max(r[i],a[i][j]);
			c[j]=max(c[j],a[i][j]);
		}
	}
	sort(r,r+n);
	sort(c,c+m);
	ll ri = n-1, ci = m-1;
	ll cr=-1,cc=-1;
	p64 pos[n*m+1];
	while(ri!=-1 || ci!=-1){
		if(ri==-1){
			cc++;
			ans[cr][cc] = c[ci];
			ci--;
		}
		else if(ci==-1 || (r[ri]>c[ci])){
			cr++;
			ans[cr][cc] = r[ri];
			ri--;
		}
		else if(c[ci]>r[ri]){
			cc++;
			ans[cr][cc] = c[ci];
			ci--;
		}
		else{
			cr++;
			cc++;
			ans[cr][cc] = r[ri];
			ri--;
			ci--;
		}
		pos[ans[cr][cc]] = mp(cr,cc);
		val[ans[cr][cc]] = 1;
	}
	// forn(i,n){
	// 	forn(j,m) cout << ans[i][j] << " ";
	// 	cout << ln; 
	// }
	vp64 diff;
	diff.pb(mp(-1,0));
	diff.pb(mp(1,0));
	diff.pb(mp(0,-1));
	diff.pb(mp(0,1));
	vp64 vec;
	rforsn(k,n*m,1){
		if(!val[k]){
			assert(sz(vec));
			p64 lst = vec.back();
			vec.pop_back();
			ans[lst.fi][lst.se]=k;
			for(auto it : diff){
				ll nx = (lst.fi+it.fi) , ny = (lst.se+it.se);
				if(nx>=0 && nx<n && ny>=0 && ny<m){
					nb[nx][ny]++;
					if(nb[nx][ny]==2 && !ans[nx][ny]) vec.pb(mp(nx,ny));
				}
			}
		}
		else{
			p64 lst = pos[k];
			for(auto it : diff){
				ll nx = (lst.fi+it.fi) , ny = (lst.se+it.se);
				if(nx>=0 && nx<n && ny>=0 && ny<m){
					nb[nx][ny]++;
					if(nb[nx][ny]==2 && !ans[nx][ny]) vec.pb(mp(nx,ny));
				}
			}
		}
	}
	forn(i,n){
		forn(j,m) cout << ans[i][j] << " ";
		cout << ln; 
	}
}
 
int main()
{
	fast_cin();
	ll t=1;
    // cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}