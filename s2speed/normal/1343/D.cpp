#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		vector<ll> dp;
		ll n , k , a[100000] , h;
		cin>>n>>k;
		for(int i = 0 ; i <= 2 * k ; i++){
			dp.push_back(0);
		}
		for(int i = 0 ; i < n / 2 ; i++){
			cin>>a[i];
		}
		for(int i = n / 2 - 1 ; i >= 0 ; i--){
			cin>>h;
			dp[min(h , a[i]) + 1]--;
			dp[2]++;
			dp[max(h , a[i]) + k + 1]++;
			a[i] += h;
		}
		for(int i = 3 ; i <= 2 * k ; i++){
			dp[i] += dp[i - 1];
		}
		for(int i = 0 ; i < n / 2 ; i++){
			dp[a[i]]--;
		}
		dp.erase(dp.begin());
		dp.erase(dp.begin());
		sort(dp.begin() , dp.end());
		cout<<dp[0] + n / 2<<endl;
		dp.clear();
	}
	return 0;
}