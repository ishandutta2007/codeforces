#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 310;
char buf[MAXN];

int strlen(char *c) {
	int x = 0;
	while (c[x] != '\0') x++;
	return x;
}

int main() {
	scanf("%s", buf);
	int N = strlen(buf);
	int low = 0;
	int high = 0;
	int cur = 0;
	for(int i = 0; i < N; ++i) {
		if (buf[i] == '+') {
			cur++;
		} else {
			cur--;
		}
		low = min(low, cur);
		high = max(high, cur);
	}
	printf("%d\n", high - low);
	return 0;
}