#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> v;
ll p[MAX_N];
set<ll> s;

void s_build(ll l , ll r){
	ll o = (v[l] + v[r - 1]) / 2 , m;
	vector<ll>::iterator it;
	it = upper_bound(v.begin() , v.end() , o);
	m = it - v.begin();
	if(m == r){
		return;
	}
	ll a , b;
	a = p[m - 1];
	if(l > 0){
		a -= p[l - 1];
	}
	b = p[r - 1] - p[m - 1];
	s.insert(a);
	s.insert(b);
	s_build(l , m);
	s_build(m , r);
	return;
}

void solve(){
	v.clear();
	s.clear();
	ll n , q;
	cin>>n>>q;
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		v.push_back(inp);
	}
	sort(v.begin() , v.end());
	p[0] = v[0];
	for(int i = 1 ; i < n ; i++){
		p[i] = p[i - 1] + v[i];
	}
	s.insert(p[n - 1]);
	s_build(0 , n);
	while(q--){
		ll x;
		cin>>x;
		if(s.count(x)){
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}