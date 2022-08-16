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
const int m=1e5+5;
int a[m],ans[m],mprev[m],used[m];

int f(int n,int l,int h){
	if(l==h) return l;
	ll c = (l+h+1)/2;
	if((c*(c+1))/2 <= n) return f(n,c,h);
	else return f(n,l,c-1);
}

int g(int v, int l, int h){
	if(l==h){
		return l;  
	}
	int c = (l+h)/2;
	if(ans[c]==0) return g(v,l,c);
	else if(ans[c]<v) return g(v,c+1,h);
	else return g(v,l,c);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int ml;
    cin >> t;
    while(t--){
    	int n,copy;
    	cin >> n;
    	copy=n;
    	int k = f(n,1,n);
    	// dbg(k);
    	forn(i,n){
    		cin >> a[i];
    		used[i+1]=0;
    	}
    	bool b=false;
    	int index=0;
    	vector<vector<int> > v;
    	vector<vector<int> > v1(n);
    	while(true){
    		forn(i,n) ans[i]=0,mprev[i+1]=0;
	    	forn(i,n){
	    		if(used[a[i]]) continue;
	    		if(ans[0]==0 || a[i]<ans[0]) {ans[0]=a[i];v1[0].pb(a[i]); continue;}
	    		int ko=g(a[i],0,n-1);
	    		// dbg(ko);dbg(a[i]);
	    		// if(ans[ko]>a[i] || ans[ko]==0){
	    			ans[ko]=a[i];v1[ko].pb(a[i]);
	    			mprev[a[i]]=ans[ko-1];
	    		// } 
	    	}
	    	rforn(i,n-1){
	    		if(ans[i]!=0) {ml=i+1; break;}
	    	}
	    	// cout << "ml" << "=" << ml << ln;
	    	if(ml<=k) break;
	    	int ind=ans[ml-1];
	    	v.pb(vector<int>());
	    	while(ind!=0){
	    		v[index].pb(ind);
	    		used[ind]=1;
	    		ind = mprev[ind];
	    	}
	    	index++;
	    	b=true;
	    	forn(i,n) if(!used[i+1]){b=false;break;}
	    	if(b) break;
	    	k--;
	    	forn(i,n) v1[i].clear();
    	}
    	int temp12=index-1;
    	int si=v.size();
    	if(!b) si+=ml;
    	cout << si<<ln;
    	if(!b){
    		forn(i,ml){
    			cout << v1[i].size() << " ";
    			forn(j,v1[i].size()) cout << v1[i][j] << " ";
    			cout << ln;
    		}
    	}
    	forn(i,v.size()){
    		cout << v[i].size() << " ";
    		rforn(j,v[i].size()-1) cout << v[i][j] << " ";
    		cout << ln;
    	}
    }
    return 0;
}