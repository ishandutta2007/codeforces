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

int ask(int k, int x) {
	printf("%c %d\n", 'A' + k - 1, x);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int a[100005];

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	euler();
	int n;
	scanf("%d", &n);
	vector<int> v;
	int cnt = 0, h = 0, f = 0;
	for (int i: prime) {
		if (i > n) break;
		++cnt;
		int x = ask(2, i);
		int y = 0;
		for (int j = i; j <= n; j += i) {
			if (!a[j]) ++y, a[j] = 1;
		}
		if (x != y) v.push_back(i);
		if (!f && cnt == 100) {
			int xx = ask(1, 1);
			int yy = 0;
			for (int j = 1; j <= n; ++j) {
				if (!a[j]) ++yy;
			}
			if (xx != yy) f = 1;
			else ++h, cnt = 0;
		}
	}
	for (int i = 100 * h; i < prime.size() && prime[i] <= n && i < 100 * (h + 1); ++i) {
		int x = ask(1, prime[i]);
		if (x) {
			v.push_back(prime[i]);
			break;
		}
	}
	int ans = 1;
	for (int i: v) {
		long long p = i;
		while (p * i <= n && ask(1, p * i)) p *= i;
		ans *= p;
	}
	printf("C %d\n", ans);
	fflush(stdout);
	return 0;
}