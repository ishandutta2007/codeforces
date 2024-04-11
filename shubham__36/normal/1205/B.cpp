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
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll mpow(ll a, ll b){
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
	ll t1 = mpow(a,b/2);
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

ll msz = 120;
vv64 gr(msz,v64(msz,0));

void solve(){
	ll n;
	cin >> n;
	v64 num(msz/2,0);
	ll a[n];
	forn(i,n){
		cin >> a[i];
		forn(j,60){
			if(1LL<<j & a[i]){
				num[j]++;
			}
		}
	}
	v64 in;
	forn(i,msz/2){
		if(num[i]>2){
			cout << 3 << ln;
			return;
		}
		else if(num[i]==2){
			in.pb(i);
		}
	}
	// forn(i,sz(in)) cout << in[i] << " ";
	// cout << ln;
	ll curin=0;
	unordered_map<ll,ll> mp1;
	unordered_map<ll,ll> tl;
	forn(i,n){
		bool bo=0;
		forn(j,sz(in)){
			if(1LL<<in[j] & a[i]){
				if(!bo) {
					mp1[i]=curin++;
					bo=1;
				}
				if(tl.find(j)!=tl.end()){
					// cout << i << " " << j << " " << tl[j] << " " << mp1[i] << ln;
					gr[tl[j]][mp1[i]]=1;
					gr[mp1[i]][tl[j]]=1;
				}
				tl[j]=mp1[i];
			}
		}
	}
	// forn(i,4) {
	// 	forn(j,4) cout << gr[i][j] << " ";
	// 	cout << ln;
	// }
	ll ans = INF;
	forn(i,msz){
		queue<p64> q;
		vector<ll> dp(msz,0);
		q.push(mp(i,0));
		vv64 mark(msz,v64(msz,0));
		while(sz(q)!=0){
			p64 now = q.front();
			q.pop();
			ll v = now.fi;
			bool bo=0;
			forn(j,msz){
				if(gr[v][j]==1 && mark[v][j]==0){
					mark[v][j]=1;
					mark[j][v]=1;
					if(dp[j]!=0){
						ans = min(ans,dp[j]+now.se+1);
						bo=1;
						break;
					}
					else{
						dp[j] = now.se+1;
						q.push(mp(j,now.se+1));
					}
				}
			}
			if(bo) break;
		}
	}
	if(ans<=n) cout << ans << ln;
	else cout << -1 << ln;
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