#include <bits/stdc++.h>
using namespace std;

#define N 1010101

char s[N];
int a[N];

map <char, int> mp;

char ch[] = "<>{}[]()";

void prep() {
	for (int i = 0; i < 8; i ++) mp[ch[i]] = i;
}

int q[N];

int main() {
	prep();
	gets(s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) a[i] = mp[s[i]];
	int ans = 0;
	int e = 0;
	for (int i = 1, j; i <= n; i ++) {
		if (a[i] & 1) {
			if (!e) {
				puts("Impossible");
				return 0;
			}
			j = q[e--];
			if (a[j] != a[i] - 1) ans ++;
		}
		else q[++e] = i;
	}
	if (e) {
		puts("Impossible");
		return 0;
	}
	printf("%d\n", ans);


	return 0;
}