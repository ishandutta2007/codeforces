#include<iostream>

typedef long long ll;

using namespace std;


int main(){
	ll dp[100001][2] , n , k , a , b;
	cin>>n>>k;
	dp[0][1] = 0;
	for(int i = 1 ; i < k ; i++){
		dp[i][0] = 1;
		dp[i][1] = dp[i - 1][1] + dp[i][0];
	}
	dp[k][0] = 2;
	dp[k][1] = k + 1;
	for(int i = k + 1 ; i < 100001 ; i++){
		dp[i][0] = dp[i - 1][0] + dp[i - k][0];
		dp[i][0] %= 1000000007;
		dp[i][1] = dp[i - 1][1] + dp[i][0];
		dp[i][1] %= 1000000007;
	}
	while(n > 0){
		cin>>a>>b;
		if(dp[b][1] < dp[a - 1][1]){
			cout<<dp[b][1] + 1000000007 - dp[a - 1][1]<<endl;
		} else {
			cout<<dp[b][1] - dp[a - 1][1]<<endl;
		}
		n--;
	}
	return 0;
}