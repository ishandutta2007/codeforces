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
		char s[n+1];
		scanf("%s", s);
		int answer;
		if(n == 1) {
			answer = 1;
		} else if(n == 2) {
			answer = (s[0]!=s[1]);
		} else {
			answer = 0;
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}