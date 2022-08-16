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
#define INF 1e11
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

ll f(ll a, ll b, ll en, ll ex){
	ll ans = -abs(en-ex);
	ll ma = 0, mi = INF;
	ma = max(ma,a);
	ma = max(ma,b);
	ma = max(ma,en);
	ma = max(ma,ex);
	mi = min(mi,a);
	mi = min(mi,b);
	mi = min(mi,en);
	mi = min(mi,ex);
	ans += 2*(ma-mi);
	return ans;
}

void solve(){
	ll n,m,k,q;
	cin >> n >> m >> k >> q;
	v64 mmin(n+1,m+1);
	v64 mmax(n+1,0);
	ll ans = 0;
	forn(i,k){
		ll r,c;
		cin >> r >> c;
		ans = max(ans,r-1);
		mmin[r]=min(mmin[r],c);
		mmax[r]=max(mmax[r],c);
	}
	// forsn(i,1,n+1) cout << mmin[i] << " " << mmax[i] << ln;
	v64 op;
	forn(i,q){
		ll t;
		cin >> t;
		op.pb(t);
	}
	sort(all(op));
	v64 pr(m+1),nx(m+1);
	ll in = 0;
	forsn(i,1,m+1){
		if(in<q-1 && op[in+1]==i){
			in++;
		}
		pr[i] = op[in];
	}
	in = q-1;
	rforsn(i,m,1){
		if(in>0 && op[in-1]==i){
			in--;
		}
		nx[i] = op[in];
	}
	// forsn(i,1,m+1) cout << pr[i] << " " << nx[i] << ln;
	
	ll val1 = 0,val2=1;
	if(mmax[1]==0){
		val2 = op[0];
		val1 = op[0]-1;
	}
	v64 p(4,val2);
	v64 ans1(4,val1);
	forsn(i,1,ans+2){
		if(mmax[i]!=0){
			v64 tan(4,INF);
			v64 pt(4);
			pt[0]=pr[mmin[i]];
			pt[1]=pr[mmax[i]];
			pt[2]=nx[mmin[i]];
			pt[3]=nx[mmax[i]];
			if(i==ans+1){
				pt[0]=mmin[i];
				pt[1]=mmax[i];
			}
			forn(i1,4){
				forn(j,4){
					tan[j]=min(tan[j],ans1[i1]+f(mmin[i],mmax[i],p[i1],pt[j])); 
				}
			}
			p = pt;
			ans1 = tan;
		}
		// forn(i,4) cout << ans1[i] << " ";
		// cout << ln;
	}
	ll add = INF;
	forn(i,4) add = min(ans1[i],add);
	// cout << ans << " " << add << ln;
	ans += add;
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