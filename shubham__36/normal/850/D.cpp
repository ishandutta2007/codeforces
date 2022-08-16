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

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll dp[65][35][1850];
ll p[65];
ll win[65];

bool cmp(ll x, ll y){
	return win[x]<win[y];
}

void solve(){
	ll m;
	cin >> m;
	ll a[m+1];
	forn(i,m){
		cin >> a[i+1];
	}
	sort(a+1,a+m+1);
	forn(i,65){
		forn(j,35){
			forn(k,1850) dp[i][j][k]=-1;
		}
	}
	dp[0][0][0]=1;
	forsn(i,1,62){
		forsn(j,1,m+1){
			forsn(k,(i*(i-1))/2,1850){
				if(k-a[j]<((i-2)*(i-1))/2) continue;
				if(dp[i-1][j-1][k-a[j]]!=-1){
					dp[i][j][k]=j-1;
				}
				else if(dp[i-1][j][k-a[j]]!=-1){
					dp[i][j][k]=j;
				}
			}
		}
	}
	ll n=-1;
	forsn(i,m,62){
		if(dp[i][m][(i*(i-1))/2]!=-1){
			n = i;
			break;
		}
	}
	if(n==-1){
		cout << "=(" << ln;
		return;
	}
	ll tot = (n*(n-1))/2;
	ll j = m;
	rforsn(i,n,1){
		ll in = dp[i][j][tot];
		win[i]=a[j];
		tot -= a[j];
		j = in;
	}
	// forsn(i,1,n+1){
	// 	cout << win[i] << " ";
	// }
	// cout << ln;
	ll ans[n+1][n+1];
	forn(i,n+1) ans[i][i]=0;
	forsn(i,1,n+1) p[i]=i; 
	forsn(i,1,n+1){
		sort(p+i,p+n+1,cmp);
		ll temp = win[p[i]];
		forsn(j,i+1,n+1){
			if(temp){
				ans[p[j]][p[i]]=0;
				ans[p[i]][p[j]]=1;
				temp--;
			}
			else{
				ans[p[j]][p[i]]=1;
				ans[p[i]][p[j]]=0;
				win[p[j]]--;
			}
		}
	}
	cout << n << ln;
	forsn(i,1,n+1){
		ll coun = 0;
		forsn(j,1,n+1) {
			if(ans[i][j]==1) coun++;
			cout << ans[i][j];
		}
		// cout << " " << coun;
		cout << ln;
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