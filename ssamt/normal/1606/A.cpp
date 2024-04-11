#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[1001];
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		if(s[0] != s[n-1]) {
			s[0] = s[n-1];
		}
		printf("%s\n", s);
	}
}