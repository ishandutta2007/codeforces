#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		for(i=0; i<m; i++) {
			a[i] = a[i+n-m];
		}
		int k[m];
		vector<int> b[m];
		long long sum[m] = {};
		for(i=0; i<m; i++) {
			scanf("%d", &k[i]);
			for(j=0; j<k[i]; j++) {
				scanf("%d", &in);
				b[i].push_back(in);
				sum[i] += in;
			}
		}
		int count[m+1];
		for(i=0; i<m; i++) {
			count[i] = -1;
		}
		count[m] = 0;
		for(i=0; i<m; i++) {
			count[lower_bound(a, a+m, (sum[i]-1)/k[i]+1)-a]++;
		}
		int cumul[m+1];
		cumul[m] = count[m];
		for(i=m-1; i>=0; i--) {
			cumul[i] = cumul[i+1]+count[i];
		}
		int large = 0;
		int zero[m+2] = {}, one[m+2] = {};
		for(i=0; i<=m; i++) {
			if(cumul[i] > 1) {
				large = 1;
			}
			zero[i+1] = zero[i]+(cumul[i]==0);
			one[i+1] = one[i]+(cumul[i]==1);
		}
		for(i=0; i<m; i++) {
			for(j=0; j<k[i]; j++) {
				int answer;
				int idx = lower_bound(a, a+m, (sum[i]-1)/k[i]+1)-a;
				int idx2 = lower_bound(a, a+m, (sum[i]-b[i][j]-1)/(k[i]-1)+1)-a;
				if(large) {
					answer = 0;
				} else {
					if(idx < idx2) {
						if(one[m+1]) {
							answer = 0;
						} else {
							if(zero[idx2+1]-zero[idx+1] > 0) {
								answer = 0;
							} else {
								answer = 1;
							}
						}
					} else {
						if(one[m+1] == one[idx+1]-one[idx2+1]) {
							answer = 1;
						} else {
							answer = 0;
						}
					}
				}
				printf("%d", answer);
			}
		}
		printf("\n");
	}
}