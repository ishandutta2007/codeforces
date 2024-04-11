#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long answer = 0;
		int one = 0;
		int odd = 0;
		int large = 0;
		for(i=1; i<n-1; i++) {
			if(a[i] == 0) {
				;
			} else if(a[i] == 1) {
				one++;
			} else {
				large++;
				answer += a[i]/2;
			}
			if(a[i]%2 == 1) {
				odd++;
			}
		}
		if(odd != 0) {
			if(large > 0) {
				if(large == 1 && one == 0) {
					answer = -1;
				} else {
					answer += odd;
				}
			} else {
				if(one != 0) {
					answer = -1;
				}
			}
		}
		printf("%lld\n", answer);
	}
}