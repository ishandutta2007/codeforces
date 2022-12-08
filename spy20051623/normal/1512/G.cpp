#include <bits/stdc++.h>

using namespace std;

long long s[10000005];
int p[10000005];

int main() {
//	freopen("in.txt", "r", stdin);
	for (int i = 1; i <= 10000000; ++i) {
		for (int j = i; j <= 10000000; j += i) {
			s[j] += i;
		}
	}
	for (int i = 1; i <= 10000000; ++i) {
		if (s[i] <= 10000000 && p[s[i]] == 0)
			p[s[i]] = i;
	}
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (p[n] == 0)
			printf("-1\n");
		else
			printf("%d\n", p[n]);
	}
	return 0;
}