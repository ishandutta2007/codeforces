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
#include <fstream>

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
#define INF 1e18
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

ll query(ll x1, ll x2, ll x3, ll x4){
	cout << "? " << x1+1 << " " << x2+1 << " " << x3+1 << " " << x4+1 << endl;
	ll ans;
	cin >> ans;
	return ans;
}

void solve(){
	ll n;
	cin >> n;
	vv64 a(n,v64(n,-1));
	a[0][0]=1;
	a[n-1][n-1]=0;
	a[1][0]=1;
	if(query(1,0,1,2)) a[1][2]=1;
	else a[1][2]=0;
	if(query(0,1,1,2)) a[0][1]=a[1][2];
	else a[0][1]=1-a[1][2];
	forn(i,n){
		forn(j,n){
			if(a[i][j]==-1){
				if(i && j){
					if(query(i-1,j-1,i,j)) a[i][j]=a[i-1][j-1];
					else a[i][j]=1-a[i-1][j-1];
				}
				else if(i>1){
					if(query(i-2,j,i,j)) a[i][j]=a[i-2][j];
					else a[i][j]=1-a[i-2][j];
				}
				else{
					if(query(i,j-2,i,j)) a[i][j]=a[i][j-2];
					else a[i][j]=1-a[i][j-2];
				}
			}
		}
	}
	ll add;
	forn(i,n-2){
		if(a[i+1][i+1]==a[i+2][i+2] && a[i][i]!=a[i+1][i+1]){
			if(a[i+1][i]==a[i+1][i+2]){
				if(query(i+1,i,i+2,i+2)) add = (a[i+1][i]!=a[i+2][i+2]);
				else add = (a[i+1][i]==a[i+2][i+2]);
			}
			else{
				if(query(i,i,i+1,i+2)) add = (a[i][i]!=a[i+1][i+2]);
				else add = (a[i][i]==a[i+1][i+2]);
			}
			break;
		}
		else if(a[i+1][i+1]!=a[i+2][i+2] && a[i][i]==a[i+1][i+1]){
			if(a[i+1][i]==a[i+1][i+2]){
				if(query(i,i,i+1,i+2)) add = (a[i+1][i+2]!=a[i][i]);
				else add = (a[i+1][i+2]==a[i][i]);
			}
			else{
				if(query(i+1,i,i+2,i+2)) add = (a[i+1][i]!=a[i+2][i+2]);
				else add = (a[i+1][i]==a[i+2][i+2]);
			}
			break;
		}
	}
	cout << "!" << endl;
	forn(i,n){
		forn(j,n){
			if((i+j)%2) cout << (a[i][j]^add);
			else cout << a[i][j];
		}
		cout << endl;
	}
}

int main()
{
	// fast_cin();
    ll t=1;
	// cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}