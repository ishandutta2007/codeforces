#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define MAX_N 1000000
#define INF 1000000

int N, M;
int arr[MAX_N+1];
int ans = 0;
int dp[9][9], dp2[9][9];

int main(){
	scanf("%d%d", &M, &N);
	for(int i=0; i<M; i++){
		int x;
		scanf("%d", &x);	arr[x]++;
	}
	for(int i=1; i<=N; i++){
		if(arr[i]>6){
			ans+=(arr[i]-6)/3;
			arr[i] = 6 + (arr[i]-6)%3;
		}
	}
	if(N<=2){
		printf("%d", ans);
		return 0;
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			dp[i][j] = dp2[i][j] = -INF;
		}
	}
	int cnt = ans;
	int a1 = arr[1], a2 = arr[2];
	int c1, c2;
	while(arr[1]>=0){
		arr[2] = a2;
		c2 = cnt;
		while(arr[2]>=0){
			dp[arr[1]][arr[2]] = max(dp[arr[1]][arr[2]], cnt);
			cnt++;arr[2]-=3;
		}cnt = c2;
		cnt++;arr[1]-=3;
	}
	arr[1] = a1; arr[2] = a2;
	for(int ii=3; ii<=N; ii++){
		int k = arr[ii];
		int t = 0;
		while(k>=0){
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					dp2[j][k] = max(dp2[j][k], dp[i][j]+t);
					if(i>=1 && j>=1 && k>=1)	dp2[j-1][k-1] = max(dp2[j-1][k-1], dp[i][j]+t+1);
					if(i>=2 && j>=2 && k>=2)	dp2[j-2][k-2] = max(dp2[j-2][k-2], dp[i][j]+t+2);
				}
			}
			k-=3;
			t++;
		}
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				dp[i][j] = dp2[i][j];
				dp2[i][j] = -INF;	
			}
		}
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}