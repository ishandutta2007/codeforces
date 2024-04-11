#include <bits/stdc++.h>

using namespace std;

int zero(int d, int end) {
	int answer = end/(1<<(d+1))*(1<<d);
	answer += min(end%(1<<(d+1)), 1<<d);
	return answer;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int l, r;
		scanf("%d %d", &l, &r);
		int min_zero = INT_MAX;
		for(i=0; i<20; i++) {
			min_zero = min(min_zero, zero(i, r+1)-zero(i, l));
			//printf("%d %d\n", i, min_zero);
		}
		printf("%d\n", min_zero);
	}
}