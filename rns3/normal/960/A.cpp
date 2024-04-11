#include <bits/stdc++.h>

using namespace std;



char s[101010];



int main() {

	//freopen("r.in", "r", stdin);

	gets(s);

	int n = strlen(s);

	int a = 0;

	while (s[a] == 'a' && a < n) a ++;

	int b = a;

	while (s[b] == 'b' && b < n) b ++;

	int c = b;

	while (s[c] == 'c' && c < n) c ++;

	if (c != n) {

		puts("NO");

		return 0;

	}

	c -= b, b -= a;

	if (!a || !b || !c) {

		puts("NO");

		return 0;

	}

	if (a == c || b == c) {

		puts("YES");

		return 0;

	}

	puts("NO");



	return 0;

}