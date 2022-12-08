#include <bits/stdc++.h>

using namespace std;

bool p_vis[100005];
vector<int> prime;

void eratosthenes() {
	const int maxn = 100005;
	for (int i = 2; i < maxn; ++i) {
		if (p_vis[i])
			continue;
		prime.push_back(i);
		for (int j = i; j < maxn; j += i) {
			p_vis[j] = true;
		}
	}
}

void solve() {
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	int ans = 0;
	if (k == 1 && ((a % b && b % a) || a == b)) {
		printf("NO\n");
		return;
	}
	for (int i : prime) {
		while (a % i == 0) {
			a /= i;
			++ans;
		}
		if (i > a)
			break;
	}
	if (a > 1)
		++ans;
	for (int i : prime) {
		while (b % i == 0) {
			b /= i;
			++ans;
		}
		if (i > b)
			break;
	}
	if (b > 1)
		++ans;
	if (k > ans) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	eratosthenes();
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}