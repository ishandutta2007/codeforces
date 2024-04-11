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
		char s[7];
		scanf("%s", s);
		int check = 1;
		for(i=0; i<6; i++) {
			for(j=i+1; j<6; j++) {
				if(abs(s[i]-s[j]) == 'a'-'A') {
					if(s[i] < s[j]) {
						check = 0;
					}
				}
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}