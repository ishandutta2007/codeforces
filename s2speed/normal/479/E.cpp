#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll md = 1e9 + 7;

vector<ll> dp , pd;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , a , b , k , s = 1;
	cin>>n>>a>>b>>k; a--; b--;
	if(a > b){
		a = n - a - 1;
		b = n - b - 1;
	}
	dp.assign(b , 0);
	pd.resize(b);
	dp[a] = 1;
	if(a == b - 1){
		cout<<0<<"\n";
		return 0;
	}
	for(int i = 0 ; i < k ; i++){
		pd[b - 1] = s;
		pd[b - 2] = s - dp[b - 2] + md;
		pd[b - 2] %= md;
		s = pd[b - 2];
		int x = b - 2;
		for(int j = b - 3 ; j >= 0 ; j--){
			pd[j] = pd[j + 1] - dp[j] + dp[j + 1];
			if(b - x == x - j){
				pd[j] -= dp[x];
				x--;
			}
			pd[j] += md * 3;
			pd[j] %= md;
			s += pd[j];
			s %= md;
		}
		for(int i = 0 ; i < b ; i++){
			swap(dp[i] , pd[i]);
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < b ; i++){
		ans += dp[i];
		ans %= md;
	}
	cout<<ans<<"\n";
	return 0;
}