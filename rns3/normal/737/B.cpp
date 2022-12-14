#include <bits/stdc++.h>
using namespace std;

#define N 200020

int n, a, b, k;
int ans[N], e = 0;

char s[N];

int main() {
	scanf("%d %d %d %d\n", &n, &a, &b, &k);
	gets(s + 1);
	s[0] = '1';
	int cnt;
	for (int i = 0; i <= n; i ++) {
		if (s[i] == '1') cnt = 0;
		else {
			cnt ++;
			if (cnt == b) ans[++e] = i, cnt = 0;
		}
	}
	cnt = e - a + 1;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++) printf("%d ", ans[i]);
	return 0;
}