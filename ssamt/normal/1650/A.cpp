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
		char s[50];
		scanf("%s", s);
		char c;
		getchar();
		scanf("%c", &c);
		int check = 0;
		for(i=0; s[i]; i++) {
			if(i%2 == 0 && s[i] == c) {
				check = 1;
			}
		}
		printf(check?"YES\n":"NO\n");
	}
}