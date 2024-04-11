#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[51];
		scanf("%s", s);
		int count = 0;
		for(i=0; s[i]; i++) {
			if(s[i] == 'N') {
				count++;
			}
		}
		if(count == 1) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}