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
		char s[n+1];
		scanf("%s", s);
		for(i=1; i<n; i++) {
			if(i == 1 && s[i-1] <= s[i]) {
				break;
			}
			if(i != 1 && s[i-1] < s[i]) {
				break;
			}
		}
		int pos = i;
		for(i=0; i<pos; i++) {
			printf("%c", s[i]);
		}
		for(i=pos-1; i>=0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
}