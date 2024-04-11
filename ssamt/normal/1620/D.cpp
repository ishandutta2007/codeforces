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
		sort(a, a+n);
		int count[3] = {};
		for(i=0; i<n; i++) {
			count[a[i]%3]++;
		}
		int min1 = 0;
		for(i=0; i<n; i++) {
			if(a[i] == a[n-1]-1) {
				min1++;
			}
		}
		int answer = a[n-1]/3;
		if(a[n-1]%3 == 0) {
			if(count[1] == 0 && count[2] == 0) {
				answer += 0;
			} else {
				answer += 1;
			}
		} else if(a[n-1]%3 == 1) {
			if(count[2] == 0) {
				answer += 1;
			} else if(a[0] != 1 && !min1) {
				answer += 1;
			} else {
				answer += 2;
			}
		} else {
			if(count[1] == 0) {
				answer += 1;
			} else {
				answer += 2;
			}
		}
		printf("%d\n", answer);
	}
}