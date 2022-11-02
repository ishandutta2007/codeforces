#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int m = *max_element(a.begin(), a.end());
		long long answer = LLONG_MAX;
		for(int j=m; j<=m+1; j++) {
			long long odd = 0, sum = 0;
			for(i=0; i<n; i++) {
				if((j-a[i])%2 == 1) {
					odd++;
				}
				sum += j-a[i];
			}
			long long go;
			if(sum%3 == 0) {
				go = sum/3*2;
			} else if(sum%3 == 1) {
				go = sum/3*2+1;
			} else {
				go = sum/3*2+2;
			}
			answer = min(answer, max(2*odd-1, go));
		}
		printf("%lld\n", answer);
	}
}