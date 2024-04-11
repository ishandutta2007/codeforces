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
		scanf("%d", &n);
		if(n < 100) {
			printf("%d\n", n%10);
		} else {
			int answer = INT_MAX;
			while(n > 0) {
				answer = min(answer, n%10);
				n /= 10;
			}
			printf("%d\n", answer);
		}
	}
}