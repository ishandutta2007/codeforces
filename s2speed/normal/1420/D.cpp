#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 3e5 + 1 , md = 998244353;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return (x * x) % md;
	} else {
		return (((x * x) % md) * n) % md;
	}
}

ll fact[MAX_N];

void fact_build(){
	fact[0] = 1;
	for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
	}
}

ll chs(ll n, ll k){
    if(k > n) return 0;
    return (((fact[n] * tav(fact[k] , md - 2)) % md) * tav(fact[n - k] , md - 2)) % md;
}

vector< pair<ll , ll> > v;
vector<ll> l;

void solve(){
	ll n , k , ans = 0;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		ll o , u;
		cin>>o>>u;
		v.push_back( make_pair(u , o) );
		l.push_back(o);
	}
	sort(v.begin() , v.end());
	sort(l.begin() , l.end());
	ll x = 0;
	for(int i = 0 ; i < n ; i++){
		while(l[x] <= v[i].first && x < n){
			x++;
		}
		ans += chs(x - i - 1 , k - 1);
		ans %= md;
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fact_build();
	solve();
	return 0;
}