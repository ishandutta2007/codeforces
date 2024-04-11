//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int S = 1005;
const int N = 1e6 + 9;
pair<int, int> p[N];
int ans[N];
bool cmp(int x, int y) {
	if ((p[x].first / S) == (p[y].first / S))
		return p[x].second < p[y].second;
	return (p[x].first / S) < (p[y].first / S);
}
int main() {
	int n; scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&p[i].first, &p[i].second);
		ans[i] = i;
	}
	sort(ans, ans + n, cmp);
	for (int i = 0; i < n; ++i)
		printf("%d ", 1 + ans[i]);
	return 0;
}