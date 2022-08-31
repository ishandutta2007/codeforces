#include <bits/stdc++.h>
#include <iomanip>
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
typedef unordered_map<int,int> m32;
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 1e9 + 7;
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
v64 v1,v2;
v64 f,g;

// ll s1(ll v, ll l, ll h){
// 	if(l==h) return h;
// 	ll mid = (l+h+1)/2;
// 	if(v1[mid]<=v) return s1(v,mid,h);
// 	else return s1(v,l,mid-1);
// }

// ll s2(ll v, ll l, ll h){
// 	if(l==h) return h;
// 	ll mid = (l+h+1)/2;
// 	if(v2[mid]<=v) return s2(v,mid,h);
// 	else return s2(v,l,mid-1);
// }

// ll f(ll v){
// 	return s1(v,0,(ll)v1.size());
// }

// ll g(ll v){
// 	return s2(v,0,(ll)v2.size());
// }

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin >> n >> q;
    ll s[q],e[q];
    ll a[n];
    forn(i,n) a[i]=0;
    forn(i,q) {
    	cin >> s[i] >> e[i];
    	forsn(j,s[i]-1,e[i]){
    		a[j]++;
    	}
    }
    ll ans = 0;
    v1.pb(0);
    v2.pb(0);
    forn(i,n){
    	if(a[i]!=0) ans++;
    	if(a[i]==1) v1.pb(i+1);
    	else if(a[i]==2) v2.pb(i+1);
    }
    ll in1=0,in2=0;
    f.pb(0),g.pb(0);
    forn(i,n){
    	if(in1+1<(ll)v1.size() && v1[in1+1]<=i+1){
    		in1++;
    	}
    	if(in2+1<(ll)v2.size() && v2[in2+1]<=i+1){
    		in2++;
    	}
    	f.pb(in1);
    	g.pb(in2);
    }
    // cout << ans << ln;
    ll fans=0;
    forn(i,q-1){
    	forsn(j,i+1,q){
    		ll s1=s[i],s2=s[j],e1=e[i],e2=e[j];
    		if(e1>e2){
    			swap(e1,e2);
    			swap(s1,s2);
    		}
    		if(e1 < s2){
    			ll temp = f[e1]+f[e2]-f[s1]-f[s2];
    			if(a[s1-1]==1) temp++;
    			if(a[s2-1]==1) temp++;
    			fans = max(fans,ans-temp);
    		}
    		else{
    			ll temp = 0;
    			if(s1<=s2-1){
    				temp += f[s2-1]-f[s1];
    				if(a[s1-1]==1) temp++;
    			}
    			else if(s1-1>=s2){
    				temp += f[s1-1]-f[s2];
    				if(a[s2-1]==1) temp++;
    			}
    			if(e2>=e1+1){
    				temp += f[e2]-f[e1+1];
    				if(a[e1]==1) temp++;
    			}
    			ll t = max(s1,s2);
    			temp+=g[e1]-g[t];
    			if(a[t-1]==2) temp++; 
    			fans = max(fans,ans-temp);
    		}
    	}
    }
    cout << fans << ln;
    return 0;
}