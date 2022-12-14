#include <bits/stdc++.h>
using namespace std;

int n;

char s[100];

int main() {

	scanf("%d\n", &n);
	gets(s);
	for (int i = 1; i <= n; i ++) gets(s);
	if (n & 1) puts("contest");
	else puts("home");
	return 0;
}