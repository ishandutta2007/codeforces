#include <bits/stdc++.h>
using namespace std;
const int N=502;
int n,m,a[N][N],dp[N][N];
int main() {
	int k; cin >> k;
	n=2,m=3;
	int pw=1;
	while(pw<=k) pw*=2;
	printf("2 3\n");
	printf("%d %d %d\n", pw+k, k, 0);
	printf("%d %d %d\n", pw, pw+k, k);
}