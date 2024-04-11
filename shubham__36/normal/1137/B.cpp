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
#define INF LLONG_MAX/2

// ll sz(string s){
// 	return (ll)s.size();
// }

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    ll o=0,z=0;
    forn(i,(ll)s.size()){
    	if(s[i]=='1') o++;
    	else z++;
    }
    ll in=-1;
    forn(i,(ll)t.size()){
    	if(i==0) continue;
    	if(t[i]==t[in+1]) in++;
    	else{
    		if(t[i]==t[0]) in=0;
    		else in = -1;
    	}
    }
    // cout << in << ln;
    forn(i,in+1){
    	if(t[i]=='0' && z>0) {s[i]='0'; z--;}
    	else if(t[i]=='1' && o>0) {s[i]='1'; o--;}
    	else {
    		forsn(j,i,(ll)s.size()){
    			if(z>0){
    				s[j]='0';
    				z--;
    			}
    			else{
    				s[j]='1';
    				o--;
    			}
    		}
    		cout << s << ln;
    		return 0;
    	}
    }
    forn(i,(ll)s.size()-in-1){
    	if(t[in+1+(i%((ll)t.size()-in-1))]=='0' && z>0){
    		s[in+1+i]='0';
    		z--;
    	}
    	else if(t[in+1+(i%((ll)t.size()-in-1))]=='1' && o>0){
    		s[in+1+i]='1';
    		o--;
    	}
    	else{
    		forsn(j,i,(ll)s.size()-in-1){
    			if(z>0){
    				s[j+in+1]='0';
    				z--;
    			}
    			else{
    				s[j+in+1]='1';
    				o--;
    			}
    		}
    		cout << s << ln;
    		return 0;
    	}
    }
    cout << s << ln;
    return 0;
}