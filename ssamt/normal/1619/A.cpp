#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[101];
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		int check = 1;
		if(n%2 == 1) {
			check = 0;
		}
		for(i=0; i<n/2; i++) {
			if(s[i] != s[n/2+i]) {
				check = 0;
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}