#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
 
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

vector<int> l , r;
vector<pii> v;
int n , ans;

int lbs(int k){
	int lx = 0 , rx = n + 1;
	while(lx < rx - 1){
		int m = (rx + lx) / 2;
		if(l[m] > k){
			rx = m;
		} else {
			lx = m;
		}
	}
	return lx + 1;
}

int rbs(int k){
	int lx = 0 , rx = n + 1;
	while(lx < rx - 1){
		int m = (rx + lx) / 2;
		if(r[m] > k){
			rx = m;
		} else {
			lx = m;
		}
	}
	return lx;
}

void solve(){
	l.clear();
	r.clear();
	v.clear();
	cin>>n; ans = n - 1;
	for(int i = 0 ; i < n ; i++){
		int o , u;
		cin>>o>>u;
		l.push_back(o);
		r.push_back(u);
		v.push_back({o - 1 , u});
	}
	r.push_back(-1);
	l.push_back(1.5e9);
	sort(l.begin() , l.end());
	sort(r.begin() , r.end());
	for(int i = 0 ; i < n ; i++){
		int h = 0 , m;
		m = rbs(v[i].first);
		h += m;
		m = lbs(v[i].second);
		h += n - m;
		ans = min(h , ans);
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}