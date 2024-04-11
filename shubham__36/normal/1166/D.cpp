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


void solve(){
	ll a,b,m;
	cin >> a >> b >> m;
	if(b<a){
		cout << -1 << ln;
	}
	else if(b==a){
		cout << 1 << " " << a << ln;
	}
	else{
		ll a1=a+1,a2=a+m;
		while(true){
			if((a1<=b && a2>=b) || a1>b){
				break;
			}
			a1*=2;
			a2*=2;
		}
		if(a1<=b && a2>=b){
			ll l=1,r=m;
			while(l!=r){
				ll mid=(l+r)/2;
				ll tmp1 = (a1/(a+1))*(a+mid);
				if(tmp1>=b) r=mid;
				else l=mid+1;
			}
			ll tmp1 = (a1/(a+1))*(a+l);
			if(tmp1>b){
				l--;
				tmp1 = (a1/(a+1))*(a+l);
			}
			// cout << a1 << " " << a2 << " " << l << ln;
			ll temp1 = a+l;
			vector<ll> v;
			v.pb(a);
			v.pb(temp1);
			while(temp1!=tmp1){
				temp1*=2;
				v.pb(temp1);
			}
			ll ex = b-tmp1;
			ll fact = a1/(a+1);
			ll sg=0;
			forn(i,(ll)v.size()){
				bool bo=false;
				if(i==0) continue;
				if(ex>fact/2){
					v[i]+=sg+1;
					ex -= fact/2;
					bo=true;
				}
				else{
					v[i]+=sg;
				}
				sg*=2;
				if(bo) sg++;
				fact/=2;
			}
			cout << (ll)v.size() << " ";
			forn(i,(ll)v.size()) cout << v[i] << " ";
			cout << ln;
		}
		else{
			cout << -1 << ln;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    forn(i,t) solve();
    return 0;
}