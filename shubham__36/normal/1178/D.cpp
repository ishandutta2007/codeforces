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

void solve(){
	ll val = 1050;
	ll a[val];
	forn(i,val) a[i]=1;
	a[0]=0;
	a[1]=0;
	a[2]=1;
	forsn(i,2,val){
		if(a[i]==1){
			if(2*i>=val) break;
			for(ll j=2*i;j<val;j+=i){
				a[j]=0;
			}
		}
	}
	ll n;
	cin >> n;
	ll m = 0;
	forsn(i,n,(3*n+1)/2){
		if(a[i]==1){
			m = i;
			break;
		}
	}
	// forsn(i,3,lim){
	// 	bool bo = 0;
	// 	forsn(j,i,(3*i+1)/2){
	// 		if(j>=val || a[j]==1) bo=1; 
	// 	}
	// 	if(!bo) cout << i << " ";
	// }
	// cout << ln;
	cout << m << ln;
	m *= 2;
	ll t1 = m;
	ll deg[n];
	ll rem = n;
	forn(i,n){
		deg[i] = m/rem;
		m -= deg[i];
		rem--;
	}
	// forn(i,n) cout << deg[i] << " ";
	// cout << ln;
	ll in = 0;
	ll v1,v2;
	v64 vec(n);
	forn(i,n) vec[i]=i;
	m = t1;
	while(m>2*n){
		// cout << in << ln;
		forsn(i,in,n){
			in++; 
			if(deg[i]==3) {
				// cout << i << ln;
				v1=i;
				break;
			}
		}
		// cout << in << " " << v1 << ln;
		forsn(i,in,n){
			in++; 
			if(deg[i]==3) {
				v2=i;
				break;
			}
		}
		// cout << in << " " << v2 << ln;
		cout << v1+1 << " " << v2+1 << ln;
		if(v1+1 == v2 && vec[v1]==v1 && vec[v2]==v2){
			swap(vec[v2],vec[(v2+1)%n]);
		}
		m-=2;
	}
	forn(i,n){
		cout << vec[i]+1 << " " << vec[(i+1)%n]+1 << ln;
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