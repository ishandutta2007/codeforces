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
	ll n,m;
	cin >> n >> m;
	ll a[n],b[n];
	ll lim = (1<<9);
	ll dp1[lim];
	p64 dp2[lim];
	ll bmask[m];
	forn(j,lim) dp1[j]=0;
	forn(j,lim) dp2[j]=mp(0,0);
	forn(i,n) {
		ll sz;
		cin >> sz;
		ll lmask=0;
		forn(j,sz) {
			ll t1;
			cin>>t1;
			t1--;
			lmask += (1<<t1);
		}
		v64 v;
		v.pb(lmask);
		forn(i,9){
			if(!(lmask & (1<<i))){
				ll sz = (ll)v.size();
				forn(j,sz){
					v.pb(v[j]|(1<<i));
				}
			}
		}
		forn(j,(ll)v.size()) dp1[v[j]]++;
	}
	ll p[m];
	forn(i,m) {
		ll price;
		cin >> price;
		p[i]=price;
		ll sz;
		cin >> sz;
		ll lmask=0;
		forn(j,sz) {
			ll t1;
			cin>>t1;
			t1--;
			lmask += (1<<t1);
		}
		bmask[i]=lmask;
		v64 v;
		v.pb(lmask);
		forn(i,9){
			if((lmask & (1<<i))){
				ll sz = (ll)v.size();
				forn(j,sz){
					v.pb(v[j]^(1<<i));
				}
			}
		}
		forn(j,(ll)v.size()) if(price<dp2[v[j]].fi || dp2[v[j]].fi==0) dp2[v[j]]=mp(price,i);
	}
	ll totalhappy=0,totalcost=INF;
	ll index1=0,index2=0;
	forn(i,m){
		forn(j,(1<<9)){
			ll reqmask = ((1<<9)-1-bmask[i])&(j);
			if(dp2[reqmask].fi==0) continue;
			if(dp1[j]>totalhappy || (dp1[j]==totalhappy && (p[i]+dp2[reqmask].fi<totalcost))){
				totalhappy=dp1[j];
				totalcost=p[i]+dp2[reqmask].fi;
				index1=i+1,index2=dp2[reqmask].se+1;
			}
		}
	}
	if(index1!=index2) {
		cout << index1 << " " << index2 << ln;
		return;
	}
	ll cm = INF;
	forn(i,m){
		if(cm>p[i] && i+1!=index1){
			cm = p[i];
			index2 = i+1;
		}
	}
	cout << index1 << " " << index2 << ln;
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