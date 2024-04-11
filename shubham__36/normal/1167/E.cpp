#include <bits/stdc++.h>
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

void solve(){
	ll n,x;
	cin >> n >> x;
	ll a[n];
	set<ll> s;
	ll l[x],r[x];
	forn(i,x) l[i]=-1,r[i]=-1;
	bool bo=false;
	forn(i,n) {
		cin >> a[i];
		if(i!=0 && a[i]<a[i-1]) bo=true;
		set<ll>::iterator it;
		if((ll)s.size()>0){
			it = s.upper_bound(a[i]-1);
			if(it!=s.end()){
				if(l[a[i]-1]==-1 || l[a[i]-1]>*it) l[a[i]-1]=*it;
			}
		
			it = s.end();
			it--;
			if(*it>a[i]-1 && (r[a[i]-1]==-1 || r[a[i]-1]<*it))r[a[i]-1]=*it;
		}
		s.insert(a[i]-1);
	}
	// forn(i,x) cout << l[i] << " " << r[i] << ln;
	if(bo){
		ll ans = 0;
		rforn(i,x-1){
			if(l[i]==-1) ans++;
			else {
				break;
			}
		}
		ans++;
		ll fans=ans;
		ll fl = -1, fr = -1;
		forn(i,x){
			// cout << fans << ln;
			if(l[i]!=-1){
				if(fl==-1 || fl>l[i]){
					fl = l[i];
				}
				if(fr==-1 || fr<r[i]){
					fr = r[i];
				}
			}
			
			if(fl!=-1){
				ans = min(x-fr,ans);
				if(fl<=i) ans=0;
			}
			ans = min(ans,x-i);	
			
			fans+=ans;
		}
		cout << fans << ln;
	}
	else{
		cout << ((x+1)*x)/2 << ln;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    forn(i,t) solve();
    return 0;
}