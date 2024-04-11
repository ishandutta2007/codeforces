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
		int c;
		scanf("%d %d", &n, &c);
		vector<int> e(c+1, 0);
		int answer = 1;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			e[in] = 1;
		}
		vector<int> sum(c+2, 0);
		for(i=1; i<=c+1; i++) {
			sum[i] = sum[i-1]+e[i-1];
		}
		for(i=1; i<=c; i++) {
			if(!e[i]) {
				for(j=1; i*j<=c; j++) {
					if(e[j]) {
						if(sum[min((i+1)*j, c+1)]-sum[i*j] > 0) {
							answer = 0;
						}
					}
				}
			}
		}
		printf(answer?"Yes\n":"No\n");
	}
}