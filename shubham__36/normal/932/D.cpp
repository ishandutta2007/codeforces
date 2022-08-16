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

const ll sz = 400005;
// vv64 gr(sz);
const ll logsz = 25;
vv64 pr(sz,v64(logsz,-1));
v64 val(sz,0);
v64 absval(sz,0);

void solve(){
	ll q;
	cin >> q;
	ll last = 0;
	ll in=2;
	forn(i,q){
		ll p,q,r;
		cin >> p >> q >> r;
		ll a = last^q;
		ll b = last^r;
		if(p==1){
			ll t1 = -1;
			ll cur = a;
			while(cur>0){
				forn(i,logsz){
						if(pr[cur][i]!=-1){
							if(absval[pr[cur][i]]>=b){
								if(i!=0){
									cur = pr[cur][i-1];
									break;
								}
								else{
									if(absval[cur]>=b) t1 = cur;
									else t1 = pr[cur][i];
									cur = 0;
									break;
								}
							}
						}
						else{
							if(i!=0){
								cur = pr[cur][i-1];
								break;
							}
							else{
								if(absval[cur]>=b) t1 = cur;
								cur = 0;
								break;
							}
						}
					}
			}
			forn(i,logsz){
				if(i==0) pr[in][i]=t1;
				else if(pr[in][i-1]!=-1) pr[in][i]=pr[pr[in][i-1]][i-1];
			}
			val[in]=val[t1]+b;
			absval[in]=b;
			in++;
		}
		else{
			if(b<absval[a]){
				cout << 0 << ln;
				last = 0;
			}
			else{
				ll ans = 0;
				ll cur = a;
				while(cur>0){
					forn(i,logsz){
						if(pr[cur][i]!=-1){
							if(val[a]-val[pr[cur][i]]>b){
								if(i!=0){
									ans+=(1<<(i-1));
									cur = pr[cur][i-1];
									break;
								}
								else{
									if(val[a]-val[cur]+absval[cur]<=b) ans++;
									cur = 0;
									break;
								}
							}
						}
						else{
							if(i!=0){
								ans+=(1<<(i-1));
								cur = pr[cur][i-1];
								break;
							}
							else{
								if(val[a]-val[cur]+absval[cur]<=b) ans++;
								cur = 0;
								break;
							}
						}
					}
				}
				cout << ans << ln;
				last = ans;
			}
			
		}
		// cout << val[in-1] << ln;
		// forn(i,logsz) cout << pr[in-1][i] << " ";
		// cout << ln;
		// forn(i,in) cout << val[i] << " " << absval[i] << "      ";
		// cout << ln;
	}
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