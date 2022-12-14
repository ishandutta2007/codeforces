//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 9;
pii p[N];
int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &p[i].first, &p[i].second);
	sort(p, p + n);
	int ed = 0;
	long long ans = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		while (ed != n && p[ed].first - p[i].first < d)
			cur += p[ed++].second;
		ans = max(ans, cur);
		cur -= p[i].second;
	}
	cout << ans << endl;
	return 0;
}