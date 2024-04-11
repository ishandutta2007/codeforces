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
		int answer = 0;
		for(i=1; pow(i, 2)<=n; i++) {
			answer++;
		}
		for(i=1; pow(i, 3)<=n; i++) {
			answer++;
		}
		for(i=1; pow(i, 6)<=n; i++) {
			answer--;
		}
		printf("%d\n", answer);
	}
}