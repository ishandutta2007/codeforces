#include <bits/stdc++.h>
using namespace std;
const int N = 8002;
int k,q;
double dp[8005][1005];
int main() {
	cin>>k>>q;
	dp[0][0]=2000;
	for(int i=0;i<N;i++){
		for(int j=0;j<=min(i,k);j++){
			double p1 = 1.0 * j / k; 
			dp[i+1][j] += p1*dp[i][j];
			dp[i+1][j+1] += (1-p1)*dp[i][j];
		}
	}
	//printf("%.5f\n", dp[8000][k]);
	while(q--){
		int x; cin>>x;
		for(int i=0;i<=8000;i++){
			if(dp[i][k]>=x) {
				printf("%d\n", i); break;
			}
		}
	}
}