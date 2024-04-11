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
	ll n,m;
	cin >> n >> m;
	v64 a,b;
	char c1[n][m],c2[m][n];
	forn(i,n) forn(j,m) cin >> c1[i][j];
	forn(i,m) forn(j,n) cin >> c2[i][j];
	ll no = 3;
	ll bo = 5;
	ll nop[26];
	forn(i,26){
		nop[i]=mpow(i+1,no);
	}
	// cout << 1 << ln;
	forn(i,n-m+1){
		ll temp = 1;
		forsn(j,i,i+m){
			temp *= bo;
			temp %= MOD;
			ll temp1 = 1;
			ll in = 0;
			forn(k,m){
				temp1 *= no;
				temp1 += nop[c1[j][k]-'a'];
				if(in%10==1) temp1 %= MOD;
				in++;
			}
			temp1 %= MOD;
			temp += mpow(temp1,bo);
			temp %= MOD;
		}
		a.pb(temp);
	}
	// cout << 2 << ln;
	forn(i,n-m+1){
		ll temp = 1;
		forn(j,m){
			temp *= bo;
			ll temp1 = 1;
			ll in = 0;
			forsn(k,i,i+m){
				temp1 *= no;
				temp1 += nop[c2[j][k]-'a'];
				if(in%10==1) temp1 %= MOD;
				in++;
			}
			temp1 %= MOD;
			temp += mpow(temp1,bo);
			temp %= MOD;
		}
		b.pb(temp);
	}
	// cout << 3 << ln;
	forn(i,n-m+1){
		forn(j,n-m+1){
			if(a[i]==b[j]){
				bool bo = 0;
				forn(k,m){
					forn(t,m){
						if(c1[i+k][t]!=c2[k][j+t]){
							bo = 1;
							break;
						}
					}
					if(bo) break;
				}
				if(bo) continue;
				cout << i+1 << " " << j+1 << ln;
				return;
			}
		}
	}
}


int main()
{
	fast_cin();
    ll t=1;
    forn(i,t) {
    	solve();
    }
    return 0;
}