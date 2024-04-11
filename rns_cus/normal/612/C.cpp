#include <bits/stdc++.h>
using namespace std;

const char op[] = "{}<>()[]";

char inv(char c) {
	return op[(strchr(op, c) - op) ^ 1];
}

char s[1001001];
int type[1001001], ans, p[1001001], np;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i ++) {
		if (s[i] == '<' || s[i] == '(' || s[i] == '{' || s[i] == '[') type[i] = 1;
		else type[i] = 2;
	}
	int sum = 0;
	for (int i = 1; i <= len; i ++) {
		if (type[i] == 1) sum ++;
		else sum --;
		if (sum < 0) {
			puts("Impossible"); return 0;
		}
	}
	if (sum) {
		puts("Impossible"); return 0;
	}
	for (int i = 1; i <= len; i ++) {
		if (type[i] == 1) p[++np] = s[i];
		else {
			if (p[np] != inv(s[i])) ans ++;
			np --;
		}
	}
	printf("%d\n", ans);
	return 0;
}