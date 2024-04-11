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
	ll n;
	cin >> n;
	vector<p64> a;
	vector<p64> b;
	ll sum1 = 0, sum2=0;
	forn(i,n){
		ll t1;
		cin >> t1;
		sum1+=t1;
		a.pb(mp(t1,i+1));
	}
	forn(i,n){
		ll t1;
		cin >> t1;
		sum2+=t1;
		b.pb(mp(t1,i+1));
	}
	if(sum1!=sum2){
		cout << "NO" << ln;
	}
	else{
		bool bo=false;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll nx[n];
		ll s1=-1,sn1=5*n;
		ll pr1=-1,prn1=-1;
		forn(i,n){
			if(a[i].fi > b[i].fi) {
				if(pr1!=-1) nx[pr1]=i;
				if(s1==-1) s1=i;
				pr1 = i;
			}
			else {
				if(prn1!=-1) nx[prn1]=i;
				if(sn1==5*n) sn1=i;
				prn1 = i;
			}
		}
		if(pr1!=-1) nx[pr1]=-1;
		if(prn1!=-1) nx[prn1]=5*n;
		ll in1s=sn1,in1e=s1;
		ll in2s=sn1,in2e=s1;
		vv64 v;
		while(in1s<in1e){
			bool b1 = false;
			if(a[in1s].fi == b[in2s].fi){
				in1s=nx[in1s];
				in2s=nx[in2s];
				b1 = true;
			}
			if(a[in1e].fi == b[in2e].fi){
				in1e=nx[in1e];
				in2e=nx[in2e];
				b1 = true;
			}
			if(!b1){
				v64 temp;
				ll val = min(b[in2s].fi-a[in1s].fi,a[in1e].fi-b[in1e].fi);
				if(val<0) bo = true;
				temp.pb(a[in1s].se);
				temp.pb(a[in1e].se);
				temp.pb(val);
				a[in1s] = mp(a[in1s].fi + val,a[in1s].se);
				a[in1e] = mp(a[in1e].fi - val,a[in1e].se);
				v.pb(temp);
			}
		}
		forn(i,n){
			if(a[i].fi != b[i].fi) bo=true;
		}
		if(bo){
			cout << "NO" << ln;
		}
		else{
			cout << "YES" << ln;
			cout << (ll)v.size() << ln;
			forn(i,(ll)v.size()){
				cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << ln;
			}
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
    forn(i,t) solve();
    return 0;
}