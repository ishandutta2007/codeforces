//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 5005, inf = 0x3f3f3f3f;

int n, a[N];
int dp[N][N][2];

void initDP() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : inf);
		}
	}
}
void updDP(int &a, int b) {a = min(a, b);}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	initDP(); 
	for(int j=1;j<=n;j++) {
		for(int i=j;i>=1;i--) {
			for(int bit=0;bit<=1;bit++) {
				int col = bit ? a[j] : a[i];
				if(i > 1) updDP(dp[i-1][j][0], dp[i][j][bit] + (col != a[i-1]));
				if(j < n) updDP(dp[i][j+1][1], dp[i][j][bit] + (col != a[j+1]));
			}
		}
	}
	printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
	return 0;
}