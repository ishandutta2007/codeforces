#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
		}
		int left[n][n];
		for(i=0; i<n; i++) {
			left[i][0] = 0;
			for(j=1; j<n; j++) {
				left[i][j] = left[i][j-1];
				if(a[j-1] < i) {
					left[i][j]++;
				}
				//printf("%d ", left[i][j]);
			}
			//printf("\n");
		}
		int right[n][n];
		for(i=0; i<n; i++) {
			right[i][n-1] = 0;
			for(j=n-2; j>=0; j--) {
				right[i][j] = right[i][j+1];
				if(a[j+1] < i) {
					right[i][j]++;
				}
			}
		}
		long long answer = 0;
		for(i=1; i<n-1; i++) {
			for(j=i+1; j<n-1; j++) {
				//printf("%d %d %d %d\n", i, j, left[a[j]][i], right[a[i]][j]);
				answer += left[a[j]][i]*right[a[i]][j];
			}
		}
		printf("%lld\n", answer);
	}
}