#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int N = 1e6 + 7;

int n, c, d, suf[N];
vector<pair<int, int> > coins, dia;

int fuck(vector<pair<int, int> > a, int tot) {
	sort(a.begin(), a.end());
	if (a.size() < 2) return 0;
	int l = 0;
	suf[0] = a[0].second;
	for (int i = 1; i < a.size(); i++) {
		suf[i] = max(a[i].second, suf[i - 1]);
	}
	int ret = 0;
	for (int i = a.size() - 1; i > 0; i--) {
		while (l < a.size() && a[l].first + a[i].first <= tot) {
			l++;
		}
		if (l > 0 && a[i].first + a[min(l - 1, i - 1)].first <= tot)
			ret = max(ret, a[i].second + suf[min(l - 1, i - 1)]);
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &c, &d);
	int ma = -INF, mb = -INF;
	for (int i = 0; i < n; i++) {
		int b, cost;
		char s[10];
		scanf("%d %d %s", &b, &cost, s);
		if (s[0] == 'C') {
			coins.push_back({cost, b});
			if (cost <= c) {
				ma = max(ma, b);
			}
		} else {
			dia.push_back({cost, b});
			if (cost <= d) {
				mb = max(mb, b);
			}
		}
	}
	int ans = max(0, ma + mb);
	ans = max(ans, fuck(coins, c));
	ans = max(ans, fuck(dia, d));
	cout << ans << endl;
	return 0;
}