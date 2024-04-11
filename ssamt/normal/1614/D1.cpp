#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &n);
	int a[n];
	int am = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		am = max(am, a[i]);
	}
	int count[am+1] = {};
	for(i=0; i<n; i++) {
		count[a[i]]++;
	}
	int mult[am+1] = {};
	for(i=1; i<=am; i++) {
		for(j=i; j<=am; j+=i) {
			mult[i] += count[j];
		}
	}
	/*for(i=1; i<=am; i++) {
		printf("%d ", mult[i]);
	}
	printf("\n");*/
	long long answer[am+1] = {};
	answer[1] = n;
	for(i=1; i<=am; i++) {
		for(j=2*i; j<=am; j+=i) {
			answer[j] = max(answer[j], answer[i]+(long long)mult[j]*(j-i));
		}
	}
	long long sum_max = 0;
	for(i=1; i<=am; i++) {
		//printf("%lld ", answer[i]);
		sum_max = max(sum_max, answer[i]);
	}
	//printf("\n");
	printf("%lld\n", sum_max);
}