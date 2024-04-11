#include <bits/stdc++.h>
#include <iomanip> 
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

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
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
ll MOD = 998244352;
ll p = 998244353;
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
#define MAX 300000
ll k;
vv64 mat; 
vv64 a;
vv64 c;

void mult(){
	forn(i,k){
		forn(j,k){
			c[i][j]=0;
			forn(t,k){
				c[i][j]+=a[i][t]*mat[t][j];
				c[i][j]%=MOD;
			}
		}
	}
	forn(i,k){
		forn(j,k){
			a[i][j]=c[i][j];
		}
	}
}

void sq(){
	forn(i,k){
		forn(j,k){
			c[i][j]=0;
			forn(t,k){
				c[i][j]+=(a[i][t]*a[t][j]);
				c[i][j]%=MOD;
			}
		}
	}
	forn(i,k){
		forn(j,k){
			a[i][j]=c[i][j];
		}
	}
}

void mpow(ll p){
	if(p==1) return;
	if(p%2){
	   // sq();
    	mpow(p/2);
		sq();
		mult();
		return;
	}
	else{
	   // sq();
		mpow(p/2);
		sq();
		return;
	}
}

ll modular_pow(ll a, ll b){
	if(b==0) return 1;
	if(b==1) return a;
	b%=MOD;
	ll temp = modular_pow(a,b/2);
	if(b%2){
		return (a*((temp*temp)%p))%p;
	}
	else {
		return (temp*temp)%p;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    mat.resize(k,vector<ll>(k));
    a.resize(k,vector<ll>(k));
    c.resize(k,vector<ll>(k));
    forn(i,k){
    	forn(j,k){
    		if(i==0) {cin >> mat[i][j]; mat[i][j]%=MOD;}
    		else if(i==j+1) mat[i][j]=1;
    		else mat[i][j]=0;
    	}
    }
    forn(i,k){
    	forn(j,k){
    		a[i][j]=mat[i][j];
    	}
    }
    ll n,m;
    cin >> n >> m;
    mpow(n-k);
    // cout << a[0][0] << ln;
    ll k = modular_pow(3,a[0][0]);
    ll fa = sqrt(MOD)+1;
    vector<p64 > v1,v2;
    forn(i,fa+1){
    	if(i==0) continue;
    	v1.pb(mp(modular_pow(k,i*fa),i));
    }
    forn(j,fa){
    	v2.pb(mp((modular_pow(k,j)*m)%p,j));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ll in1=0,in2=0;
    ll ans=-1;
    while(in1<fa && in2<fa){
    	if(v1[in1].fi==v2[in2].fi){
    		ans=v1[in1].se*fa-v2[in2].se;
    		break;
    	}
    	else if(v1[in1].fi<v2[in2].fi) in1++;
    	else in2++;
    }
    if(ans == -1){
    	cout << -1 << ln;
    }
    else{
        ans %= MOD;
    	ll ku = modular_pow(3,ans);
    	cout << ku << ln;
    // 	cout << modular_pow(ku,a[0][0]) << ln;
    }
    return 0;
}