#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5 + 1;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll gh(ll a , ll b){
	ll o = a - b;
	if(o < 0){
		o -= 2 * o;
	}
	return o;
}

ll dp[MAX_N] , a[MAX_N] , b[MAX_N] , t[MAX_N];

void solve(){
	ll r , n , x = 0 , m = -1e18, ans = 0;
	cin>>r>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>t[i]>>a[i]>>b[i];
	}
	t[0] = 0; a[0] = 1; b[0] = 1; dp[0] = 0;
	for(int i = 1 ; i <= n ; i++){
		while(t[x] <= t[i] - r * 2){
			m = max(dp[x] , m);
			x++;
		}
		dp[i] = m + 1;
		for(int j = x ; j < i ; j++){
			if(gh(a[j] , a[i]) + gh(b[j] , b[i]) <= gh(t[j] , t[i])){
				dp[i] = max(dp[i] , dp[j] + 1);
			}
		}
	}
	for(int i = 0 ; i <= n ; i++){
		ans = max(dp[i] , ans);
	}
	cout<<ans<<"\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}