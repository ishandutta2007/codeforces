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
	ll n;
	cin >> n;
	map<ll,set<p64> > m;
	ll fact = 30;
	string arr[n];
	forn(i,n){
		string s;
		ll c = 0;
		cin >> s;
		char lv = 'a';
		forn(i,(ll)s.size()){
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
				c++;
				lv = s[i];
			}
		}
		arr[i]=s;
		m[c].insert(mp(lv-'a',i));
	}
	v64 a,b;
	p64 pr1=mp(-1,-1),pr2=mp(-1,-1);
	for(auto i : m){
		// cout << (ll)i.size() << ln;
		for(auto j : i.se){
			// cout << j.fi << " " << j.se << ln;
			if(pr1.fi == -1){
				pr1 = j;
			}
			else if(pr2.fi == -1 && pr1.fi == j.fi){
				b.pb(pr1.se);
				b.pb(j.se);
				pr1 = mp(-1,-1);
			}
			else if(pr2.fi==-1){
				pr2 = j;
			}
			else if(pr2.fi == j.fi){
				b.pb(pr2.se);
				b.pb(j.se);
				pr2 = mp(-1,-1);
			}
			else{
				a.pb(pr1.se);
				a.pb(pr2.se);
				pr1 = j;
				pr2 = mp(-1,-1);
			}
		}
		if(pr1.fi!=-1 && pr2.fi!=-1){
			a.pb(pr1.se);
			a.pb(pr2.se);
		}
		pr1 = mp(-1,-1);
		pr2 = mp(-1,-1);
		// cout << i.fi << ln;
		// forn(j,(ll)a.size()) cout << a[j] << " ";
		// cout << ln;
		// forn(j,(ll)b.size()) cout << b[j] << " ";
		// cout << ln;
	}
	ll sz = min((ll)b.size()/2,((ll)b.size()+(ll)a.size())/4);
	cout << sz << ln;
	ll in1=0;
	forn(i,sz){
		if(in1<(ll)a.size()){
			cout << arr[a[in1]] << " " << arr[b[in1]] << ln;
			in1++;
			cout << arr[a[in1]] << " " << arr[b[in1]] << ln;
			in1++;
		}
		else{
			cout << arr[b[in1]] << " " << arr[b[in1+2]] << ln;
			in1++;
			cout << arr[b[in1]] << " " << arr[b[in1+2]] << ln;
			in1+=3;
		}
	}
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