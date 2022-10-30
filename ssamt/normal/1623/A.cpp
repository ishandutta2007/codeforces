#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int b[2], d[2];
		scanf("%d %d %d %d %d %d", &n, &m, &b[0], &b[1], &d[0], &d[1]);
		int answer = INT_MAX;
		for(i=0; i<2; i++) {
			if(d[i] >= b[i]) {
				answer = min(answer, d[i]-b[i]);
			} else {
				answer = min(answer, 2*(i?m:n)-d[i]-b[i]);
			}
		}
		printf("%d\n", answer);
	}
}