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
	ll n,m;
	cin >> n >> m;
	p64 a[26],b[26];
	p64 emp = mp(-1,-1);
	forn(i,26) a[i]=b[i]=emp;
	bool bo=1;
	ll m1 = 0;
	p64 per = emp;
	char arr[n][m];
	forn(i,n) forn(j,m) {
		char c;
		cin >> c;
		arr[i][j]=c;
		if(c!='.'){
			if(m1<c-'a'+1){
				m1 = c-'a'+1;
				per = mp(i+1,j+1);
			}
			if(a[c-'a']==emp){
				a[c-'a']=mp(i+1,j+1);
				b[c-'a']=mp(i+1,j+1);
			} 
			else if(a[c-'a']==b[c-'a']){
				b[c-'a']=mp(i+1,j+1);
			}
			else if(a[c-'a'].fi==b[c-'a'].fi && a[c-'a'].fi==i+1){
				b[c-'a']=mp(i+1,j+1);
			}
			else if(a[c-'a'].se==b[c-'a'].se && a[c-'a'].se==j+1){
				b[c-'a']=mp(i+1,j+1);
			}
			else bo=0;
		}
	}
	if(bo){
		char c[n][m];
		forn(i,n) forn(j,m) c[i][j]='.';
		forn(i,m1){
			if(!(a[i]==emp)){
				if(a[i].fi==b[i].fi){
					forsn(k,a[i].se-1,b[i].se){
						c[a[i].fi-1][k]='a'+i;
					}
				}
				else if(a[i].se==b[i].se){
					forsn(k,a[i].fi-1,b[i].fi){
						c[k][a[i].se-1]='a'+i;
					}
				}
			}
		}
		forn(i,n) forn(j,m){
			if(arr[i][j]!=c[i][j]){
				cout << "NO" << ln;
				return;
			}
		}
		cout << "YES" << ln;
		cout << m1 << ln;
		forn(i,m1){
			if(a[i]==emp){
				cout << per.fi << " " << per.se << " " << per.fi << " " << per.se << " " << ln;
			}
			else{
				cout << a[i].fi << " " << a[i].se << " " << b[i].fi << " " << b[i].se << ln;
			}
		}
	}
	else{
		cout << "NO" << ln;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}