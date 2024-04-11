#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, s;
int main() {
	cin >> n >> s;
	if (s < 2 * n) return !printf("NO\n");
	printf("YES\n");
	for (int i = 1; i < n; i ++) {
		printf("2 "); s -= 2;
	}
	printf("%d\n", s);
	printf("1\n");
}