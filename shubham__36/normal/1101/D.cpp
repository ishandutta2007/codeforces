#include <bits/stdc++.h>
#include <set>
#include <queue>
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
typedef unordered_map<ll,set<ll> > m34234;
typedef unordered_map<int,v32 > m648;
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
    ll n;
    cin >> n;
    int ans=0;
    int va[n];
    vector<m648 > v(n);
    vector<set<int> > voe(n);
    bool bo12=false;
    forn(i,n){
    	cin >> va[i];
    	if(va[i]!=1) bo12=true;
    }
    forn(i,n-1){
    	int a,b;
    	cin >> a >> b;
    	a--,b--;
    	int t = __gcd(va[a],va[b]);
    	int in=2;
    	while(t!=1 && in*in<=t){
    		if(t%in == 0){
    			v[in-1][a].pb(b);
    			v[in-1][b].pb(a);
    			voe[in-1].insert(a);
    			voe[in-1].insert(b);
    			while(t%in == 0){
    				t/=in;
    			}
    		}
    		in++;
    	}
    	if(t!=1){
    		v[t-1][a].pb(b);
    		v[t-1][b].pb(a);
    		voe[t-1].insert(a);
    		voe[t-1].insert(b);
    	}
    }
    forn(i,n){
    	if(voe[i].size()){
    		unordered_map<int,int> umap;
    		for(auto a : voe[i]){
    		  //  cout << a << ln;
    			if(umap.find(a)==umap.end()){
    				queue<int> q; 
    				q.push(a); 
    				umap[a] = 1;
    				int f;
    				while (!q.empty()) { 
				        f = q.front(); 
				        q.pop();  
				        for (auto ik = v[i][f].begin(); ik != v[i][f].end(); ik++) { 
				            if (umap.find(*ik)==umap.end()) { 
				                q.push(*ik); 
				                umap[*ik] = 1; 
				            } 
				        } 
				    }  
    				queue<p32> q1; 
    				// cout << f << ln;
    				q1.push(mp(f,1)); 
    				umap[f] = 0;
    				int temp;
    				while (!q1.empty()) { 
				        f = q1.front().fi;
				        temp= q1.front().se;
				        // cout << temp << ln;
				        q1.pop();  
				        for (auto ik = v[i][f].begin(); ik != v[i][f].end(); ik++) { 
				            if (umap[*ik]==1) { 
				                q1.push(mp(*ik,temp+1)); 
				                umap[*ik] = 0; 
				            } 
				        } 
				    }
				    ans=max(ans,temp); 
				    q={};
				    q1={};
    			}
    		}
    		umap.clear();
    	}
    }
    if(!ans && bo12) ans++;
    cout << ans;
    return 0;
}