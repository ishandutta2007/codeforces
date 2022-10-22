#include<iostream>

typedef long long ll;

using namespace std;

int main(){
	ll dp[11][1001] , n , m;
	for(int i = 1 ; i <= 1000; i++){
		dp[1][i] = i * (i + 1) / 2;
	}
	for(int i = 1 ; i <= 1000 ; i++){
		for(int j = 2 ; j <= 10 ; j++){
			dp[j][i] = 0;
		}
	}
	for(int j = 2 ; j <= 10 ; j++){
		for(int i = 1 ; i <= 1000 ; i++){
			for(int q = 1 ; q <= i ; q++){
				dp[j][i] += dp[j - 1][q] * (i - q + 1);
				dp[j][i] %= 1000000007;
			}
		}
	}
	cin>>n>>m;
	cout<<dp[m][n]<<endl;
	return 0;
}