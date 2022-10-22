#include<iostream>

using namespace std;

typedef long long ll;

int main(){
	ll dp[100] , n;
	cin>>n;
	dp[0] = 1;
	for(int i = 1 ; i < n ; i++){
		dp[i] = dp[i - 1] + 4 * i;
	}
	cout<<dp[n - 1]<<endl;
	return 0;
}