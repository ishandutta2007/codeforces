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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int in1=0,in2=s.size()-1;
    ll ans=0;
    bool bo1=false,bo2=false;
    bool b1=false,b2=false;
    while(true){
    	if(!b1 && s[in1]=='['){
    		b1=true;
    	}
    	else if(b1 && s[in1]==':'){
    		b2=true;
    	}
    	else{
    		ans++;
    	}
    	in1++;
    	if((b1 && b2) || in1>=s.size()) break;
    }
    while(true){
    	if(!bo1 && s[in2]==']'){
    		bo1=true;
    	}
    	else if(bo1 && s[in2]==':'){
    		bo2=true;
    	}
    	else{
    		ans++;
    	}
    	in2--;
    	if((bo1 && bo2) || in2<0) break;
    }
    // cout << in1 << " " << in2 << ln;
    if(!b1 || !b2 || !bo1 || !bo2 || in2-in1<-1){
    	cout << -1;
    }
    else{
	    	while(in2-in1!=-1){
		    	if(s[in1]!='|'){
		    		ans++;
		    	}
		    	in1++;
	    }
	    cout << (ll)s.size()-ans;
    }
    return 0;
}