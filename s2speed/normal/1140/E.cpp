#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 20 , md = 998244353;

ll dp[MAX_N][2] , f[2 * MAX_N] , g[2 * MAX_N] , a[MAX_N] , b[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0){
			cin>>a[i / 2];
		} else {
			cin>>b[i / 2];
		}
	}
	for(int i = n ; i < MAX_N ; i++){
		a[i] = 0;
		b[i] = 0;
	}
	f[0] = 1; f[1] = k - 2;
	g[0] = 0; g[1] = k - 1;
	for(int i = 2 ; i < n ; i++){
		ll o = f[i - 2] , h = g[i - 2] , q = f[i - 2];
		o *= (k - 2);
		o %= md;
		o *= (k - 2);
		o %= md;
		h *= (k - 2);
		h %= md;
		q *= (k - 1);
		q %= md;
		f[i] = o + h + q;
		f[i] %= md;
		o = f[i - 2];
		o *= (k - 1);
		o %= md;
		o *= (k - 2);
		o %= md;
		h = g[i - 2];
		h *= (k - 1);
		h %= md;
		g[i] = h + o;
		g[i] %= md;
	}
	ll x = -1;
	if(a[0] == -1){
		dp[0][0] = k - 1;
		if(a[1] <= 0){
			dp[0][0]++;
		}
	} else {
		dp[0][0] = 1;
		x = 0;
	}
	for(int i = 1 ; i < (n + 1) / 2 ; i++){
		if(a[i] >= 1){
			x = i;
			dp[i][0] = dp[i - 1][0];
			if(a[i] == a[i - 1]){
				cout<<"0\n";
				return 0;
			}
		} else {
			ll z = k - 2;
			if(a[i + 1] <= 0 || a[i + 1] == a[i - 1]){
				z++;
			}
			dp[i][0] = dp[i - 1][0];
			dp[i][0] *= z;
			dp[i][0] %= md;
			if(a[i - 1] != -1){
				continue;
			}
			if(z == k - 2){
				if(i - 2 >= 0){
					if(a[i - 2] == a[i + 1]){
						continue;
					}
				}
				if(x == -1){
					if(i == 1){
						dp[i][0]++;
						dp[i][0] %= md;
					} else {	
						ll hey = f[i - 2];
						hey *= (k - 1);
						hey %= md;
						dp[i][0] += hey + g[i - 2];
						dp[i][0] %= md;
					}
				} else {
					if(a[x] == a[i + 1]){
						ll o = g[i - x - 2];
						o *= dp[x][0];
						o %= md;
						dp[i][0] += o;
						dp[i][0] %= md;
					} else {
						ll o = f[i - x - 2];
						o *= dp[x][0];
						o %= md;
						dp[i][0] += o;
						dp[i][0] %= md;
					}
				}
			}
	
		}
	}
	x = -1;
	if(b[0] == -1){
		dp[0][1] = k - 1;
		if(b[1] <= 0){
			dp[0][1]++;
		}
	} else {
		x = 0;
		dp[0][1] = 1;
	}
	for(int i = 1 ; i < n / 2 ; i++){
		if(b[i] >= 1){
			x = i;
			dp[i][1] = dp[i - 1][1];
			if(b[i] == b[i - 1]){
				cout<<"0\n";
				return 0;
			}
		} else {
			ll z = k - 2;
			if(b[i + 1] <= 0 || b[i + 1] == b[i - 1]){
				z++;
			}
			dp[i][1] = dp[i - 1][1];
			dp[i][1] *= z;
			dp[i][1] %= md;
			if(b[i - 1] != -1){
				continue;
			}
			if(z == k - 2){
				if(i - 2 >= 0){
					if(b[i - 2] == b[i + 1]){
						continue;
					}
				}
				if(x == -1){
					if(i == 1){
						dp[i][1]++;
						dp[i][1] %= md;
					} else {	
						ll hey = f[i - 2];
						hey *= (k - 1);
						hey %= md;
						dp[i][1] += hey + g[i - 2];
						dp[i][1] %= md;
					}
				} else {
					if(b[x] == b[i + 1]){
						ll o = g[i - x - 2];
						o *= dp[x][1];
						o %= md;
						dp[i][1] += o;
						dp[i][1] %= md;
					} else {
						ll o = f[i - x - 2];
						o *= dp[x][1];
						o %= md;
						dp[i][1] += o;
						dp[i][1] %= md;
					}
				}
			}
		}
	}
	ll ans = dp[(n - 1) / 2][0];
	ans *= dp[(n - 2) / 2][1];
	ans %= md;
	cout<<ans<<"\n";
	return 0;
}