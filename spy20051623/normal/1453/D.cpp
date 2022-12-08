#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long k;
	scanf("%lld", &k);
	if (k % 2) {
		printf("-1\n");
		return;
	}
	k -= 2;
	vector<int> v;
	for (int i = 61; i > 0; --i) {
		while (k >= (1LL << (i + 1)) - 2) {
			v.push_back(i);
			k -= (1LL << (i + 1)) - 2;
		}
	}
	int sum = 1;
	for (int i : v) {
		sum += i;
	}
	printf("%d\n", sum);
	printf("1 ");
	for (int i : v) {
		for (int j = 0; j < i - 1; ++j) {
			printf("0 ");
		}
		printf("1 ");
	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}