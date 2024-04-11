#include <bits/stdc++.h>
using namespace std;

char s[505];

int n, f[255];

int main() {
	gets(s);
	n = strlen(s);
	for (char c = 'a'; c <= 'z'; c ++) f[c] = n;
	for (int i = 0; i < n; i ++) {
		f[s[i]] = min(f[s[i]], i);
	}
	for (char c = 'a'; c < 'z'; c ++) {
		if (f[c] > f[c+1]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");


	return 0;
}