#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll a[200000] , l[200000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		vector<ll> dp;
		ll n , k , o = 0;
		cin>>n>>k;
		for(int i = 0 ; i <= n - k ; i++){
			dp.push_back(0);
		}
		cin>>a[0]>>a[1];
		for(int i = 2 ; i < n ; i++){
			cin>>a[i];
			if(a[i - 1] > a[i - 2] && a[i - 1] > a[i]){
				if(i - k + 1 <= n - k){
					dp[max(o , i - k + 1)]++;
				}
				if(i <= n - k + 1){
					dp[i - 1]--;
				}
			}
		}
		l[0] = dp[0];
		for(int i = 1 ; i <= n - k ; i++){
			dp[i] += dp[i - 1];
			l[i] = dp[i];
		}
		sort(dp.begin() , dp.end());
		reverse(dp.begin() , dp.end());
		cout<<dp[0] + 1<<" ";
		for(int i = 0 ; i <= n - k ; i++){
			if(l[i] == dp[0]){
				cout<<i + 1<<endl;
				break;
			}
		}
		dp.clear();
	}
	return 0;
}