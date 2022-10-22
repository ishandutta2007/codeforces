#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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

const ll MAX_N = 262144;

ll a[20] , b[20][20] , dp[MAX_N][20];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , m , k , mn , ans = 0;
	cin>>n>>m>>k; mn = tav(2 , n);
	for(int i = 0 ; i < mn ; i++){
		for(int j = 0 ; j < n ; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		for(int j = 0 ; j < n ; j++){
			b[i][j] = 0;
		}
	}
	for(int i = 0 ; i < k ; i++){
		ll x , y , c;
		cin>>x>>y>>c; x--; y--;
		b[x][y] = c;
	}
	for(int i = 0 ; i < mn ; i++){
		ll q = 1;
		for(int j = 0 ; j < n ; j++){
			ll p = q & i;
			if(p == q){
				v.push_back(j);
			}
			q *= 2;
		}
		ll vs = v.size();
		for(int e = 0 ; e < vs ; e++){
			int j = v[e];
			dp[i][j] = a[j];
			ll o = 1 << j , y = i ^ o;
			for(int r = 0 ; r < vs ; r++){
				int q = v[r];
				if(q == j){
					continue;
				}
				dp[i][j] = max(dp[i][j] , dp[y][q] + a[j] + b[q][j]);
			}
			if(vs == m){
				ans = max(ans , dp[i][j]);
			}
		}
		v.clear();
	}
	cout<<ans<<"\n";
	return 0;
}