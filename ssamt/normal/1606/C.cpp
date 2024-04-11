#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		k++;
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long answer = 0;
		for(i=0; i<n-1; i++) {
			if(pow(10, a[i+1]-a[i])-1 >= k) {
				answer += (long long)pow(10, a[i])*k;
				k = 0;
				break;
			} else {
				answer += (long long)pow(10, a[i+1])-(long long)pow(10, a[i]);
				k -= pow(10, a[i+1]-a[i])-1;
			}
		}
		//printf("%lld %d %lld\n", answer, k, (long long)pow(10, a[n-1])*k);
		answer += (long long)pow(10, a[n-1])*k;
		printf("%lld\n", answer);
	}
}