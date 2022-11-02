#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, p;
long long m, ans;
char s[N][N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i]);
	for (int i = n; i >= 1; i --) {
        if (strcmp(s[i], "half") == 0) m = m * 2;
        else m = m * 2 + 1, ans -= p / 2;
	}
	printf("%I64d\n", m * p + ans);
	return 0;
}