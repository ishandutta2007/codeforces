#include <bits/stdc++.h>

using namespace std;

char s[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%s", s);
	int n = strlen(s);
	printf("3\n");
	printf("L %d\n", n - 1);
	printf("R %d\n", n - 1);
	printf("R %d\n", n + n - 1);
	return 0;
}