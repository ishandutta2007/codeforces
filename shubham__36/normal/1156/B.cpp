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
ll NUM = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

ll mmod(ll v,ll mod){
	ll temp = v/mod;
	return v-(temp*mod);
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    forn(i,t){
    	string s;
    	cin >> s;
    	vector<char> vf;
    	vector<char> vr;
    	ll c[26];
    	forn(j,26) c[j]=0;
    	forn(j,(ll)s.size()){
    		c[s[j]-'a']++;
    	}
    	forn(j,26){
    		if(c[j]!=0){
    			forn(k,c[j]) vf.pb('a'+j);
    			ll p = 0;
    			forsn(k,j+2,26){
    				if(c[k]!=0){
    					forn(p1,c[k]){
    						if(p==0) vf.pb('a'+k);
    						else vr.pb('a'+k);
    					}
    					p=1-p;
    				}
    			}
    			if(j<25 && c[j+1]!=0 && (ll)vr.size()==0 && abs(vf[(ll)vf.size()-1]-('a'+j+1))==1){
    				cout << "No answer" << ln;
    				break;
    			}
    			else if(j<25 && c[j+1]!=0 && (ll)vr.size()==0){
    				forn(p1,c[j+1]){
    					vf.pb('a'+j+1);
    				}
    			}
    			else if(j<25){
    				forn(p1,c[j+1]){
    					vr.pb('a'+j+1);
    				}
    			}
    			if((ll)vr.size()>0)
    				rforn(yyu,(ll)vr.size()-1){
    					cout << vr[yyu];
    				}
    				forn(yyu,(ll)vf.size()){
    					cout << vf[yyu];
    				}
    				cout << ln;
    			break;
    		}
    	}
    }
    return 0;
}