#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &n);
	int start = 0, end = n*2001-1;
	while(start+1 < end) {
		int mid = (start+end)/2;
		printf("? %d\n", mid);
		fflush(stdout);
		scanf("%d", &in);
		if(in == 1) {
			end = mid;
		} else {
			start = mid;
		}
	}
	int answer = end;
	for(i=2; i<=n; i++) {
		printf("? %d\n", (answer-1)/i);
		fflush(stdout);
		scanf("%d", &in);
		if(in == 0) {
			break;
		}
		if(in <= i) {
			answer = (answer-1)/i*in;
		}
	}
	printf("! %d\n", answer);
	fflush(stdout);
}