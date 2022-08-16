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

ll n,m;
const ll maxval = (1<<20);
ll a[2*maxval],s[2*maxval];

void update(ll index, ll val){
	index += maxval;
	a[index]+=val;
	s[index]+=val;
	for(index>>=1;index;index>>=1){
		s[index]=s[index<<1]+s[index<<1|1];
		a[index]=max(a[index<<1|1],s[index<<1|1]+a[index<<1]);
	}
}

ll process(){
	ll ans = 1;
	ll ch = 0;
	if(a[ans]<=ch) return -1;
	while(ans<maxval){
		if(a[(ans<<1|1)]>ch){
			ans = ans<<1|1;
		}
		else{
			ch -= s[ans<<1|1];
			ans = ans<<1;
		}
	}
	return ans-maxval;
}

void solve(){
	cin >> n >> m;
	ll d[n],p[m];
	forn(i,n){
		cin >> d[i];
		update(d[i],1);
	}
	forn(i,m){
		cin >> p[i];
		update(p[i],-1);
	}
	ll q;
	cin >> q;
	forn(i,q){
		ll t1,i1,p1;
		cin >> t1 >> i1 >> p1;
		i1--;
		if(t1==1){
			update(d[i1],-1);
			d[i1]=p1;
			update(d[i1],1);
		}
		else{
			update(p[i1],1);
			p[i1]=p1;
			update(p[i1],-1);
		}
		cout << process() << ln;
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