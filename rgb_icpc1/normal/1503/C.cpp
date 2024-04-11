#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
const int MN = 1000005;
const int M = 998244353;

int a[MN], b[MN], c[MN];
int ans[MN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int bn = 0;
	LL rlt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[bn++] = a[i];
		b[bn++] = a[i] + c[i];
		rlt += c[i];
	}
	sort(b, b + bn);
	bn = unique(b, b + bn) - b;
	for (int i = 1; i <= n; i++) {
		int j;
		j = lower_bound(b, b + bn, a[i]) - b;
		ans[j]++;
		j = lower_bound(b, b + bn, a[i] + c[i]) - b;
		ans[j]--;
	}
	for (int i = 0; i < bn; i++) ans[i + 1] += ans[i];
	for (int i = 0; i < bn - 1; i++) if (ans[i] == 0) {
		rlt += b[i + 1] - b[i];
	}
	cout << rlt << endl;

	return 0;
}