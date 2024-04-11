#include <bits/stdc++.h>

using namespace std;

int a[200005];

int calc(int st, int en, int t, int add) {
	if (t == 0) return 0;
	int md = lower_bound(a + st, a + en, t + add) - a;
	int rlt = 10000000;
	if (md == en) rlt = min(rlt, calc(st, md, t / 2, add));
	else if (st == md) rlt = min(rlt, calc(md, en, t / 2, add + t));
	else {
		rlt = min(rlt, calc(st, md, t / 2, add) + en - md - 1);
		rlt = min(rlt, calc(md, en, t / 2, add + t) + md - st - 1);
	}
	return rlt;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cout << calc(0, n, (1 << 29), 0) << endl;

	return 0;

}