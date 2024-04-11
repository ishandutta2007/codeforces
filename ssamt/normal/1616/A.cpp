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
		int count[101] = {};
		for(i=0; i<n; i++) {
			count[abs(a[i])]++;
		}
		int answer = 0;
		for(i=0; i<101; i++) {
			answer += min(count[i], 2);
		}
		if(count[0] >= 2) {
			answer--;
		}
		printf("%d\n", answer);
	}
}