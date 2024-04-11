#include <bits/stdc++.h>
#include <queue>
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
typedef pair < ll, pair < ll, ll > > myp;
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

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll ans = mpow(a,b/2);
	ans *= ans;
	ans%=MOD;
	if(b%2==1) ans *= a;
	ans %=MOD;
	return ans;
}

ll fact(ll n){
	ll ans=1;
	forn(i,n-1){
		ans*=(i+2);
    	ans%=MOD;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    // cout << MOD << ln;
    // cout << mpow(2,MOD-2) << ln;
    cin >> s;
    ll a[52];
    forn(i,52) a[i]=0;
    forn(i,s.size()){
    	if(s[i]-'a'>=0 && s[i]-'a'<=25) a[s[i]-'a']++;
    	else a[26+s[i]-'A']++;
    }
    ll n=(ll)s.size();
    ll pt=1;
    pt=fact(n/2);
    pt*=pt;
    pt%=MOD;
    // cout << pt << ln;
    forn(i,52) {
    	pt*=mpow(fact(a[i]),MOD-2);
    	// cout << fact(a[i]) << mpow(fact(a[i]),MOD-1) << ln;
    	pt%=MOD;
    }
    // cout << pt << ln;
    ll dp[n/2+1][52];
    forn(i,n/2+1){
    	if(i==0 || i==a[0]) dp[i][0]=1;
    	else dp[i][0]=0;
    }
    forn(i,n/2+1){
    	forn(j,52){
    		if(j==0) continue;
    		dp[i][j]=dp[i][j-1];
    		if(a[j]>0 && i-a[j]>=0) dp[i][j]+=dp[i-a[j]][j-1];
    		dp[i][j]%=MOD;
    	}
    }
    // cout << dp[n/2][51] << " 1 " << ln;
    ll ans[52][52];
    ll d[n/2];
    forn(i,52){
    	forsn(j,i+1,52){
    		forn(v,n/2+1){
    			d[v]=dp[v][51];
    		}
    		forn(v,n/2+1){
    			if(v-a[j]>=0) {d[v]-=d[v-a[j]]; d[v]+=MOD; d[v]%=MOD;}
    		}
    		forn(v,n/2+1){
    			if(v-a[i]>=0) {d[v]-=d[v-a[i]]; d[v]+=MOD; d[v]%=MOD;}
    		}
    		ans[i][j]=d[n/2];
    	}
    }
    ll q;
    cin >> q;
    ll temp1,temp2;
    forn(i,q){
    	cin >> temp1 >> temp2;
    	if(s[temp1-1]==s[temp2-1]){
    		ll fv = pt*dp[n/2][51];
    		fv %= MOD;
    		cout << fv << ln;
    	}
    	else{
    		ll i1,i2;
    		if(s[temp1-1]-'a'>=0 && s[temp1-1]-'a'<=25) i1 = s[temp1-1]-'a';
    		else i1 = s[temp1-1]-'A'+26;
    		if(s[temp2-1]-'a'>=0 && s[temp2-1]-'a'<=25) i2 = s[temp2-1]-'a';
    		else i2 = s[temp2-1]-'A'+26;
    		if(i1>i2) swap(i1,i2);
    		ll fv = 2*pt*ans[i1][i2];
    		fv %= MOD;
    		cout << fv << ln;
    	}
    }
    return 0;
}