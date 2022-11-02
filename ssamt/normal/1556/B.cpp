#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n, m;
	int par[2];
	std::vector<int> sum[2];
	long long min_change;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		min_change = INT_MAX;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		par[0] = 0;
		par[1] = 0;
		sum[0].clear();
		sum[1].clear();
		for(i=0; i<n; i++) {
			par[a[i]%2]++;
			sum[a[i]%2].push_back(i);
		}
		if(par[0] == (n-1)/2+1) {
			long long temp = 0;
			for(i=0; i<sum[0].size(); i++) {
				temp += abs(sum[0][i]-2*i);
			}
			min_change = min(min_change, temp);
		}
		if(par[1] == (n-1)/2+1) {
			long long temp = 0;
			for(i=0; i<sum[1].size(); i++) {
				temp += abs(sum[1][i]-2*i);
			}
			min_change = min(min_change, temp);
		}
		if(min_change == INT_MAX) {
			printf("-1\n");
		} else {
			printf("%lld\n", min_change);
		}
	}
}