#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll md = 1e9 + 7 , MAX_N = 2e5 + 20 , mn = 2020;
 
ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x % md;
	} else {
		return x * x % md * n % md;
	}
}
 
ll fact[MAX_N] , fact_md[MAX_N];
 
void fact_build(){
	fact[0] = 1;
    fact_md[0] = 1;
	for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
        fact_md[i] = tav(fact[i] , md - 2);
    }
}
 
ll chs(ll n, ll k){
    if(k > n) return 0;
    return (((fact[n] * fact_md[k]) % md) * fact_md[n - k]) % md;
}
 
vector< pair<ll , ll> > v;
ll dp[mn];
 
int main(){
    fact_build();
    int h , w , n;
    cin>>h>>w>>n;
    for(int i = 0 ; i < n ; i++){
        int r , c;
        cin>>r>>c; r--; c--;
        v.push_back( {r , c} );
    }
    v.push_back( {h - 1 , w - 1} );
    sort(v.begin() , v.end());
    for(int i = 0 ; i <= n ; i++){
        pair<ll , ll> p = v[i];
        dp[i] = chs(p.first + p.second , p.first);
        for(int j = 0 ; j < i ; j++){
            if(v[j].second <= v[i].second){
                pair<ll , ll> q = v[j];
                ll z = dp[j];
                z *= chs(p.first - q.first + p.second - q.second , p.first - q.first);
                z %= md;
                dp[i] -= z - md;
                dp[i] %= md;
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}