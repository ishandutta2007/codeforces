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
		int a, b;
		scanf("%d %d", &a, &b);
		int answer;
		for(i=0; ; i++) {
			if(((a+i)|b) == b) {
				break;
			}
		}
		if(a+i == b) {
			answer = i;
		} else {
			answer = i+1;
		}
		for(i=0; ; i++) {
			if((a|(b+i)) == (b+i)) {
				break;
			}
		}
		answer = min(answer, i+1);
		printf("%d\n", answer);
	}
}