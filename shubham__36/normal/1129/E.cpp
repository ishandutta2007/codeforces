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

set<ll> s;

ll bs(ll val, ll v, ll l, ll r){
	if(l==r) return l;
	ll mid = (l+r)/2;
	cout << mid + 1 << " ";
	ll temp=mid;
	for(auto it : s){
		cout << it << " ";
		if(!temp) break;
		temp--;
	}
	cout << endl;
	cout << 1 << " " << 1 << endl;
	cout << v << endl;
	ll ans;
	cin >> ans;
	if(ans >= val) return bs(val,v,l,mid);
	else return bs(val,v,mid+1,r);
}

void solve(){
	ll n;
	cin >> n;
	ll sz[n+1];
	ll pr[n+1];
	forsn(i,1,n+1) pr[i]=-1;
	sz[1]=n;
	forsn(j,2,n+1){
		cout << n-1 << " ";
		forsn(i,2,n+1) cout << i << " ";
		cout << endl;
		cout << 1 << " " << 1 << endl;
		cout << j << endl;
		cin >> sz[j];
	}
	v64 vec(n);
	iota(ALL(vec),1);
	sort(ALL(vec),[&](ll a, ll b){
		return sz[a]<sz[b];
	});
	forn(i,n-1){
		ll temp = sz[vec[i]]-1;
		while(temp!=0){
			ll ans = bs(1,vec[i],0,(ll)s.size()-1);
			ll ele;
			for(auto it : s){
				if(!ans){
					ele = it;
					break;
				}
				ans--;
			}
			pr[ele]=vec[i];
			s.erase(ele);
			temp -= sz[ele];
		}
		s.insert(vec[i]);
	}
	cout << "ANSWER" << endl;
	forsn(i,2,n+1){
		cout << (pr[i]==-1 ? 1 : pr[i]) << " " << i << endl;
 	}
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