#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[10];
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		int even = 0;
		for(i=0; i<n; i++) {
			if((s[i]-'0')%2 == 0) {
				even = 1;
			}
		}
		if((s[n-1]-'0')%2 == 0) {
			printf("0\n");
		} else if((s[0]-'0')%2 == 0) {
			printf("1\n");
		} else if(even) {
			printf("2\n");
		} else {
			printf("-1\n");
		}
	}
}