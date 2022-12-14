#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, nxt[N], prv[N];
char s[N];

int main() {
	gets(s + 1);
	n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}
    int cnt = n;
    for (int i = 1; i < n; i = nxt[i]) {
		while (nxt[i] <= n && s[i] == s[nxt[i]]) {
			cnt -= 2;
			nxt[prv[i]] = nxt[nxt[i]];
            prv[nxt[nxt[i]]] = prv[i];
            i = prv[i];
		}
    }
    if (cnt == 0) puts("YES");
    else puts("NO");
	return 0;
}