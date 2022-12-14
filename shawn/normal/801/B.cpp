#include <bits/stdc++.h>

using namespace std;

char x[110], y[110];
int n;

int main() {
	scanf("%s%s", x, y);
	n = strlen(x);
	for (int i = 0; i < n; i ++) if (y[i] > x[i]) return puts("-1"), 0;
	printf("%s", y);
	return 0;
}