#include<iostream>

typedef long long int ll;

using namespace std;

int main(){
	ll n , h , a[100000] , dp[100000];
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		a[i] = 0;
		dp[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		a[h - 1] += h;
	}
	dp[0] = a[0];
	dp[1] = max(a[0] , a[1]);
	for(int i = 2 ; i < 1e5 ; i++){
		dp[i] = max(dp[i - 1] , dp[i - 2] + a[i]);
	}
	cout<<dp[99999]<<endl;
}