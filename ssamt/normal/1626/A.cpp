#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[53];
		scanf("%s", s);
		for(i=0; s[i]; i++);
		sort(s, s+i);
		printf("%s\n", s);
	}
}