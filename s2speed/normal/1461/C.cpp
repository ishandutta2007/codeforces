#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef double db;
 
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

ll a[MAX_N];

void solve(){
	ll n , x = -1 , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		if(a[i] != i){
			x = i;
			break;
		}
	}
	if(x == -1){
		ll t1;
		db t2;
		for(int i = 0 ; i < m ; i++){
			cin>>t1>>t2;
		}
		printf("1\n");
		return;
	}
	ll o;
	db p , ans = 1;
	for(int i = 0 ; i < m ; i++){
		cin>>o>>p;
		if(o <= x){
			continue;
		}
		p = 1 - p;
		ans *= p;
	}
	ans = 1 - ans;
	printf("%.10lf\n" , ans);
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