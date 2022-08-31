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
typedef vector<vector<p64> > vvp64;
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
#define INF LLONG_MAX/2e5

ll n;
v64 p,leaf;
vv64 gr;
map <p64,ll> m;
ll ro;
vv64 ans;

void sub(ll par, ll ch, ll val){
	if(ch==par) return;
	ll jp = p[ch];
	m[mp(ch,jp)]-=val;
	m[mp(jp,ch)]-=val;
	sub(par,jp,val);
}

void pdfs(ll v, ll pa){
	p[v]=pa;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=pa){
			pdfs(gr[v][i],v);
			leaf[v] = leaf[gr[v][i]];
		}
	}
	if(!leaf[v]) leaf[v]=v;
}

void dfs(ll v, ll p){
	// cout << v << ln;
	v64 vec;
	forn(i,(ll)gr[v].size()){
		if(gr[v][i]!=p){
			vec.pb(gr[v][i]);
		}
	}
	forn(i,(ll)vec.size()-2){
		ll val = m[mp(v,vec[i])];
		if(val!=0){
			v64 temp(3);
			temp[0]=leaf[vec[i]];
			temp[1]=leaf[vec[(ll)vec.size()-1]];
			temp[2]=val;
			ans.pb(temp);
			// cout << leaf[vec[i]] << " " << leaf[vec[(ll)vec.size()-1]] << " " << val << ln;
			sub(v,leaf[vec[i]],val);
			sub(v,leaf[vec[(ll)vec.size()-1]],val);
		}
	}
	if((ll)vec.size()==1){
		ll val = m[mp(v,vec[0])];
		if(val){
			v64 temp(3);
			temp[0]=ro;
			temp[1]=leaf[vec[0]];
			temp[2]=val;
			ans.pb(temp);
			// cout << ro << " " << leaf[vec[0]] << " " << val << ln;
			sub(ro,leaf[vec[0]],val);
		}
	}
	else if((ll)vec.size()){
		ll a1 = vec[(ll)vec.size()-2];
		ll a2 = vec[(ll)vec.size()-1];
		ll val1 = m[mp(v,a1)];
		ll val2 = m[mp(v,a2)];
		ll fv1 = (val1+val2)/2;
		ll fv2 = (val1-val2)/2;
		if(fv1!=0) {
			v64 temp(3);
			temp[0]=leaf[a1];
			temp[1]=leaf[a2];
			temp[2]=fv1;
			ans.pb(temp);
			// cout << leaf[a1] << " " << leaf[a2] << " " << fv1;
			sub(v,leaf[a1],fv1);
			sub(v,leaf[a2],fv1);
		}
		if(fv2){
			v64 temp(3);
			temp[0]=leaf[a1];
			temp[1]=ro;
			temp[2]=fv2;
			ans.pb(temp);
			temp[0]=leaf[a2];
			temp[1]=ro;
			temp[2]=-fv2;
			ans.pb(temp);
			// cout << ro << " " << leaf[a1] << " " << fv2 << ln;
			// cout << ro << " " << leaf[a2] << " " << -fv2 << ln;
			sub(ro,leaf[a1],fv2);
			sub(ro,leaf[a2],-fv2);
		}
	}
	forn(i,(ll)vec.size()){
		dfs(vec[i],v);
	}
}

void solve(ll index){
	cin >> n;
	p.resize(n+1,0);
	leaf.resize(n+1,0);
	gr.resize(n+1);
	forn(i,n-1){
		ll t1,t2,v;
		cin >> t1 >> t2 >> v;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
		m[mp(t1,t2)]=v;
		m[mp(t2,t1)]=v;
	}
	ro = -1;
	forn(i,n+1){
		if((ll)gr[i].size()==1) ro = i; 
		if((ll)gr[i].size()==2){
			if(m[mp(i,gr[i][0])] != m[mp(i,gr[i][1])]){
				cout << "NO" << ln;
				return;
			}
		}
	}
	pdfs(ro,-1);
	dfs(ro,-1);
	// forn(i,n+1){
	// 	forn(j,(ll)gr[i].size()){
	// 		cout << i << " " << gr[i][j] << " " << m[mp(i,gr[i][j])] << ln;
	// 			// cout << "NO" << ln;
	// 			// return;
	// 		// }
	// 	}
	// }
	forn(i,n+1){
		forn(j,(ll)gr[i].size()){
			if(m[mp(i,gr[i][j])]!=0){
				cout << "NO" << ln;
				return;
			}
		}
	}
	cout << "YES" << ln;
	cout << (ll)ans.size() << ln;
	forn(i,(ll)ans.size()){
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << ln;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve(i+1);
    return 0;
}