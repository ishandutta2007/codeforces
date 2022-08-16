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
ll MOD = 1000000007;
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

struct mat{
	long long d[105][105];
};
mat mat1,fmat,c;
ll m;


inline void mul(mat &a,mat &b){
	forn(i,m+1)
		forn(j,m+1){
			c.d[i][j]=0;
			forn(k,m+1) c.d[i][j]+=a.d[i][k]*b.d[k][j]%MOD;
			c.d[i][j]%=MOD;
		}
	a=c;
	// return 0;
}

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	if(b%2){
		return (((t1*t1)%MOD)*a)%MOD;
	}
	else return (t1*t1)%MOD;
}

void solve(){
    ll n,k;
    cin >> n >> k;
    ll a[n];
    m=0;
    forn(i,n){
    	cin >> a[i];
    	if(a[i]==0) m++;
    }
    ll c=0;
    forn(i,m){
    	if(a[i]==0) c++;
    }
    // cout << "m = " << m << ln;
    // cout << "c = " << c << ln;
    // ll dp[n+1];
    // forn(i,n+1) dp[i]=0;
    // dp[c2]=1;
    forn(i,m+1) fmat.d[i][i]=1;
    ll t1 = n*(n-1)/2;
    t1%=MOD;
    ll fact = mpow(t1,MOD-2);
    forn(i,m+1){
    	if(i) mat1.d[i][i-1]=(m-i+1)*(m-i+1)*fact%MOD;
    	if(i<m+1) mat1.d[i][i+1]=(i+1)*(n-m-(m-i-1))*fact%MOD;
    	mat1.d[i][i]=((m*(m-1)/2)+((n-m)*((n-m)-1)/2)+(i*(m-i))+((m-i)*(n-m-(m-i))))*fact%MOD;
    }
    // forn(i,m+1){
    // 	forn(j,m+1){
    // 		cout << mat1.d[i][j] << " ";
    // 	}
    // 	cout << ln;
    // }
    // forn(i,m+1){
    // 	forn(j,m+1){
    // 		cout << fmat.d[i][j] << " ";
    // 	}
    // 	cout << ln;
    // }
    while(k){
    	if(k&1) mul(fmat,mat1);
    	mul(mat1,mat1);
    	k>>=1;
    } 
    // forn(i,m+1){
    // 	forn(j,m+1){
    // 		cout << fmat.d[i][j] << " ";
    // 	}
    // 	cout << ln;
    // }
    cout << fmat.d[m][c] << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}