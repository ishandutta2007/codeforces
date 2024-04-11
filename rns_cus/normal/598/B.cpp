#include <bits/stdc++.h>
using namespace std;
#define N 100100

char s[N], t[N];

int q, l, r, k;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%s", s + 1);
	scanf("%d", &q);
	while (q --) {
		scanf("%d %d %d", &l, &r, &k);
		int len = 0;
		for (int i = l; i <= r; i ++) t[len++] = s[i];
		for (int i = 0; i < len; i ++) s[l+(i+k)%len] = t[i];
	}
	puts(s + 1);
	return 0;
}