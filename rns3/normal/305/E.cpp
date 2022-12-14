#include <bits/stdc++.h>
using namespace std;

#define N 5050

bool vis[20], tag[N];

int n, a[N];
char s[N];

void prep() {
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	a[4] = 0;
	for (int k = 5; k < N; k ++) {
		memset(vis, 0, sizeof vis);
		vis[a[k-2]] = 1;
		for (int i = 0; i < k - 2; i ++) {
			vis[a[i]^a[k-i-3]] = 1;
		}
		int now = 0;
		while (vis[now]) now ++;
		a[k] = now;
	}
}

int main() {
	prep();
	gets(s + 1);
	n = strlen(s + 1);
	for (int i = 2; i < n; i ++) if (s[i-1] == s[i+1]) tag[i] = 1;
	for (int j = 2; j < n; j ++) if (tag[j]) {
        int rlt = 0;
		for (int i = 2; i < j - 1; i ++) if (tag[i]) {
			int cnt = 0;
			while (tag[i] && i < j - 1)	cnt ++, i ++;
			rlt ^= a[cnt];
		}
		for (int i = j + 2; i < n; i ++) if (tag[i]) {
			int cnt = 0;
			while (tag[i] && i < n) cnt ++, i ++;
			rlt ^= a[cnt];
		}
		if (!rlt) {
			printf("First\n%d", j);
			return 0;
		}
	}
	puts("Second");
	return 0;
}