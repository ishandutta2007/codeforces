#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int n, v[N], buc[N], mx;
pair<int, int> t[N];
vector<pair<int, int>> a, b;

int main() {
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", v + i), t[v[i]].second = i;
	for (int i = n; i; --i) t[v[i]].first = i;
	int tot = 0;
	for (int i = 1; i <= 200000; ++i)
		if (t[i].first) a.push_back(t[i]);
	sort(a.begin(), a.end());
	b.push_back(a[0]);
	for (int i = 1; i < (int)a.size(); ++i)
		if (a[i].second > b.back().second)
			b.push_back(a[i]);
	int ans = 0;
	for (int i = 0, j; i < (int)b.size(); i = j) {
		for (j = i + 1; j < (int)b.size() && b[j].first <= b[j - 1].second; ++j);
		mx = 0;
		for (int k = b[i].first; k <= b[j - 1].second; ++k)
			mx = max(mx, ++buc[v[k]]);
		ans += b[j - 1].second - b[i].first + 1 - mx;
		for (int k = b[i].first; k <= b[j - 1].second; ++k)
			--buc[v[k]];
	}
	printf("%d\n", ans);
	return 0;
}