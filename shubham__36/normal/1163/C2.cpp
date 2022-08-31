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

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll x[n],y[n];
    ll offset = 1e9;
    map<ll, ll> pr[n];
    ll sh[n][n];
    forn(i,n) forn(j,n) sh[i][j]=-1;
    forn(i,n) cin >> x[i] >> y[i];
    multiset<p64> fin;
    forn(i,n){
    	set<p64> s;
    	forsn(j,i+1,n){
    		if(sh[i][j]==-1){
    			ll g = __gcd(abs(x[j]-x[i]),abs(y[j]-y[i]));
    			p64 t;
    			if(x[j]-x[i]>0 || (x[j]-x[i]==0 && y[j]-y[i]>=0)) t = mp((x[j]-x[i])/g,(y[j]-y[i])/g);
    			else t = mp((x[i]-x[j])/g,(y[i]-y[j])/g);
    			if(s.find(t)==s.end()){
    				s.insert(t);
    				pr[i][t.fi*offset+t.se]=j;
    			}
    			else{
    				ll index = pr[i][t.fi*offset+t.se];
    				sh[index][j]=t.fi*offset+t.se;
    				forsn(k,index+1,n){
    					if(sh[index][k]==t.fi*offset+t.se){
    						if(k<j) sh[k][j]=t.fi*offset+t.se;
    						else sh[j][k]=t.fi*offset+t.se;
    					}
    				}
    			}
    		}
    	}
    	for(auto it:s){
    		fin.insert(it);
    	}
    	// cout << (ll)fin.size() << ln;
    }
    ll now = fin.size();
    // cout << now << ln;
    ll ans = (now*(now-1))/2;
    p64 prev = mp(-1,-1);
    ll count = 1;
    for(auto it:fin){
    	// cout << it.fi << " " << it.se << "     ";
    	if(it == prev){
    		count++;
    	}
    	else{
    		prev = it;
    		if(count > 1){
    			ans -= ((count-1)*count)/2;
    			// cout << count << ln;
    		}
    		count = 1;
    	}
    }
    if(count > 1){
    			ans -= ((count-1)*count)/2;
    			// cout << count << ln;
    		}
    // cout << ln;
    cout << ans << ln;
    return 0;
}