#include <bits/stdc++.h>
#include <set>
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
string s,p;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
	cin >> n >> k;
	cin >> s >> p;
	ll carry;
	ll t=-1;
	forn(i,n){
		if(s[i]!=p[i]){
			t=i;
			break;
		}
	}
	if(t==-1){
		cout << n << ln;
		return 0;
	}
	t = n - t;
	if(t<30){
		ll a=0,b=0;
		for(ll i=n-t;i<n;i++){
			a += (s[i]-'a')*pow(2,n-1-i);
			b += (p[i]-'a')*pow(2,n-1-i);
		}
		k = min(k,b-a+1);
	}
	ll prev=0,count=1;
	ll ans = 0;
	ll temp;
	// cout << ans << ln;
	forn(i,n){
		if(prev == 0 && s[i]==p[i]){
			ans++;
		}
		if(prev == 0 && s[i]!=p[i]) {
			temp = 2*count;
			ans+=min((ll)k,temp);
			if(count<=k) count=temp;
			prev=1;
		}
		else if(prev != 0){
			temp = 2*count;
			if(s[i]=='b') temp--;
			if(p[i]=='a') temp--;
			ans+=min((ll)k,temp);
			if(count<=k) count=temp;
		}
	}
	cout << ans;
}