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
	ll h,w;
	cin >> h >> w;
	char c[h][w];
	p64 l=mp(INF,INF),u=mp(INF,INF);
	forn(i,h){
		forn(j,w){
			cin >> c[i][j];
			if(c[i][j]=='*'){
				l = min(l,mp(j,i));
				u = min(u,mp(i,j));
			}
		}
	}
	if(l.fi >= w){
		cout << "NO" << ln;
		return;
	}
	p64 cen = mp(l.se,u.se);
	if(cen.fi-1 >= 0 && c[cen.fi-1][cen.se]=='*'){
		if(cen.fi+1 < h && c[cen.fi+1][cen.se]=='*'){
			if(cen.se-1 >= 0 && c[cen.fi][cen.se-1]=='*'){
				if(cen.se+1 < w && c[cen.fi][cen.se+1]=='*'){
					bool bo = true;
					forn(i,h){
						forn(j,w){
							if(c[i][j]=='*' && (i!=cen.fi && j!=cen.se)) bo=false;
						}
					}
					forsn(i,u.fi,h-1){
						if(c[i][cen.se]=='.' && c[i+1][cen.se]=='*') bo=false;
					}
					forsn(i,l.fi,w-1){
						if(c[cen.fi][i]=='.' && c[cen.fi][i+1]=='*') bo=false;
					}
					if(bo) {
						cout << "YES" << ln;
						return;
					}
				}
			}
		}
	}
	cout << "NO" << ln;
	return;
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