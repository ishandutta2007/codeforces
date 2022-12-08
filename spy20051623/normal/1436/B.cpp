#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
int vis[100005];

void euler() {
	for (int i = 2; i < 100005; ++i) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 100005; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}

void print(int n, int x) {
	for (int i = 0; i < n - 1; ++i) {
		printf("%d", x);
		for (int j = 0; j < n - 1; ++j) printf(" 1");
		putchar('\n');
	}
	putchar('1');
	for (int i = 0; i < n - 1; ++i) printf(" %d", x);
	putchar('\n');
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 4; i < 100000; ++i) {
		if (vis[i]) continue;
		if (vis[1 + (n - 1) * i] && vis[i + n - 1]) {
			print(n, i);
			return;
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	euler();
	memset(vis, 0, sizeof vis);
	for (int i : prime) vis[i] = 1;
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}