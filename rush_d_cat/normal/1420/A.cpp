#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		bool ok = 1;
		for (int i = 1; i < n; i ++)
			if (a[i] <= a[i+1])
				ok = 0;
		printf("%s\n", ok ? "NO" : "YES");
	}
}