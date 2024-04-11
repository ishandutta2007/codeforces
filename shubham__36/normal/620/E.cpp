#include <bits/stdc++.h> 
#include <complex>
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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
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
#define INF LLONG_MAX
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
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

vv64 gr;
v64 rev,col,sz;
ll n1,cur;

class Recursive{
	ll n;
	v64 tr,lazy;

	public:

	Recursive(){
		n = n1;
		tr.assign(4*n,0);
		lazy.assign(4*n,0);
		forsn(i,1,n+1) {
			assign(1,rev[i]+1,rev[i]+1,1,n,1LL<<col[i]);
		}
	}

	void pushdown(ll node) {
		if(lazy[node]) {
			tr[node*2]=lazy[node];
			tr[node*2+1]=lazy[node];
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
			lazy[node]=0;
		}
	}
	void assign(ll node, ll l, ll r, ll ll1, ll rr, ll val) {
		if(l>rr||ll1>r)
			return;
		if(l<=ll1&&rr<=r) {
			tr[node]=val;
			lazy[node]=val;
			return;
		}
		pushdown(node);
		assign(2*node,l,r,ll1,(ll1+rr)/2,val);
		assign(2*node+1,l,r,1+(ll1+rr)/2,rr,val);
		tr[node]=tr[2*node]|tr[2*node+1];
	}
	ll query(ll node, ll l, ll r, ll ll1, ll rr) {
		if(l>rr||ll1>r)
			return 0;
		if(l<=ll1&&rr<=r)
			return tr[node];
		pushdown(node);
		return query(node*2,l,r,ll1,(ll1+rr)/2)|query(node*2+1,l,r,(ll1+rr)/2+1,rr);
	}
};

void dfs(ll v, ll p){
	rev[v]=cur;
	cur++;
	sz[v]=1;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p){
			dfs(gr[v][i],v);
			sz[v]+=sz[gr[v][i]];
		}
	}
}

void solve(){
	ll m;
	cin >> n1 >> m;
	gr.resize(n1+5);
	rev.resize(n1+5,0);
	col.resize(n1+5,0);
	sz.resize(n1+5,0);
	forn(i,n1){
		cin >> col[i+1];
	}
	forn(i,n1-1){
		ll a,b;
		cin >> a >> b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs(1,-1);
	Recursive st;
	forn(i,m){
		ll qt;
		cin >> qt;
		if(qt==1){
			ll v,c;
			cin >> v >> c;
			st.assign(1,rev[v]+1,rev[v]+sz[v],1,n1,((ll)1<<c));
		}
		else{
			ll v;
			cin >> v;
			cout << __builtin_popcountll(st.query(1,rev[v]+1,rev[v]+sz[v],1,n1)) << ln;
		}
	}
}


int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}