#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long x, n;
		long long answer;
		scanf("%lld %lld", &x, &n);
		if(x%2 == 0) {
			if(n%4 == 0) {
				answer = x;
			} else if(n%4 == 1) {
				answer = x-n;
			} else if(n%4 == 2) {
				answer = x+1;
			} else {
				answer = x+n+1;
			}
		} else {
			if(n%4 == 0) {
				answer = x;
			} else if(n%4 == 1) {
				answer = x+n;
			} else if(n%4 == 2) {
				answer = x-1;
			} else {
				answer = x-n-1;
			}
		}
		printf("%lld\n", answer);
	}
}