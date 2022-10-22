#include<iostream>

using namespace std;

int main(){
	int n , dp[100] , counter = 0;
	cin>>n;
	for(int i = 0 ; i < 100 ; i++){
		dp[i] = 0;
	}
	for(int i = 1 ; i < 100 ; i++){
		if(i >= 20){
			dp[i] = dp[i - 20] + 1;
		} else if(i >= 10){
			dp[i] = dp[i - 10] + 1;
		} else if(i >= 5){
			dp[i] = dp[i - 5] + 1;
		} else if(i >= 1){
			dp[i] = dp[i - 1] + 1;
		}
	}
	counter += n / 100;
	counter += dp[n % 100];
	cout<<counter<<endl;
	return 0;
}