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
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
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
m64 umap;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    ll a[n],b[n];
    forn(i,n) {cin >> a[i]; b[i]=a[i];}
    sort(b,b+n);
    ll ans=0;
    forn(i,m*k){
    	if(umap.find(b[n-1-i])==umap.end()) umap[b[n-1-i]]=0;
    	umap[b[n-1-i]]++;
    	ans += b[n-1-i];
    }
    cout << ans << ln;
    ll rem=m;
    forn(i,n){
    	if(k==1) break;
    	if(umap.find(a[i])==umap.end() || umap[a[i]]==0){
    		continue;
    	}
    	rem--;
    	umap[a[i]]--;
    	if(rem==0){
    		cout << i+1 << " ";
    		rem=m;
    		k--;
    	}
    }
    cout << ln;
    return 0;
}