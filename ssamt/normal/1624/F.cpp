#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &n);
	int start = 1, end = n+1;
	while(start+1 < end) {
		int mid = (start+end)/2;
		int c = n-mid%n;
		if(c == n) {
			in++;
		} else {
			printf("+ %d\n", c);
			fflush(stdout);
			scanf("%d", &in);
		}
		if(in == mid/n+1) {
			start = mid;
		} else {
			end = mid;
		}
		start += c;
		end += c;
	}
	printf("! %d\n", start);
	fflush(stdout);
}