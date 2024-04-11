#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <fstream>
 
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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
    if(b >= (MOD-1)) b %= (MOD-1);
    if(b==0) return 1;
    ll t1 = mpow(a,b/2);
    t1 *= t1;
    t1 %= MOD;
    if(b%2) t1 *= a;
    t1 %= MOD;
    return t1;
}
 
ll mpow(ll a, ll b, ll p){
    if(b==0) return 1;
    ll t1 = mpow(a,b/2,p);
    t1 *= t1;
    t1 %= p;
    if(b%2) t1 *= a;
    t1 %= p;
    return t1;
}
 
ll modinverse(ll a, ll m){
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}
 
ll range(ll l, ll r){
    return l + rand()%(r-l+1);
}

ll cur = 2;
ll n,m,k;
vv64 gr,rgr;
v64 vis;
bool bo = 0;

p64 dfs(ll v, ll val){
	vis[v]=val;
	p64 ret = mp(1,0);
	forn(i,sz(gr[v])){
		if(!vis[gr[v][i]]){
			p64 temp = dfs(gr[v][i],val);
			ret.fi += temp.fi;
			ret.se += temp.se;
		}
		else if(vis[gr[v][i]]!=val){
			bo=1;
		}
	}
	forn(i,sz(rgr[v])){
		if(!vis[rgr[v][i]]){
			p64 temp = dfs(rgr[v][i],val^1);
			ret.fi += temp.se;
			ret.se += temp.fi;
		}
		else if(vis[rgr[v][i]]==val){
			bo=1;
		}
	}
	return ret;
}

void solve(){

    int n,m;
    cin>>n>>m;
    vv64 arr(n+1);
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            int temp;
            cin>>temp;
            arr[j].push_back(temp);
        }
    }
    ll ans=1e9;
    v64 vec;
    for (int i=0; i<n-1; i++)
    {
        vp64 temp;
        for (int j=0; j<m; j++)
        {
            temp.push_back(p64(arr[n-1][j]-arr[i][j],j));
        }
        sort(temp.begin(),temp.end());
        int count=m;
        int sum=0;
        for (int j=0; j<m; j++)
        {
            sum+=temp[j].first;
            if (sum<=0)
            {
                count--;   
            }
            else
            {
                if (count<ans)
                {
                    ans=count;
                    vec.clear();
                    for (int k=j; k<m; k++)
                        vec.push_back(temp[k].second);
                }

            }
        }
        if (sum<=0)
        {
            ans=0;
            vec.clear();
        }
    }
    cout<<ans<<endl;
    for (int i=0; i<vec.size(); i++)
        cout<<vec[i]+1<<" ";
    

}
 
int main()
{
    fast_cin();
    ll t=1;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}