#include <bits/stdc++.h>
using namespace std;

int n;
char s[105];

int main() {
    scanf("%d %s", &n, s);
    int ans = 0;
    for (int i = 0; i < n - 1; i ++) {
        if (s[i] != s[i+1]) ans ++, i ++;
    }
    printf("%d\n", n - ans);
	return 0;
}