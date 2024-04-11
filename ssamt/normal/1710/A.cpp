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
		scanf("%d %d %d", &n, &m, &k);
		int a[k];
		for(i=0; i<k; i++) {
			scanf("%d", &a[i]);
		}
		long long sum1 = 0;
		for(i=0; i<k; i++) {
			if(a[i]/n >= 2) {
				sum1 += a[i]/n;
			}
		}
		int check1 = (sum1 >= m);
		int except1 = 1;
		for(i=0; i<k; i++) {
			if(a[i]/n > 2) {
				except1 = 0;
			}
		}
		if(m%2 == 0) {
			except1 = 0;
		}
		long long sum2 = 0;
		for(i=0; i<k; i++) {
			if(a[i]/m >= 2) {
				sum2 += a[i]/m;
			}
		}
		int check2 = (sum2 >= n);
		int except2 = 1;
		for(i=0; i<k; i++) {
			if(a[i]/m > 2) {
				except2 = 0;
			}
		}
		if(n%2 == 0) {
			except2 = 0;
		}
		if((check1 && !except1) || (check2 && !except2)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}