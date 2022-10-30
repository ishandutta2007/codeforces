#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	int go[1001];
	go[1] = 0;
	for(i=2; i<=1000; i++) {
		go[i] = INT_MAX;
	}
	for(i=1; i<=1000; i++) {
		for(j=1; j<=i; j++) {
			int idx = i+i/j;
			if(idx <= 1000) {
				go[idx] = min(go[idx], go[i]+1);
			}
		}
	}
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		int b[n], c[n];
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &c[i]);
		}
		int total = 0;
		for(i=0; i<n; i++) {
			total += go[b[i]];
		}
		int answer;
		if(k >= total) {
			answer = 0;
			for(i=0; i<n; i++) {
				answer += c[i];
			}
		} else {
			int d[n+1][k+1] = {};
			for(i=0; i<n; i++) {
				for(j=0; j<=k; j++) {
					d[i+1][j] = d[i][j];
					if(go[b[i]] <= j) {
						d[i+1][j] = max(d[i+1][j], d[i][j-go[b[i]]]+c[i]);
					}
				}
			}
			answer = d[n][k];
		}
		printf("%d\n", answer);
	}
}