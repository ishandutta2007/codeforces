#include <bits/stdc++.h>
using namespace std;

#define N 111

char s[N];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int cnt = 0;
	for (int i = 0; i < n; i ++) if (s[i] == '8') cnt ++;
	int ans = min(cnt, n / 11);
	printf("%d\n", ans);

	return 0;
}