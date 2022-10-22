#include<cstdio>
#include<iostream>
using namespace std;

const int INF = 1000000000;

int num[2005];
int dp[2005][2005];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	int n;
	scanf("%d", &n);
	int numOfOne = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		numOfOne += (num[i] == 1);
	}
	if(numOfOne > 0) return !printf("%d", n - numOfOne);
	for(int i = 0; i < n; i++) dp[i][i] = num[i];
	int minlen = INF;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			dp[i][j] = gcd(dp[i][j-1], num[j]);
			if(dp[i][j] == 1) minlen = min(minlen, j - i);
		}
	}
	if(minlen == INF) printf("-1");
	else printf("%d", minlen + n - 1);
	
	
}