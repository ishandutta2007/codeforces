#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[200001];
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		int check = 1;
		if(s[0] == 'B' || s[n-1] == 'A') {
			check = 0;
		}
		int h = 0;
		for(i=0; i<n; i++) {
			if(s[i] == 'A') {
				h++;
			} else {
				h--;
			}
			if(h < 0) {
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