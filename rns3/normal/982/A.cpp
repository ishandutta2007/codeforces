#include <bits/stdc++.h>

using namespace std;



#define N 1010



char s[N];

int n;



int main() {

	scanf("%d\n", &n);

	gets(s);

	assert(n == strlen(s));

	for (int i = 1; i < n; i ++) if (s[i] == '1' && s[i-1] == '1') {

		puts("No");

		return 0;

	}

	if (n == 1) {

		if (s[0] == '1') puts("Yes");

		else puts("No");

		return 0;

	}

	if (s[0] == '0' && s[1] == '0') {

		puts("No");

		return 0;

	}

	if (s[n-1] == '0' && s[n-2] == '0') {

		puts("No");

		return 0;

	}

	for (int i = 1; i < n - 1; i ++) {

		if (s[i] == '0' && s[i-1] == '0' && s[i+1] == '0') {

			puts("No");

			return 0;

		}

	}

	puts("Yes");



	return 0;

}