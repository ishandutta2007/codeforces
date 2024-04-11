using namespace std;
#include<bits/stdc++.h>
float dp[2001][2001], a[2000], aa, bb, ab;

main() {
	int n, A, B, I=0, i, j, mna, mnb;
	scanf("%d %d %d", &n, &A, &B);
	for(i=0; i<n; i++) scanf("%f", a+i);
	for(; I<n; I++) {
		scanf("%f", &bb);
		aa=a[I], ab=aa+bb-aa*bb;
		for(i=min(A, I), mna=max(0, A-n+I); i>=mna; i--) {
			for(j=min(B, I), mnb=max(0, B-n+I); j>=mnb; j--) {
				if(dp[i][j]+aa>dp[i+1][j]) dp[i+1][j]=dp[i][j]+aa;
				if(dp[i][j]+bb>dp[i][j+1]) dp[i][j+1]=dp[i][j]+bb;
				if(dp[i][j]+ab>dp[i+1][j+1]) dp[i+1][j+1]=dp[i][j]+ab;
			}
		}
	}
	printf("%.4f", dp[A][B]);
}