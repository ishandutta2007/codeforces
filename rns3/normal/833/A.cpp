#include <bits/stdc++.h>
using namespace std;

int n;

map <long long, bool> mp;

int main() {
	long long now = 1;
	for (int i = 1; i <= 1e6; i ++) {
		now = 1ll * i * i * i;
		mp[now] = 1;
	}
	int a, b;
	scanf("%d", &n);
	while (n --) {
		scanf("%d %d", &a, &b);
		int d = __gcd(a, b);
		int aa = a / d;
		int bb = b / d;
		if ((d % aa) || (d % bb)) {
			puts("No");
			continue;
		}
		long long c = 1ll * a * b;
		if (mp[c]) puts("Yes");
		else puts("No");
	}

	return 0;
}