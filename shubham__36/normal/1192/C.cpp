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

ll f(char c){
	if(c-'a'>=0 && c-'a'<=25){
		return c-'a';
	}
	else if(c-'A'>=0 && c-'A'<=25){
		return 26+c-'A';
	}
	else{
		return 52+c-'0';
	}
}

ll no[64][64][8];
ll dp[64][64][64][8];

ll fact(ll val){
	if(val==1) return 1;
	else if(val==2) return 2;
	else if(val==3) return 6;
	else return 24;
}

ll nop(ll a, ll b, ll c, ll d){
	ll ans = 24;
	ll c1 = 1;
	if(a==b){
		c1++;
	}
	else{
		ans /= fact(c1);
		c1=1;
	}
	if(c==b){
		c1++;
	}
	else{
		ans /= fact(c1);
		c1=1;
	}
	if(c==d){
		c1++;
	}
	else{
		ans /= fact(c1);
		c1=1;
	}
	ans /= fact(c1);
	return ans;
}

void solve(){
	ll n;
	cin >> n;
	set<string> s;
	forn(i,n){
		string temp;
		cin >> temp;
		s.insert(temp);
		reverse(all(temp));
		s.insert(temp);
	}
	for(auto it : s){
		no[f(it[0])][f(it[sz(it)-1])][sz(it)-3]++;
	}
	// cout << 1 << ln;
	forn(i,8){
		forn(j,64){
			forsn(k,j,64){
				forsn(l,k,64){
					forn(p,64){
						dp[j][k][l][i]+=no[p][j][i]*no[p][k][i]*no[p][l][i];
						dp[j][k][l][i]%=MOD;
					}
				}
			}
		}
	}
	// cout << 2 << ln;
	ll ans = 0;
	forn(i,8){
		forn(j,64){
			forsn(k,j,64){
				forsn(l,k,64){
					forsn(p,l,64){
						ans += nop(j,k,l,p)*((((dp[j][k][l][i]*dp[j][k][p][i])%MOD)*((dp[j][l][p][i]*dp[k][l][p][i])%MOD))%MOD);
						ans %= MOD;
					}
				}
			}
		}
	}
	cout << ans << ln;
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