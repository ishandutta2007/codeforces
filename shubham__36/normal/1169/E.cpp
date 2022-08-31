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
ll MOD = 1000000007;
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

void solve(){
    ll n,q;
    cin >> n >> q;
    ll a[n];
    forn(i,n){
    	cin >> a[i];
    }
    ll pr[n][20];
    forn(i,n){
    	forn(j,20){
    		pr[i][j]=-1;
    	}
    }
    ll tmp[20];
    forn(i,20) tmp[i]=-1;
    forn(i,n){
    	forn(j,20){
    		if(a[i]&(1<<j)){
    			ll temp=tmp[j];
    			tmp[j]=i;
    			if(temp!=-1){
    				pr[i][j]=temp;
    				forn(k,20){
    					pr[i][k]=max(pr[i][k],pr[temp][k]);
    				}
    			}
    		}
    	}
    }
    // forn(i,n){
    // 	forn(j,20){
    // 		cout << pr[i][j] << " ";
    // 	}
    // 	cout << ln;
    // }
    forn(i,q){
    	ll x,y;
    	cin >> x >> y;
    	x--,y--;
    	bool bo=false;
    	forn(j,20){
    		if(a[x]&(1<<j)){
    			if(pr[y][j]>=x) bo=true;
    		}
    	}
    	if(bo) cout << "Shi" << ln;
    	else cout << "Fou" << ln;
    }
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}