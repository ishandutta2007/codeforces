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
	ll a[6];
	a[0]=4,a[1]=8,a[2]=15,a[3]=16,a[4]=23,a[5]=42;
	ll res[4];
	forn(i,4){
		cout << "? 1 " << i+2 << endl;
		cin >> res[i];
	}
	ll ans[6];
	forn(i,6){
		forsn(j,i+1,6){
			if(a[i]*a[j]==res[0]){
				ans[0]=a[i],ans[1]=a[j];
			}
		}
	}
	forn(i,3){
		ans[i+2]=res[i+1]/ans[0];
		bool bo = false;
		forn(j,6) if(a[j]==ans[i+2]) bo=true;
		if(!bo || res[i+1]%ans[0]!=0 || ans[i+2]==ans[0] || ans[i+2]==ans[1]){
			swap(ans[0],ans[1]);
		}
		ans[i+2]=res[i+1]/ans[0];
	}
	ans[5]=0;
	forn(i,6) ans[5]+=a[i];
	forn(i,5) ans[5]-=ans[i];
	cout << "! " ;
	forn(i,6) cout << ans[i] << " ";
	cout << endl;
}


int main()
{
	// ios_base::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
    ll t=1;
    forn(i,t) solve();
    return 0;
}