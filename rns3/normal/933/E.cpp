#include <bits/stdc++.h>
using namespace std;

#define N 303030

int n, p[N];
long long dp[N];

bool bad[N];

vector <int> v;

long long ans;

void doing(int k) {
	int val = min(p[k], p[k+1]);
	if (val) v.push_back(k);
	p[k] -= val, p[k+1] -= val;
	ans += val;
}

void oper(int k, int tag) {
	if (tag == 1) doing(k), doing(k - 1);
	else doing(k), doing(k - 1), doing(k + 1);
}

int tar;

int main() {
	//freopen("r.in", "r", stdin);
	tar = (int)clock();
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
	dp[1] = p[1];
	dp[2] = p[2];
	for (int i = 3; i <= n + 1; i ++) {
		dp[i] = min(dp[i-2] + p[i], dp[i-3] + max(p[i], p[i-1]));
	}
	int k;
	if (dp[n] < dp[n+1]) k = n;
	else k = n + 1;
	bad[k+1] = 1;
	while (k > 2) {
		if (dp[k] == dp[k-2] + p[k]) bad[k-1] = 1, k = k - 2;
		else bad[k-2] = 1, k = k - 3;
	}
	for (int i = 1; i <= n; i ++) {
		if (!bad[i]) {
			int j = i;
			while (!bad[j]) j ++;
			oper(i, j - i);
			i = j;
		}
	}
	while (clock() - tar <= 1900);
	printf("%d\n", (int)v.size());
	for (int i = 0; i < v.size(); i ++) printf("%d\n", v[i]);

	return 0;
}